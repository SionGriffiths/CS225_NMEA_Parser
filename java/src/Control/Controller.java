package Control;

import GPSUtils.FixType;
import GPSUtils.GPSposition;
import GPSUtils.GPXmaker;
import Sentences.*;

import java.util.ArrayList;
import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:14
 *
 * The Controller class deefines the main logical steps for the NMEA parsing project.
 * It facilitates the creation of all other classes and funcitons as the main point of entry to the system.
 */
public class Controller {

  /**
   * Stream instances to hold stream data
   */
  private final Stream s1;
  private final Stream s2;
  /**
   * Arraylist to hold corrected gps positions
   */
  private final ArrayList<GPSposition> gps;
  /**
   * Calendar instance to hold time of last corrected gps fix
   */
  private Calendar lastFixTime;

  /**
   * Constructs a Controller.
   * Initialises 2 stream instances with stream datafiles.
   */
  public Controller(){
    s1 = new Stream("dataFiles/gps_1.dat");
    s2 = new Stream("dataFiles/gps_2.dat");
    gps = new ArrayList<GPSposition>();
  }

  /**
   * Method to run the NMEA parser. Entry point of the system.
   */
  public void run(){
    while(!(s1.isEndOfStream())){
      syncStream(s1,s2);
    }
    System.out.println("Streams parsed.");
    System.out.println("gps fixes : " + gps.size());
    for(GPSposition g : gps){
      System.out.println(g.toString());
    }
    makeGPX("dataFiles/output.gpx");
  }

  /**
   * Parses a line in a stream file that corresponds to an NMEA sentence.
   * Splits the sentence and creates a new sentence type object corresponding
   * the the sentence being parsed.
   * @param stream the stream currently being parsed
   */
  public void parseSentence(Stream stream){
    String input;
    if((input=stream.getNext()) != null){
      String[] parts = input.split("[,*]");
      stream.count++;
      String type = parts[0];


      switch(type){
        case "$GPGSA" :
          new GSA(parts, stream);
          break;

        case "$GPGGA" :
          new GGA(parts, stream);

          break;

        case "$GPRMC" :
          new RMC(parts, stream);

          break;

        case "$GPGSV" :
          new GSV(parts, stream);
          break;

        case "$GPZDA" :
          new ZDA(parts, stream);
          break;

        case "$GPGBS" :
          new GBS(parts, stream);
          break;

        default:
          System.err.println("Unrecognised sentence : " + input);
      }
    }
  }


  /**
   * Synchronises the input from 2 streams depending on their timestamps
   * calls parseSentence() on earliest stream to advance it
   * or both if synced.
   * @param stream1 first Stream
   * @param stream2 second Stream
   */
  private void syncStream(Stream stream1, Stream stream2){
    boolean synced = false;

    while(!synced){
      checkForNewFix();
      if(stream1.getStreamTime().compareTo(stream2.getStreamTime()) < 0){
        parseSentence(stream1);
        synced = false;
      }else if (stream1.getStreamTime().compareTo(stream2.getStreamTime()) > 0){
        parseSentence(stream2);
        synced = false;
      }else{
        synced = true;
        calculateOffset(stream1, stream2);
        parseSentence(stream1);
        parseSentence(stream2);

      }
    }
  }

  /**
   * Checks streams for fix availability based on current
   * stream quality. Makes a new corrected GPS fix if
   * quality is sufficient favouring stream 1
   */
  private void checkForNewFix(){
    if(s1.getFixtype()== FixType.GOOD_FIX){
      makeGPSfix(s1);

    }else if(s2.getFixtype()== FixType.GOOD_FIX){
      makeGPSfix(s2);

    }else{
      if(s1.getFixtype()== FixType.MIN_FIX){
        makeGPSfix(s1);

      }else if(s2.getFixtype()== FixType.MIN_FIX){
        makeGPSfix(s2);

      }
    }
  }

  /**
   * Creates a corrected gps fix if 1 second has passed since the last corrected fix from
   * current data in the parameter Stream.
   *
   * @param stream the stream
   */
  private void makeGPSfix(Stream stream){
    if((lastFixTime == null) || (stream.getStreamTime().compareTo(lastFixTime) > 0)){
      gps.add(stream.makeGPS());
      updateFixTime(stream);

    }
  }

  /**
   * Updates the time of last corrected fix with time from the
   * stream which generated the fix.
   * @param stream the stream
   */
  private void updateFixTime(Stream stream){
    lastFixTime = (Calendar)stream.getStreamTime().clone();
  }

  /**
   * Calculates and applies an offset for for values in stream 2
   * @param stream1 the first stream
   * @param stream2 the second stream
   */
  private void calculateOffset(Stream stream1, Stream stream2){
    float latOffset = stream1.getCurrentLat() - stream2.getCurrentLat();
    float lngOffset = stream1.getCurrentLng() - stream2.getCurrentLng();
    float elevOffset = stream1.getCurrentElev() - stream2.getCurrentElev();

    stream2.updateLatLongOffest(latOffset, lngOffset);
    stream2.updateElevOffset(elevOffset);
  }


  /**
   * Creates a GPX file for corrected gps stream output
   * @param filename the filename
   */
  private void makeGPX(String filename){
     new GPXmaker(gps, filename);
  }



}
