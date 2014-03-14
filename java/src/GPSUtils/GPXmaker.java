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
      writer.write("Something");
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

}
