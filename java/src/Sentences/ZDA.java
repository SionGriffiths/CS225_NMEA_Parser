package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:38
 */
public class ZDA extends Sentence{

  public ZDA(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  public String makeTime(){
    return sentenceData[1];
  }

  public String makeDate(){
    return sentenceData[2] + sentenceData[3] + sentenceData[4].charAt(2) + sentenceData[4].charAt(3);
  }

  @Override
  protected void updateStream(Stream stream) {
    stream.setTime(makeTime());
    stream.setDate(makeDate());
    stream.updateTime();
  }
}
