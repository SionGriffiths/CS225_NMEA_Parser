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

  @Override
  protected void updateStream(Stream stream) {

  }
}
