package Control;

import GPSUtils.GPSposition;
import Sentences.*;

import java.util.ArrayList;
import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:14
 */
public class Controller {

  private Stream s1;
  private Stream s2;
  private ArrayList<GPSposition> gps;
  private Calendar lastFixTime;

  private boolean fixAvailable;

  private int s1count =0;
  private int s2count = 0;

  public Controller(){
    s1 = new Stream("dataFiles/gps_1.dat");
    s2 = new Stream("dataFiles/gps_2.dat");
    gps = new ArrayList<GPSposition>();
  }

  public void run(){
    while(!(s1.isEndOfStream())){
      syncStream(s1,s2);
    }
    System.out.println("S1 : " + s1count + " | S2 : " + s2count);
    System.out.println("gps fixes : " + gps.size());
    for(GPSposition g : gps){
      System.out.println(g.toString());
    }
  }

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

  private void checkForNewFix(){
    if(s1.isGoodFix()){
      if((lastFixTime == null) || (s1.getStreamTime().compareTo(lastFixTime) > 0)){
        gps.add(s1.makeGPS());
        updateFixTime(s1);
        s1count++;

      }
    }else if(s2.isGoodFix()){
      if((lastFixTime == null) || (s2.getStreamTime().compareTo(lastFixTime) > 0)){
        gps.add(s2.makeGPS());
        updateFixTime(s2);
        s2count++;
      }

    }
  }

  private boolean checkForGSAfix(Stream stream) {
    if(stream.isGSAfix()){
      if((lastFixTime == null) || (timeDiff(stream.getStreamTime(), lastFixTime) > 1000)){
        gps.add(stream.makeGPS());
        updateFixTime(stream);
        return true;
      }
    }
    return false;
  }

  private void calculateOffset(Stream stream1, Stream stream2){
    float latOffset = stream1.getCurrentLat() - stream2.getCurrentLat();
    float lngOffset = stream1.getCurrentLng() - stream2.getCurrentLng();
    float elevOffset = stream1.getCurrentElev() - stream2.getCurrentElev();

    stream2.updateLatLongOffest(latOffset, lngOffset);
    stream2.updateElevOffset(elevOffset);
  }

  private void updateFixTime(Stream stream){
    lastFixTime = (Calendar)stream.getStreamTime().clone();
  }

  private long timeDiff(Calendar time1, Calendar time2){
    long now = time1.getTimeInMillis();
    long passed = now -  time2.getTimeInMillis();
    return passed;
  }


}
