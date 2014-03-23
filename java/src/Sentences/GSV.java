package Sentences;


import Control.Stream;
import GPSUtils.FixType;

import java.util.ArrayList;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 *
 * The GSV class extracts accurate fix quality from an NMEA GSA sntance
 * The fixquality return is used to decide whether a fix should be taken
 */
public class GSV extends Sentence {

  /**
   * Constructs a GSV
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public GSV(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  /**
   * Updates the stream fix quality.
   * GSV sentences come in batches of 1-3. Method extracts and
   * parses extra sentences then counts the number of
   * satellites with SNR values in given ranges.
   * @param stream the Stream instance
   */
  @Override
  protected void updateStream(Stream stream) {

    int numLines = Integer.parseInt(sentenceData[1]);
    int goodSNRcount = 0;
    int minSNRcount = 0;
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
          if(snrValue < 35 && snrValue >= 30){
            minSNRcount++;
          }
        }
      }

    }

    if(goodSNRcount >= 3){
      stream.setFixtype(FixType.GOOD_FIX);
    }else if(goodSNRcount + minSNRcount >= 3){
      stream.setFixtype(FixType.MIN_FIX);
    }else{
      stream.setFixtype(FixType.NO_FIX);
    }
  }
}
