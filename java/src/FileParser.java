import java.io.*;
import java.util.ArrayList;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:52
 */
public class FileParser {

  /**The File instance to hold a reference to a file */
  private File file;

  /**A Buffered reader to facilitate reading of the file*/
  private BufferedReader bRead;

  /**A String to hold each line of the file, initialised to empty*/
  private String line ="";

  private ArrayList<String> sentences;

  public FileParser(){
    sentences = new ArrayList<String>();
  }

  public ArrayList<String> readFile(String  fileName){
    try {
      file = new File(fileName);
      bRead = new BufferedReader(new FileReader(file));

      while((line = bRead.readLine()) != null){
        sentences.add(line);
      }

      bRead.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

    return sentences;
  }



}
