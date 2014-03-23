package Sentences;

import Control.Stream;


/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 *
 * The GGA class extracts GPS position information from an NMEA GGA sentence
 */
public class GGA extends Sentence {

  private float lat;
  private float lng;
  private float elevation;

  /**
   * Constructs a GGA
   * @param input array of tokenised NMEA sentence.
   * @param stream The Stream instance containing the sentence
   */
  public GGA(String[] input,  Stream stream){
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
   * Finds elevation, latitude and longitude values in the tokenised sentence.   *
   */
  public void makeGPSposition(){
    lat = Float.parseFloat(sentenceData[2]);
    lng = Float.parseFloat(sentenceData[4]);
    if(sentenceData[5].equals("W")){
      lng *= -1;
    }
    if(sentenceData[3].equals("S")){
      lat *= -1;
    }
    elevation = Float.parseFloat(sentenceData[9]);

  }

  /**
   * Updates the Stream instance. Passes GPS position and time values
   * back to the Stream
   * @param stream the Stream instance
   */
  @Override
  protected void updateStream(Stream stream) {
    stream.updateLatLong(lat, lng);
    stream.updateElev(elevation);
    stream.setTime(makeTime());
    stream.updateTime(stream.getStreamTime());
  }
}
