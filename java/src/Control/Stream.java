package Control;

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

  private boolean goodFix = false;

  private String currentTime;
  private String currentDate;

  private float currentLat = 0;
  private float currentLng = 0;
  private float currentElev = 0;

  private float latOffset = 0;
  private float lngOffset = 0;
  private float elevOffset = 0;


  public Stream(String fileName){
    fp = new FileParser();
    fp.setFile(fileName);
    initTime();
  }

  private void initTime(){
    streamTime = new GregorianCalendar();

    //init with debug values
    currentTime = "110203";
    currentDate = "040506";
    updateTime();
  }

  public void updateTime(){

    SimpleDateFormat df = new SimpleDateFormat("ddMMyy HHmmss");
    Date initialDate = null;
    try {
      initialDate = df.parse(currentDate + " " + currentTime);
    } catch (ParseException e) {
      e.printStackTrace();
    }
    streamTime.setTime(initialDate);
  }

  public String getNext(){
    return fp.readLine();
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

  public boolean getIsGoodFix(){
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
}
