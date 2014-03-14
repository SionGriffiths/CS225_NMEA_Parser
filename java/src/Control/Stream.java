package Control;

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
 */
public class Stream {

  private FileParser fp;
  private Calendar streamTime;

  private boolean goodFix = true;
  private boolean GSAfix;
  private boolean endOfStream = false;

  private String currentTime;
  private String currentDate;

  private float currentLat = 0;
  private float currentLng = 0;
  private float currentElev = 0;

  private float latOffset = 0;
  private float lngOffset = 0;
  private float elevOffset = 0;


  public int count = 0;

  public Stream(String fileName){
    fp = new FileParser(fileName);
    initTime();
  }

  private void initTime(){
    streamTime = new GregorianCalendar();
//  lastFixTime = new GregorianCalendar();
//  init with debug values
    currentTime = "110203";
    currentDate = "040506";
    updateTime(streamTime);
//  updateTime(lastFixTime);
  }

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

  public String getNext(){
    String retValue;

    if((retValue = fp.readLine())==null){
      endOfStream = true;
    }
      return retValue;
  }

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

  public GPSposition makeGPS(){
    currentLat += latOffset;
    currentLng += lngOffset;
    currentElev += elevOffset;
    GPSposition gps = new GPSposition(currentLat, currentLng, currentElev, streamTime.clone());
//    updateTime(lastFixTime);
    return gps;
  }
  public Calendar getStreamTime(){
    return streamTime;
  }

  public void setGSAfix(boolean gsaFix){
    GSAfix = gsaFix;
  }
  public boolean isGSAfix(){
    return GSAfix;
  }
  public boolean isGoodFix(){
    return goodFix;
  }
  public void setIsGoodFix(boolean fix){
    goodFix = fix;
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
