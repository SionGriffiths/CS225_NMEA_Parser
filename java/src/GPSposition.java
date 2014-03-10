
/**
 * @author Siôn Griffiths - sig2@aber.ac.uk
 *         Date: 09/03/14
 *         Time: 12:51
 */
public class GPSposition {

  private float lat;
  private float lng;
  private float elevation;
  private int time;
  private int date;

  public GPSposition(int time, float lat, float lng ){
    this.time = time;
    this.lat = lat;
    this.lng = lng;

  }

  public String toString(){
    return time +" " + lat + " " + lng;
  }

  public float getLat() {
    return lat;
  }

  public void setLat(float lat) {
    this.lat = lat;
  }

  public float getLng() {
    return lng;
  }

  public void setLng(float lng) {
    this.lng = lng;
  }

  public float getElevation() {
    return elevation;
  }

  public void setElevation(float elevation) {
    this.elevation = elevation;
  }

  public int getTime() {
    return time;
  }

  public void setTime(int time) {
    this.time = time;
  }

  public int getDate() {
    return date;
  }

  public void setDate(int date) {
    this.date = date;
  }



}
