import Control.Controller;
import Control.FileParser;
import Control.Stream;

/**
 * Created by sig2 on 10/03/14.
 */
public class Launcher {

  public static void main(String[] args) {

    Stream s1 = new Stream("dataFiles/gps_1.dat");
    Controller sp = new Controller();



    String line1 = s1.getNext();
    String line2 = s1.getNext();
    System.out.println(line1 + "\n" + line2);

  }
}
