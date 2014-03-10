import java.util.ArrayList;

/**
 * Created by sig2 on 10/03/14.
 */
public class Launcher {

  public static void main(String[] args) {

    FileParser fp = new FileParser();
    Controller sp = new Controller();
    ArrayList<String> file1 = fp.readFile("dataFiles/gps_1.dat");
    ArrayList<String> file2 = fp.readFile("dataFiles/gps_2.dat");
    Sentence current;

    for(int i = 0; i < 5; i++){
      current = sp.parseSentence(file2.get(i));
      if(current instanceof GGA){
        System.out.println(((GGA) current).makeGPSposition().toString());
      }
      if(current instanceof RMC){
        System.out.println(((RMC) current).makeGPSposition().toString());
      }

    }


  }
}
