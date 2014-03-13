package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:38
 */
public class GSA extends Sentence {


  public GSA(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }




  @Override
  protected void updateStream(Stream stream) {
    int satCount = 0;

    for(int i = 3; i < 15; i++){
      if(sentenceData[i].equals("")){
        satCount++;
      }
    }
    int total = 12 - satCount;
    stream.setGSAfix(total > 3 && sentenceData[1].equals("3"));
  }
}
