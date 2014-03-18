/* 
 * File:   main.c
 * Author: sig2
 *
 * Created on 18 March 2014, 13:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"

/*
 * 
 */

void parseSentence(sent_ptr sentence_in);

int main(int argc, char** argv) {

    FILE *gps_1 = fopen("gps_1.dat", "r");
    FILE *gps_2 = fopen("gps_2.dat", "r");
    
    if(gps_1 == NULL || gps_2 == NULL){
      printf("Missing stream file. Aborting.");
      return (1);
    }
    
//    int count1 = 0;
//    int count2 = 0;
    sent_ptr sentence_in;
    while (((sentence_in = read_sentence(gps_1))) != NULL){
//      count1++;
      parseSentence(sentence_in);
    }
//    while ((read_sentence(gps_2)) != NULL){
//      count2++;
//    }
    
//    printf("Lines in file1 : %d \nLines in file2 : %d", count1, count2);
    
//    while (make_stream_list("gps_1.dat") == 0);
//    while (make_stream_list("gps_2.dat") == 0);
  
    fclose(gps_1);
    fclose(gps_2);
  
    return (EXIT_SUCCESS);
}

void parseSentence(sent_ptr sentence_in){
  char *data, *outTemp;
  data = sentence_in->sentenceData;
  
  while((outTemp = strsep(&data, ",*")) != NULL){
    printf("%s | ", outTemp);
  }
  printf("\n");
  
//  return strsep(&data, ",");
}