package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public class GSV extends Sentence {

  public GSV(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  @Override
  protected void updateStream(Stream stream) {

  }
}
