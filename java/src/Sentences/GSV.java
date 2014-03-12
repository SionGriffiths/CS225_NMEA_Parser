package Sentences;


import Control.Stream;

import java.util.ArrayList;

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

    int numLines = Integer.parseInt(sentenceData[1]);
    int goodSNRcount = 0;
    ArrayList<String[]> GSVlines = new ArrayList<String []>();
    GSVlines.add(sentenceData);

    for(int i = 1; i < numLines; i++){
      String[] temp = stream.getNext().split("[,*]");
      GSVlines.add(temp);
      stream.count++;
    }

    for(String[] sData : GSVlines){
      for(int i = 7; i < sData.length; i+=4){
        if(!(sData[i].equals(""))){
          int snrValue = Integer.parseInt(sData[i]);
          if(snrValue >= 35){
            goodSNRcount++;
          }
        }
      }

    }

    stream.setIsGoodFix(goodSNRcount >=3);

  }
}
