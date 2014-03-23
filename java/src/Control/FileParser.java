package Control;

import java.io.*;


/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:52
 * The FileParser implements methods to enable a text file to be read into the system one line
 * at a time.
 */
public class FileParser {

  /**The File instance to hold a reference to a file */
  private File file;

  /**A Buffered reader to facilitate reading of the file*/
  private BufferedReader bRead;

  /**A String to hold each line of the file, initialised to empty*/
  private String line ="";


  /**
   * Constructs a FilePaser instance. Uses a filepath to set current file.
   * @param fileName name/path of current file.
   */
  public FileParser(String fileName){
    setFile(fileName);
  }

  /**
   * Sets current file
   * @param fileName name/path of current file.
   */
  public void setFile(String fileName){
    file = new File(fileName);
    try {
      bRead = new BufferedReader(new FileReader(file));
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

  /**
   * Reads and returns a single line from the current file.
   * Subsequent calls to this method will progress the returned lines through the file.
   * @return a String representing the current line in a file.
   */
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

        } catch (IOException e) {
          e.printStackTrace();
        }
      }

      return line;
    }
  }

}




