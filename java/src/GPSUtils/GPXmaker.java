package GPSUtils;

import java.io.*;
import java.util.ArrayList;


/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 * Date: 14/03/14
 * Time: 09:01
 *
 * The GPXmaker class facilitates the creation of a formatted XML file
 * to output all corrected GPS positions.
  */
public class GPXmaker {

  /**
   * List of GPS positions
   */
  private final ArrayList<GPSposition> gps;

  /**
   * Constructs a GPXmaker.
   * @param gps List of gps positions
   * @param fileName name of output file.
   */
  public GPXmaker(ArrayList<GPSposition> gps, String fileName){
    this.gps = gps;
    makeGPX(fileName);
  }

  /**
   * Writes to the gpx output file
   * @param fileName the file name
   */
  public void makeGPX(String fileName){
    Writer writer = null;
    try {
      writer = new BufferedWriter(new OutputStreamWriter(
          new FileOutputStream(fileName), "utf-8"));
      writer.write(buildGPX());
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        assert writer != null;
        writer.close();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }

  /**
   * Appends to a StringBuffer the correctly formatted
   * data including headers. A complete gpx file will be returned.
   * @return a StringBuffer instance containing a complete GPX formatted output string.
   */
  private String buildGPX() {
    StringBuffer sb = new StringBuffer();
    sb = headerString(sb);
    sb = findBounds(sb);
    for(GPSposition g : gps){
      sb = g.GPXoutput(sb);
    }
    sb.append(footerString());
    return sb.toString();
  }

  /**
   * Appends a formatted header to the GPX file StringBuffer instance
   * @param sb the StringBuffer instance
   * @return the StringBuffer instance
   */
  private StringBuffer headerString(StringBuffer sb){
    sb.append("<?xml version=\"1.0\"?> \n");
    sb.append("<gpx \n");
    sb.append("version=\"1.0\" \n");
    sb.append("creator=\"ExpertGPS 1.1 - http://www.topografix.com\" \n");
    sb.append("xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" \n");
    sb.append(" xmlns=\"http://www.topografix.com/GPX/1/0\" \n");
    sb.append(" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/0 http://www.topografix.com/GPX/1/0/gpx.xsd\"> \n");

    return sb;
  }

  /**
   * Closing tag for the file
   * @return "</gpx>"
   */
  private String footerString(){

    return  "</gpx>";
  }

  /**
   * Finds smallest and highest values for latitude and longitude
   * in the list of gps positions.
   * Adds these values to the StringBuffer instance within formatting tags.
   * @param sb the StringBuffer instance
   * @return the StringBuffer instance
   */
  private StringBuffer findBounds(StringBuffer sb){
    float minlat = 91;
    float minlong = 181;
    float maxlat = -91;
    float maxlong = -181;

    for(GPSposition g : gps){
      if(minlat > g.getLat()){
        minlat = g.getLat();
      }
      if(minlong > g.getLng()){
        minlong = g.getLng();
      }
      if(maxlat < g.getLat()){
        maxlat = g.getLat();
      }
      if(maxlong < g.getLng()){
        maxlong = g.getLng();
      }
    }

    sb.append("<bounds minlat=\"").append(minlat).append("\" minlon=\"").append(minlong).append("\" maxlat=\"").append(maxlat).append("\" maxlon=\"").append(maxlong).append("\"/>\n");

    return sb;
  }

}

