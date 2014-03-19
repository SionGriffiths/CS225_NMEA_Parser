#include "linked_list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static float lat;
static float lng;
static float elevation;

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
    if(i == 3){
      if(strcmp(iterator->node_data, "S") == 0){
        lat_modifier = -1;
      }
    }
    if (i == 4) {
      lng_string = iterator->node_data;
    }
    if(i == 5){
      if(strcmp(iterator->node_data, "W") == 0){
        lng_modifier = -1;
      }
    }
    if(i == 9){
      elev_string = iterator->node_data;
    }
    if (iterator->next != NULL) {
      iterator = iterator->next;
    } else {
      break;
    }
  }
  
  lat = ((atof(lat_string)) * lat_modifier) / 100;
  lng = ((atof(lng_string)) * lng_modifier) / 100;
  elevation = atof(elev_string);
  
  
  
}