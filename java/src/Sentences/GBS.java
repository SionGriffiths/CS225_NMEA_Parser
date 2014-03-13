package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 11/03/14
 *         Time: 16:09
 */
public class GBS extends Sentence {

  public GBS (String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  private String makeTime(){
    return sentenceData[1];
  }

  @Override
  protected void updateStream(Stream stream) {
    stream.setTime(makeTime());
    stream.updateTime(stream.getStreamTime());
  }

}
