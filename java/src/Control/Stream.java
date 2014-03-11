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

  private Calendar streamTime;
  private boolean goodFix = false;
  private float latOffset = 0;
  private float lngOffset = 0;
  private float elevOffset = 0;
  private FileParser fp;


  public Stream(String fileName){
    fp = new FileParser();
    fp.setFile(fileName);


  }

  private void initTime(){
    streamTime = new GregorianCalendar();
    SimpleDateFormat df = new SimpleDateFormat("hh-mm-ss");
    Date initialTime = null;
    try {
      initialTime = df.parse("00-00-00");
    } catch (ParseException e) {
      e.printStackTrace();
    }
    streamTime.setTime(initialTime);
  }

  public String getNext(){
    return fp.readLine();
  }

  public void updateLatLongOffest(float latOffset, float lngOffset){
    this.latOffset = latOffset;
    this.lngOffset = lngOffset;
  }

  public void updateElevOffset(float elevOffset){
    this.elevOffset = elevOffset;
  }

  public boolean getStreamQuality(){
    return goodFix;
  }
  public void setStreamQuality(boolean fix){
    goodFix = fix;
  }
}
