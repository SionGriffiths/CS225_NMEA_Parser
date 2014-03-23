package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:38
 * The GSA class extracts very basic fix quality from an NMEA GSA sntance
 */
public class GSA extends Sentence {


  /**
   * Constructs a GSA
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public GSA(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }


  /**
   * Updates the stream with a value representing whether a
   * good fix is available.
   * @param stream the Stream instance
   */
  @Override
  protected void updateStream(Stream stream) {
    int satCount = 0;

    for(int i = 3; i < 15; i++){
      if(sentenceData[i].equals("")){
        satCount++;
      }
    }
    int total = 12 - satCount;
    stream.setGSAfix(total >= 3 && sentenceData[1].equals("3"));
  }
}
