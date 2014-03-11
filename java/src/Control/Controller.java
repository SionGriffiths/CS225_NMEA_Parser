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

  private Stream s1;
  private Stream s2;

  private boolean goodFix = false;
  private ArrayList<GPSposition> gps;




  public Controller(){
    s1 = new Stream("dataFiles/gps_1.dat");
    s2 = new Stream("dataFiles/gps_2.dat");
    gps = new ArrayList<GPSposition>();

  }

  public void run(){

    String input;
    while((input = s2.getNext()) != null){
      parseSentence(input, s2);
    }

  }

  public void parseSentence(String inputLine, Stream stream){

    String[] parts = inputLine.split("[,*]");

    String type = parts[0];
    Sentence sentence = null;

    switch(type){
      case "$GPGSA" :
        sentence = new GSA(parts, stream);
        break;

      case "$GPGGA" :
        sentence = new GGA(parts, stream);
        break;

      case "$GPRMC" :
        sentence = new RMC(parts, stream);
        break;

      case "$GPGSV" :
        sentence = new GSV(parts, stream);

        break;

      case "$GPZDA" :
        sentence = new ZDA(parts, stream);
        break;

      case "$GPGBS" :
        sentence = new GBS(parts, stream);
        break;

      default:
        System.err.println("Unrecognised sentence: " + type + " : " + inputLine);
    }

  }

}
