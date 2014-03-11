package Sentences;

import Control.Stream;
import GPSUtils.GPSposition;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class GGA extends Sentence {

  public GGA(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  public GPSposition makeGPSposition(){

    float lat = Float.parseFloat(sentenceData[2]);
    float lng = Float.parseFloat(sentenceData[4]);
    float elevation = Float.parseFloat(sentenceData[9]);
    lat /= 100;
    lng /= 100;
    GPSposition gps = new GPSposition(lat, lng );
    gps.setElevation(elevation);


    return gps;
  }

  @Override
  protected void updateStream(Stream stream) {

  }
}
