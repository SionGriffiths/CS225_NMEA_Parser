/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:38
 */
public class GSA extends Sentence {


  public GSA(String[] input){
    data = input;

  }

  public boolean goodfix(){
    int satCount = 0;

    for(int i = 3; i < 15; i++){
      if(data[i].equals("")){
        satCount++;
      }
    }
    int total = 12 - satCount;
    return total > 3 && data[1].equals("3");
  }


}
