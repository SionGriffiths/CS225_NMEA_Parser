package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 11/03/14
 *         Time: 16:09
 * The GBS class extracts time information from an NMEA GBS sentence.
 */
public class GBS extends Sentence {

  /**
   * Constructs a GBS
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public GBS (String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  /**
   *
   * @return String representation of the Stream time.
   */
  private String makeTime(){
    return sentenceData[1];
  }

  /**
   * Updates the Stream. Finds time representation in the current sentence and
   * passes the value back to the Stream
   * @param stream the Stream instance
   */
  @Override
   protected void updateStream(Stream stream) {
    stream.setTime(makeTime());
    stream.updateTime(stream.getStreamTime());
  }

}
