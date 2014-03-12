package Control;

import java.io.*;


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

//  private ArrayList<String> sentences;

  public FileParser(){

  }


  public void setFile(String fileName){
    file = new File(fileName);
    try {
      bRead = new BufferedReader(new FileReader(file));
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

  public String readLine(){

    if(bRead == null){
      return null;
    }else{
      try {
        line = bRead.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }


      if(line == null){
        try {
          bRead.close();
          bRead = null;
          System.err.println("END OF FILE");
        } catch (IOException e) {
          e.printStackTrace();
        }
      }

      return line;
    }
  }

}




/*public ArrayList<String> readFile(String  fileName){
    sentences = new ArrayList<String>();

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
  }*/
