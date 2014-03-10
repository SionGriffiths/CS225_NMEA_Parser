/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class RMC extends Sentence {

  public RMC(String[] input){
    data = input;

  }

  public GPSposition makeGPSposition(){
    int time = Integer.parseInt(data[1]);
    float lat = Float.parseFloat(data[3]);
    float lng = Float.parseFloat(data[5]);

    lat /= 100;
    lng /= 100;
    GPSposition gps = new GPSposition(time,lat, lng );



    return gps;
  }
}
