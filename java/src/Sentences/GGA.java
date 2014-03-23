package Sentences;

import Control.Stream;


/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class GGA extends Sentence {

  private float lat;
  private float lng;
  private float elevation;

  public GGA(String[] input,  Stream stream){
    sentenceData = input;
    makeGPSposition();
    updateStream(stream);
  }

  private String makeTime(){
    return sentenceData[1];
  }

  public void makeGPSposition(){
    lat = Float.parseFloat(sentenceData[2]);
    lng = Float.parseFloat(sentenceData[4]);
    if(sentenceData[5].equals("W")){
      lng *= -1;
    }
    if(sentenceData[3].equals("S")){
      lat *= -1;
    }
    elevation = Float.parseFloat(sentenceData[9]);

  }

  @Override
  protected void updateStream(Stream stream) {
    stream.updateLatLong(lat, lng);
    stream.updateElev(elevation);
    stream.setTime(makeTime());
    stream.updateTime(stream.getStreamTime());
  }
}
