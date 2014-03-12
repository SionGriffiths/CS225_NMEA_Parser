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
  private boolean stream1 = false;
  private boolean stream2 = false;
  int s1count = 0;
  int s2count = 0;


  public Controller(){
    s1 = new Stream("dataFiles/gps_1.dat");
    s2 = new Stream("dataFiles/gps_2.dat");
    gps = new ArrayList<GPSposition>();

  }

  public void run(){

    String input1;
    String input2;

    for(int i = 0; i < 2900; i++){




      if(s1.getStreamTime().compareTo(s2.getStreamTime()) < 0){
        System.out.println("S1 early");
        if((input1 = s1.getNext())!=null){
          parseSentence(input1, s1);
          s1count++;
        }
      }else  if(s1.getStreamTime().compareTo(s2.getStreamTime()) > 0){
        System.out.println("S2 early");
        if((input2 = s2.getNext())!=null){
          parseSentence(input2, s2);
          s2count++;
        }
      }else{
        System.out.println("Same");
        if((input1 = s1.getNext())!=null){
          parseSentence(input1, s1);
          s1count++;
        }
        if((input2 = s2.getNext())!=null){
          parseSentence(input2, s2);}
        s2count++;
      }
        System.out.println("S1 : " + s1count + " | S2 : "+ s2count);
    }
   /*while((input2 = s2.getNext()) != null){
      parseSentence(input2, s2);
      stream2 = true;
    }*/

    /*do{
      if((input2 = s2.getNext()) != null){
        parseSentence(input2, s2);
        stream2 = true;
      }else{
        stream2 = false;
      }
      if((input1 = s1.getNext()) != null){
        parseSentence(input1, s1);
        stream1 = true;
      }else{
        stream1 = false;
      }
    }while(stream1 || stream2);*/
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
        System.err.println("Unrecognised sentence : " + inputLine);
    }

  }

}
