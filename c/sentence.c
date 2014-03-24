
/**
 * @file   sentence.c
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2013
 * @brief  Defines the structure of an NMEA sentence
 *
 * Defines the structure of an NMEA sentence representation
 * Implements functions to read and parse sentences from file. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "linked_list.h"
#include "sentence.h"
#include "stream.h"
#include "shared_temp_debug.h"



/**
 * Function to read a single line from file and create
 * a sentence struct
 * @param input_file pointer to file
 * @return pointer to sentence struct
 */
sentence_ptr read_sentence(stream_ptr stream) {

  int read_status;
  sentence * in_sentence;

  in_sentence = calloc(1, sizeof (struct sentence_Str));


  read_status = fscanf(stream->stream_file, "%s",
          in_sentence->sentenceData);
  
  

  if (read_status == EOF) {
    stream->eof = true;
    return NULL;
  } else if (read_status != 1) {
    printf("Sentence data looks wrong or corrupt \n Read status returned %d", read_status);
    return NULL;
  } else {
    return in_sentence;
  }
}




/**
 * Function to parse  and tokenise NMEA sentence strings 
 * @param sentence_in pointer to sentence struct (sentence.h)
 * @return a linked list containing each token of sentence as separate
 * nodes (linked_list.h)
 */
list_ptr parseSentence(sentence_ptr sentence_in){
  char *data, *outTemp;
  data = sentence_in->sentenceData;
  
  list_ptr temp_list;
  init_list(&temp_list);
  
  while((outTemp = strsep(&data, ",*")) != NULL){
    node_ptr sentence_segment;
    init_node(&sentence_segment, outTemp);
    add_to_list(&sentence_segment, &temp_list);
    
  }
  line_count++;
  return temp_list;

}


