/* 
 * File:   main.c
 * Author: sig2
 *
 * Created on 18 March 2014, 13:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sentence.h"
#include "linked_list.h"
#include "rmc_sentence.h"
#include "gga_sentence.h"
#include "gsv_sentence.h"
#include "shared_temp_debug.h"
//static int count =0;


//Ints to represent steam quality, assume good until first GSV parsed
static int stream1_quality = 2;
static int stream2_quality = 2;
static FILE *gps_1;
static FILE *gps_2;

list_ptr parseSentence(sentence_ptr sentence_in);
void update(list_ptr sentence_tokens, FILE * gps_file);

int line_count = 0;

int main(int argc, char** argv) {

  gps_1 = fopen("gps_1.dat", "r");
  gps_2 = fopen("gps_2.dat", "r");
  list_ptr gps_list;


  if (gps_1 == NULL || gps_2 == NULL) {
    printf("Missing stream file. Aborting.");
    return (EXIT_FAILURE);
  }


  sentence_ptr sentence_in;
  while (((sentence_in = read_sentence(gps_2))) != NULL) {
    update(parseSentence(sentence_in), gps_2);
    line_count++;
  }
  

  fclose(gps_1);
  fclose(gps_2);
  printf("%d", line_count);
  return (EXIT_SUCCESS);
}




void update(list_ptr sentence_tokens, FILE * gps_file) {

  char * type = get_head(&sentence_tokens)->node_data;
  
  if ((strcmp(type, "$GPGSV") == 0)) {
    int quality = make_gsv(sentence_tokens, gps_file);
    if(gps_file == gps_1){
      stream1_quality = quality;
    }if(gps_file == gps_2){
      stream2_quality = quality;
    }

  } else if ((strcmp(type, "$GPGGA") == 0)) {
    gga_set_latlong(sentence_tokens);

  } else if (((strcmp(type, "$GPRMC") == 0))) {
    rmc_set_latlong(sentence_tokens);
  }
}




//  list_ptr temp;
//  sentence_in = read_sentence(gps_1);
//  temp = parseSentence(sentence_in);
//
//
//  node_ptr iterator = get_head(&temp);
//  if (strcmp(iterator->node_data, "$GPGSA") == 0) {
//    printf("willies \n");
//  }
//
//
//  while (iterator != NULL) {
//    printf("%s ", (char*) iterator->node_data);
//    iterator = iterator -> next;
//  }


//node_ptr iterator = get_head(&sentence_tokens);
//    if (strcmp(iterator->node_data, "$GPGSA") == 0) {
//      printf("willies \n");
//    }
//
//    int count = 0;
//    while (iterator != NULL) {
//      printf("%d %s \n", count, (char*) iterator->node_data);
//      iterator = iterator -> next;
//      count++;
//    }

