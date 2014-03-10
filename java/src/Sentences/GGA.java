package Sentences;

import GPSUtils.GPSposition;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class GGA extends Sentence {

  public GGA(String[] input){
    data = input;
  }

  public GPSposition makeGPSposition(){

    float lat = Float.parseFloat(data[2]);
    float lng = Float.parseFloat(data[4]);
    float elevation = Float.parseFloat(data[9]);
    lat /= 100;
    lng /= 100;
    GPSposition gps = new GPSposition(lat, lng );
    gps.setElevation(elevation);


    return gps;
  }

}
