import java.util.ArrayList;

/**
 * Created by sig2 on 10/03/14.
 */
public class Launcher {

  public static void main(String[] args) {
    FileParser sp = new FileParser();

    ArrayList<String> sentences = sp.readFile("dataFiles/gps_2.dat");

    String[] parts = sentences.get(0).split(",");

    for(String s : parts){
      System.out.println(s);
    }

  }
}
