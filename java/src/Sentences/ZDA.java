package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:38
 *  The ZDA class extracts time/date information from an NMEA ZDA sentence
 */
public class ZDA extends Sentence{

  /**
   * Constructs a ZDA
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public ZDA(String[] input,  Stream stream){
    sentenceData = input;
    updateStream(stream);
  }

  /**
   *
   * @return String representation of the Stream time.
   */
  public String makeTime(){
    return sentenceData[1];
  }

  /**
   *
   * @return String representation of the Stream date.
   */
  public String makeDate(){
    return sentenceData[2] + sentenceData[3] + sentenceData[4].charAt(2) + sentenceData[4].charAt(3);
  }

  /**
   * Updates the Stream instance. Passes time and date values
   * back to the Stream
   * @param stream the Stream instance
   */
  @Override
  protected void updateStream(Stream stream) {
    stream.setTime(makeTime());
    stream.setDate(makeDate());
    stream.updateTime(stream.getStreamTime());
  }
}
