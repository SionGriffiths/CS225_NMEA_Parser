package GPSUtils;

import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:51
 * The GPSposition class holds information about a single GPS fix.
 * With standard coordinates, elevation and time detail.
 * Methods are implemented to facilitate the setting of these fields
 * and format their output to file.
 */
public class GPSposition {

  private final float lat;
  private final float lng;
  private final float elevation;
  private final Calendar time;

  /**
   * Constructs a GPSposition from parameter data. Converts lat/long representations
   * from NMEA to more standard format.   *
   * @param lat latitude
   * @param lng longitude
   * @param elevation elevation
   * @param time time
   */
  public GPSposition(float lat, float lng, float elevation, Object time ){

    this.lat = nmeaToDecimalDegress(lat);
    this.lng = nmeaToDecimalDegress(lng);
    this.elevation = elevation;
    this.time = (Calendar)time;
  }

  /**
   * Converts lat/long representations
   * from NMEA to more standard format.
   * @param nmea the nmea coordinate to be converted
   * @return the converted value
   */
  public float nmeaToDecimalDegress(float nmea){
    int D = (int)(nmea / 100);
    float m = nmea - (D * 100);
    return D+(m/60);
  }


  /**
   * Adds formatted GPS data to StringBuffer for XML output
   * @param sb StringBuffer instance
   * @return the StringBuffer instance
   */
  public StringBuffer GPXoutput(StringBuffer sb){

    sb = formatLatLong(sb);
    sb = formatElev(sb);
    sb = formatTimeOutput(sb);
    sb.append("</wpt>\n");


    return sb;
  }

  /**
   * Adds formatted time representation to StringBuffer for XML
   * output
   * @param sb StringBuffer instance
   * @return the StringBuffer instance
   */
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

  /**
   * Formats elevation for XML output
   * @param sb StringBuffer instance
   * @return the StringBuffer instance
   */
  private StringBuffer formatElev(StringBuffer sb){
    sb.append("<ele>");
    sb.append(elevation);
    sb.append("</ele> \n");

    return sb;
  }

  /**
   * Formats lat/long for XML output
   * @param sb StringBuffer instance
   * @return the StringBuffer instance
   */
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

  public float getLat() {
    return lat;
  }

  public String toString(){
    return time.getTime() +  ", " + lat + ", " + lng + ", " + elevation;
  }

}
