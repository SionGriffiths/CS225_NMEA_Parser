package Control;

import GPSUtils.FixType;
import GPSUtils.GPSposition;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;



/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 10/03/14
 *         Time: 17:57
 *
 * The Stream class holds all current information relating to a stream of parsed NMEA sentences.
 * Implementing setters and getters for coordinates, time, stream quality, coordinate offsets
 * and methods to calculate updates to these fields if required.
 *
 */
public class Stream {

  /**
   * The FileParser instance.
   * Holds a reference to a file.
   */
  private final FileParser fp;
  /**
   * Calendar instance to hold stream time and date.
   */
  private Calendar streamTime;


  private boolean endOfStream = false;
  private boolean GSAfix = false;
  private String currentTime;
  private String currentDate;

  private float currentLat = 0;
  private float currentLng = 0;
  private float currentElev = 0;

  private float latOffset = 0;
  private float lngOffset = 0;
  private float elevOffset = 0;

  public FixType fixtype = FixType.NO_FIX;
  /**
   * line counter - debug.
   */
  public int count = 0;

  /**
   * Constructs a Stream. Takes a file name as parameter,
   * creates a FileParser to access file content.
   * Initialises stream time with default values.
   * @param fileName the file name
   */
  public Stream(String fileName){
    fp = new FileParser(fileName);
    initTime();
  }

  /**
   * Instantiates a calendar instance and initialises
   * it with default values for time and date
   */
  private void initTime(){
    streamTime = new GregorianCalendar();
    currentTime = "110203";
    currentDate = "040506";
    updateTime(streamTime);
  }

  /**
   * Updates the current time.
   * @param timeToUpdate a new time
   */
  public void updateTime(Calendar timeToUpdate){

    SimpleDateFormat df = new SimpleDateFormat("ddMMyy HHmmss");
    Date initialDate = null;
    try {
      initialDate = df.parse(currentDate + " " + currentTime);
    } catch (ParseException e) {
      e.printStackTrace();
    }
    timeToUpdate.setTime(initialDate);

  }

  /**
   * Method to retrieve the next line in a file.
   * @return The line from file.
   */
  public String getNext(){
    String retValue;

    if((retValue = fp.readLine())==null){
      endOfStream = true;
    }
    return retValue;
  }

  /**
   * Creates a GPSposition based on current stream state.
   * Applies offsets to lat/long/elevation.
   * @return the GPSposition
   */
  public GPSposition makeGPS(){
    currentLat += latOffset;
    currentLng += lngOffset;
    currentElev += elevOffset;
    GPSposition gps = new GPSposition(currentLat, currentLng, currentElev, streamTime.clone());

    return gps;
  }


  ////---------------------------------------
  //          SETTERS & GETTERS
  ////---------------------------------------
  public boolean isEndOfStream(){
    return endOfStream;
  }

  public void updateLatLong(float lat, float lng){
    currentLat = lat;
    currentLng = lng;
  }

  public void updateElev(float elev){
    currentElev = elev;
  }
  public void updateLatLongOffest(float latOffset, float lngOffset){
    this.latOffset = latOffset;
    this.lngOffset = lngOffset;
  }

  public void updateElevOffset(float elevOffset){
    this.elevOffset = elevOffset;
  }

  public Calendar getStreamTime(){
    return streamTime;
  }

  public void setGSAfix(boolean gsaFix){
    GSAfix = gsaFix;
  }

  public void setFixtype(FixType fixtype){
    this.fixtype = fixtype;
  }
  public FixType getFixtype(){
    return fixtype;
  }
  public void setTime(String time){
    currentTime = time;
  }
  public void setDate(String date){
    currentDate = date;
  }

  public float getCurrentLat() {
    return currentLat;
  }

  public float getCurrentElev(){
    return currentElev;
  }

  public float getCurrentLng() {
    return currentLng;
  }


}
