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

  public StringBuffer GPXoutput(StringBuffer sb){

    sb = formatLatLong(sb);
    sb = formatElev(sb);
    sb = formatTimeOutput(sb);
    sb.append("</wpt>\n");


    return sb;
  }

  private StringBuffer formatTimeOutput(StringBuffer sb){
    sb.append("<time>");
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
    sb.append("</time> \n");


    return sb;
  }

  private StringBuffer formatElev(StringBuffer sb){
    sb.append("<ele>");
    sb.append(elevation);
    sb.append("</ele> \n");

    return sb;
  }

  private StringBuffer formatLatLong(StringBuffer sb){

    sb.append("<wpt lat=\"");
    sb.append(lat);
    sb.append("\" lon=\"");
    sb.append(lng);
    sb.append("\"> \n");

    return sb;
  }
  public float getLng() {
    return lng;
  }

  public void setLng(float lng) {
    this.lng = lng;
  }

  public float getLat() {
    return lat;
  }

  public void setLat(float lat) {
    this.lat = lat;
  }

  public float getElevation() {
    return elevation;
  }

  public void setElevation(float elevation) {
    this.elevation = elevation;
  }

}
