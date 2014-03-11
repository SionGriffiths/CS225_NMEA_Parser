package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 */
public abstract class Sentence {

  protected String[] sentenceData;
  //protected Stream stream;

  protected abstract void updateStream(Stream stream);

  protected String[] getSentenceData(){
    return sentenceData;
  }


}
