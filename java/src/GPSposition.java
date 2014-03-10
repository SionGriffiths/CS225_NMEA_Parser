import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:51
 */
public class GPSposition {

  private float lat;
  private float lng;
  private Calendar time;

  GPSposition(float lat, float lng, Calendar time){
    this.lat = lat;
    this.lng = lng;
    this.time = time;
  }


}
