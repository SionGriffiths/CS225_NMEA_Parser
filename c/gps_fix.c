/**
 * @file   gps_fix.c
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Holds GPS position data and provides XML formatted output 
 */

#include "gps_fix.h"
#include "linked_list.h"
#include "stream.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Output file pointer.
 */
static FILE * gpx_file;

/**
 * Makes a gps fix from data based on the current status of a stream
 * @param stream pointer to the data stream
 * @return pointer to gps_fix struct
 */
gps_ptr make_gps(stream_ptr stream) {
  gps_ptr gps = calloc(1, sizeof (struct gps_fix));

  gps->lat = convert_nmea_degrees(stream->current_lat);
  gps->lng = convert_nmea_degrees(stream->current_lng);
  gps->elev = stream->current_elev;
  gps->time = stream->stream_time;

  return gps;
}

/**
 * Outputs data from all gps fixes formatted in GPX xml tags.
 * @param gps_fixes pointer to the list of gps fixes
 */
void make_gpx(list_ptr gps_fixes) {
  gpx_file = fopen("c_output.gpx", "w");

  if (gpx_file == NULL) {
    printf("Error finding gpx file - c_output.gpx");
  }
  make_gpx_header();
  set_bounds(gps_fixes);
  node_ptr iterator = get_head(&gps_fixes);

  while (iterator != NULL) {
    gps_ptr gps = iterator->node_data;
    fprintf(gpx_file, "<wpt lat=\"%f\" lon=\"%f\">\n", gps->lat, gps->lng);
    fprintf(gpx_file, "<ele>%f</ele>\n </wpt> \n", gps->elev);
    iterator = iterator->next;
  }
  fprintf(gpx_file, "</gpx>");
  fclose(gpx_file);
}

/**
 * Prints XML header to file 
 */
void make_gpx_header() {
  fprintf(gpx_file, "<?xml version=\"1.0\"?> \n");
  fprintf(gpx_file, "<gpx \n");
  fprintf(gpx_file, "version=\"1.0\" \n");
  fprintf(gpx_file, "creator=\"sig2GPS\" \n");
  fprintf(gpx_file, "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" \n");
  fprintf(gpx_file, " xmlns=\"http://www.topografix.com/GPX/1/0\" \n");
  fprintf(gpx_file, " xsi:schemaLocation=\"http://www.topografix.com/GPX/1/0 http://www.topografix.com/GPX/1/0/gpx.xsd\"> \n");
}

/**
 * Finds highest and lowest values for lat/long in the list of gps fixes
 * Prints out to file in formatted xml
 * @param gps_fixes pointer to list of all gps fixes
 */
void set_bounds(list_ptr gps_fixes) {
  float minlat = 91;
  float minlng = 181;
  float maxlat = -91;
  float maxlng = -181;

  node_ptr iterator = get_head(&gps_fixes);

  while (iterator != NULL) {
    gps_ptr gps = iterator->node_data;

    if (minlat > gps->lat) {
      minlat = gps->lat;
    }
    if (minlng > gps->lng) {
      minlng = gps->lng;
    }
    if (maxlat < gps->lat) {
      maxlat = gps->lat;
    }
    if (maxlng < gps->lng) {
      maxlng = gps->lng;
    }

    iterator = iterator->next;
  }

  fprintf(gpx_file, "<bounds minlat=\"%f\" minlon=\"%f\" maxlat=\"%f\" maxlon=\"%f\"/>\n", minlat, minlng, maxlat, maxlng);
}

/**
 * Converts lat/longs from NMEA representation to a more standard format
 * @param nmea nmea representation to convert
 * @return the converted value
 */
float convert_nmea_degrees(float nmea) {
  int D = (int) (nmea / 100);
  float m = nmea - (D * 100);
  return D + (m / 60);
}