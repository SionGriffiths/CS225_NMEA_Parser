package GPSUtils;

import java.io.*;
import java.util.ArrayList;

/**
 * Created by sig2 on 14/03/14.
 */
public class GPXmaker {

  private ArrayList<GPSposition> gps;



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
        writer.close();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }

  private String buildGPX() {
    StringBuffer sb = new StringBuffer();
    sb = headerString(sb);
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
    sb.append("<bounds minlat=\"42.401051\" minlon=\"-71.126602\" maxlat=\"42.468655\" maxlon=\"-71.102973\"/>\n");
    return sb;
  }

  private String footerString(){
    String footer = "</gpx>";
    return footer;
  }

}
