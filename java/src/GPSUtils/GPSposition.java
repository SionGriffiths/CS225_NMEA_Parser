package GPSUtils;

import java.util.Calendar;

/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:51
 */
public class GPSposition {

  private float lat;
  private float lng;
  private float elevation;
  private Calendar time;

  public GPSposition(float lat, float lng, float elevation, Calendar time ){

    this.lat = lat;
    this.lng = lng;
    this.elevation = elevation;
    this.time = time;
  }

  public String toString(){
    return time.getTime()+  ", " + lat + ", " + lng + ", " + elevation;
  }
}
