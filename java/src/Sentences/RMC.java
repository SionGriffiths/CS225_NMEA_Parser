package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class RMC extends Sentence {


  private float lat;
  private float lng;

  public RMC(String[] input, Stream stream){
    sentenceData = input;
    makeGPSposition();
    updateStream(stream);
  }

  private String makeTime(){
    return sentenceData[1];
  }

  private String makeDate(){
    return sentenceData[9];
  }

  public void makeGPSposition(){
    lat = Float.parseFloat(sentenceData[3]);
    lng = Float.parseFloat(sentenceData[5]);

    if(sentenceData[6].equals("W")){
      lng *= -1;
    }
    if(sentenceData[4].equals("S")){
      lat *= -1;
    }
    lat /= 100;
    lng /= 100;
  }

  @Override
  protected void updateStream(Stream stream) {
   stream.setTime(makeTime());
   stream.setDate(makeDate());
   stream.updateTime(stream.getStreamTime());
   stream.updateLatLong(lat,lng);
  }
}
