package GPSUtils;

import java.io.*;
import java.util.ArrayList;


/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 * Date: 14/03/14
 * Time: 09:01
  */
public class GPXmaker {

  private final ArrayList<GPSposition> gps;



  public GPXmaker(ArrayList<GPSposition> gps, String fileName){
    this.gps = gps;
    makeGPX(fileName);
  }

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

  private String footerString(){

    return  "</gpx>";
  }

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
/*public static int[] getMinMax(Comparable[] items){
    Comparable min = null;
    Comparable max = null;

    for(Comparable i : items){
      if(min == null || i.compareTo(min) < 0){
        min = i;
      }
      if(max == null || i.compareTo(max) > 0){
        max = i;
      }
    }
    int[] minmax = new int[2];

    minmax[0] = Integer.parseInt(min.toString());
    minmax[1] =  Integer.parseInt(max.toString());
    return minmax;
  }
*/