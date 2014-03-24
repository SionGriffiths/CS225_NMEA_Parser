/**
 * @file   gga_sentence.c
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  NMEA GGA sentence representation
 * 
 * Functions to extract GPS position and time data from an NMEA sentence.
 *  
 */

#include "linked_list.h"
#include "gga_sentence.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static float lat;
static float lng;
static float elevation;
static int time;

/**
 * Extracts gps position data from a tokenised NMEA GGA sentence.
 * 
 * Iterates through a linked list and extracts values from specific entries.
 * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
 */
void gga_set_latlong(list_ptr in_sentence) {

  

  char * lat_string;
  char * lng_string;
  char * elev_string;
  int lat_modifier = 1;
  int lng_modifier = 1;

  node_ptr iterator = get_head(&in_sentence);

  int i;
  for (i = 0; i < 10; i++) {
    if (i == 2) {
      lat_string = iterator->node_data;
    }
    if (i == 3) {
      if (strcmp(iterator->node_data, "S") == 0) {
        lat_modifier = -1;
      }
    }
    if (i == 4) {
      lng_string = iterator->node_data;
    }
    if (i == 5) {
      if (strcmp(iterator->node_data, "W") == 0) {
        lng_modifier = -1;
      }
    }
    if (i == 9) {
      elev_string = iterator->node_data;
    }
    if (iterator->next != NULL) {
      iterator = iterator->next;
    } else {
      break;
    }
  }

  lat = ((atof(lat_string)) * lat_modifier);
  lng = ((atof(lng_string)) * lng_modifier);
  elevation = atof(elev_string);



}

/**
 * Extracts time information from a tokenised NMEA GGA senetcne
 * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
 */
void gga_make_time(list_ptr in_sentence) {

  time = atoi(get_head(&in_sentence)->next->node_data);

}

/**
 * Creates a gga structure with data collected from other gga_sentence functions.
 * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
 * @return pointer to a gga_struct
 */
gga_ptr make_gga(list_ptr in_sentence) {
  gga_set_latlong(in_sentence);
  gga_make_time(in_sentence);

  gga_ptr ret_gga = calloc(1, sizeof (struct gga_struct));
  ret_gga->elev = elevation;
  ret_gga->time = time;
  ret_gga->lat = lat;
  ret_gga->lng = lng;

  return ret_gga;

}