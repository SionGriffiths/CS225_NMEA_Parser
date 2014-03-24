/**
 * @file   rmc_sentence.c
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  NMEA RMC sentence representation
 * 
 * Functions to extract GPS position and  time data from an NMEA sentence.
 *  
 */
#include "linked_list.h"
#include "rmc_sentence.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
static float lat;
static float lng;
static int time;
static int date;

/**
 * Function iterates through a tokenised NMEA RMC sentence 
 * and extracts gps positioning
 * @param in_sentence pointer to linked list of sentence tokens
 */
void rmc_set_latlong(list_ptr in_sentence) {


  char * lat_string;
  char * lng_string;
  int lat_modifier = 1;
  int lng_modifier = 1;

  node_ptr iterator = get_head(&in_sentence);
  
  int i;
  for (i = 0; i < 9; i++) {
    if (i == 3) {
      lat_string = iterator->node_data;
    }
    if(i == 4){
      if(strcmp(iterator->node_data, "S") == 0){
        lat_modifier = -1;
      }
    }
    if (i == 5) {
      lng_string = iterator->node_data;
    }
    if(i == 6){
      if(strcmp(iterator->node_data, "W") == 0){
        lng_modifier = -1;
      }
    }
    if (iterator->next != NULL) {
      iterator = iterator->next;
    } else {
      break;
    }
  }
  
  lat = ((atof(lat_string)) * lat_modifier);
  lng = ((atof(lng_string)) * lng_modifier);

  
}
/**
 * Function extracts time/date from parameter sentence
 * @param in_sentence pointer to tokenised sentence
 */
void rmc_make_time(list_ptr in_sentence){
  node_ptr iterator = get_head(&in_sentence);  
  int i;
  for (i = 0; i < 10; i++) {
    
    if(i == 1){
      time = atoi(iterator->node_data);
    }
    if(i == 9){
      date = atoi(iterator->node_data);
    }
    
    if (iterator->next != NULL) {
      iterator = iterator->next;
    } else {
      break;
    }
  }  
}
/**
 * Creates an rmc struct containing fix data - gps coordinates
 * and time stamp.
 * @param in_sentence pointer to tokenised sentece
 * @return pointer to an rmc struct
 */
rmc_ptr make_rmc(list_ptr in_sentence){
  rmc_set_latlong(in_sentence);
  rmc_make_time(in_sentence);
  
  rmc_ptr ret_rmc = calloc(1, sizeof (struct rmc_struct));
  ret_rmc->date = date;
  ret_rmc->time = time;
  ret_rmc->lat = lat;
  ret_rmc->lng = lng;
  
  return ret_rmc;  
  
}