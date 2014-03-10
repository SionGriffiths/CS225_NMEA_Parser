package Sentences;

import GPSUtils.GPSposition;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class RMC extends Sentence {

  public RMC(String[] input){
    data = input;

  }

  public void makeTime(){

    StringBuffer sb = new StringBuffer();
    sb.append(data[1].charAt(0));
    sb.append(data[1].charAt(1));
    sb.append("-");
    sb.append(data[1].charAt(2));
    sb.append(data[1].charAt(3));
    sb.append("-");
    sb.append(data[1].charAt(4));
    sb.append(data[1].charAt(5));

    System.out.println(sb.toString());

  }

  public GPSposition makeGPSposition(){

    float lat = Float.parseFloat(data[3]);
    float lng = Float.parseFloat(data[5]);

    lat /= 100;
    lng /= 100;
    GPSposition gps = new GPSposition(lat, lng );

    return gps;
  }
}
