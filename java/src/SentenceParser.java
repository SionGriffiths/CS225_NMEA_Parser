/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:14
 */
public class SentenceParser {


  public Sentence parseSentence(String[] inputLine){

    String type = inputLine[0];
    Sentence sentence = null;

    switch(type){
      case "$GPGSA" :
        sentence = new GSA();
        break;
      case "$GPGGA" :
        sentence = new GGA();
        break;
      case "$GPRMC" :
        sentence = new RMC();
        break;
      case "$GPGSV" :
        sentence = new GSV();
        break;
      case "$GPZDA" :
        sentence = new ZDA();
        break;
    }

    return sentence;
  }

}
