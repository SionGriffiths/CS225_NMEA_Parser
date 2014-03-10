package Control;

import GPSUtils.GPSposition;
import Sentences.*;

import java.util.ArrayList;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:14
 */
public class Controller {

  private boolean goodFix = false;
  private ArrayList<GPSposition> gps;

  public Controller(){
    gps = new ArrayList<GPSposition>();
  }

  public Sentence parseSentence(String inputLine){

    String[] parts = inputLine.split("[,*]");

    String type = parts[0];
    Sentence sentence = null;

    switch(type){
      case "$GPGSA" :
        sentence = new GSA(parts);
        goodFix = ((GSA) sentence).goodfix();
        break;
      case "$GPGGA" :
        sentence = new GGA(parts);

        break;
      case "$GPRMC" :
        sentence = new RMC(parts);
        ((RMC) sentence).makeTime();
        break;
      case "$GPGSV" :
        sentence = new GSV(parts);
        break;
      case "$GPZDA" :
        sentence = new ZDA(parts);
        break;
    }

    return sentence;
  }

}
