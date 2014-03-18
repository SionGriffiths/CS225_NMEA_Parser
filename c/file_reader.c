#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "file_reader.h"

static list_ptr stream_list;



sent_ptr read_sentence(FILE *input_file) {

  int read_status;
  sentence * in_sentence;

  in_sentence = calloc(1, sizeof (struct sentence_Str));


  read_status = fscanf(input_file, "%s",
          in_sentence->sentenceData);
  
  

  if (read_status == EOF) {
    return NULL;
  } else if (read_status != 1) {
    printf("Sentence data looks wrong or corrupt \n Read status returned %d", read_status);
    return NULL;
  } else {
    return in_sentence;
  }
}


//int make_stream_list(char *filename) {
//
//  FILE *file;
//  init_list(&stream_list);
//  sent_ptr in_sentence;
//
//  file = fopen(filename, "r");
//
//  if (file != NULL) {
//    int line_count = 0;
//    while ((in_sentence = read_sentence(file)) != NULL) {
//      node_ptr sentence_node;
//      init_node(&sentence_node, in_sentence);
//      add_to_list(&sentence_node, &stream_list);
//      line_count++;
//    }
//
//    printf("Read in %d sentences OK \n", line_count);
//    fclose(file);
//  } else {
//    printf("Could not read file \n");
//    return 0;
//  }
//  return 1;
//}

list_ptr get_sentence_list() {
  return stream_list;
}