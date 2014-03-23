package Sentences;

import Control.Stream;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:37
 * The Sentence class is an abstract class which represents sn NMEA sentence.
 */

public abstract class Sentence {

  /**
   * Array of tokenised sentence strings.
   */
  protected String[] sentenceData;

  /**
   * Subclasses will implement this method to update a given stream
   * @param stream The stream instance
   */
  protected abstract void updateStream(Stream stream);




}
