package GPSUtils;

import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:51
 */
public class GPSposition {

  private float lat;
  private float lng;
  private float elevation;
  private Calendar time;

  public GPSposition(float lat, float lng, float elevation, Object time ){

    this.lat = lat;
    this.lng = lng;
    this.elevation = elevation;
    this.time = (Calendar)time;
  }


  public String toString(){
    return time.getTime() +  ", " + lat + ", " + lng + ", " + elevation;
  }

  public String GPXoutput(){
    StringBuffer sb = new StringBuffer();

    sb = formatTimeOutput(sb);


    return sb.toString();
  }

  public StringBuffer formatTimeOutput(StringBuffer sb){

    sb.append(time.get(Calendar.YEAR));
    sb.append("-");
    sb.append(time.get(Calendar.MONTH)+1);
    sb.append("-");
    sb.append(time.get(Calendar.DAY_OF_MONTH));
    sb.append("T");
    sb.append(time.get(Calendar.HOUR_OF_DAY));
    sb.append(":");
    sb.append(time.get(Calendar.MINUTE));
    sb.append(":");
    sb.append(time.get(Calendar.SECOND));
    sb.append("Z");
    
    return sb;
  }
}
