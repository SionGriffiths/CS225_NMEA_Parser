package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class RMC extends Sentence {


  public RMC(String[] input, Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  private String makeTime(){
    return sentenceData[1];
  }

  private String makeDate(){
    return sentenceData[9];
  }

  @Override
  protected void updateStream(Stream stream) {
   stream.setTime(makeTime());
   stream.setDate(makeDate());
   stream.updateTime();
  }
}
