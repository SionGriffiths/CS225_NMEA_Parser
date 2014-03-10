import java.util.ArrayList;

/**
 * Created by sig2 on 10/03/14.
 */
public class Launcher {

  public static void main(String[] args) {
    FileParser sp = new FileParser();

    ArrayList<String> file1 = sp.readFile("dataFiles/gps_1.dat");
    ArrayList<String> file2 = sp.readFile("dataFiles/gps_2.dat");

    String[] parts = file1.get(3).split("[,*]");

    for(String s : parts){
      System.out.println(s);
    }

  }
}
