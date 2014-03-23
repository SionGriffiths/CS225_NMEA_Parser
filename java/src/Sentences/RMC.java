package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 *
 *  The RMC class extracts GPS position information from an NMEA RMC sentence
 */
public class RMC extends Sentence {


  private float lat;
  private float lng;

  /**
   * Constructs an RMC
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public RMC(String[] input, Stream stream){
    sentenceData = input;
    makeGPSposition();
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
   *
   * @return String representation of the Stream date.
   */
  private String makeDate(){
    return sentenceData[9];
  }

  /**
   * Finds latitude and longitude values in the tokenised sentence.
   */
  public void makeGPSposition(){
    lat = Float.parseFloat(sentenceData[3]);
    lng = Float.parseFloat(sentenceData[5]);

    if(sentenceData[6].equals("W")){
      lng *= -1;
    }
    if(sentenceData[4].equals("S")){
      lat *= -1;
    }

  }

  /**
   * Updates the Stream instance. Passes GPS position and time values
   * back to the Stream
   * @param stream the Stream instance
   */
  @Override
  protected void updateStream(Stream stream) {
   stream.setTime(makeTime());
   stream.setDate(makeDate());
   stream.updateTime(stream.getStreamTime());
   stream.updateLatLong(lat,lng);
  }
}
