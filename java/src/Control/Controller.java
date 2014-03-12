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
  private ArrayList<GPSposition> gps;

  public Controller(){
    s1 = new Stream("dataFiles/gps_1.dat");
    s2 = new Stream("dataFiles/gps_2.dat");
    gps = new ArrayList<GPSposition>();
  }

  public void run(){
    for(int i = 0; i < 2900; i++){

      parseSentence(s1);
      parseSentence(s2);
    }
   System.out.println("S1 : " + s1.count + " | S2 : " + s2.count);
  }

  public void parseSentence(Stream stream){
    String input;
    if((input=stream.getNext()) != null){
      String[] parts = input.split("[,*]");
      stream.count++;
      String type = parts[0];


      switch(type){
        case "$GPGSA" :
         new GSA(parts, stream);
          break;

        case "$GPGGA" :
         new GGA(parts, stream);
          break;

        case "$GPRMC" :
         new RMC(parts, stream);
          break;

        case "$GPGSV" :
         new GSV(parts, stream);
          break;

        case "$GPZDA" :
          new ZDA(parts, stream);
          break;

        case "$GPGBS" :
          new GBS(parts, stream);
          break;

        default:
          System.err.println("Unrecognised sentence : " + input);
      }
    }
  }

}
