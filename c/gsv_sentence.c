
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_temp_debug.h"
#include "linked_list.h"
#include "sentence.h"
#include "gsv_sentence.h"

int make_gsv(list_ptr in_sentence, FILE * file) {

  //Get the number of GSV lines from second token in the sentence
  int num_lines = atoi(get_head(&in_sentence)->next->node_data);
  int good_snr_count = 0;
  int min_snr_count = 0;

  //Make a list to hold GSVs, up to 3
  list_ptr gsv_lines;
  init_list(&gsv_lines);
  
  //passed in sentence tokens added to GSV list
  node_ptr original_line;
  init_node(&original_line, in_sentence);
  add_to_list(&original_line, &gsv_lines);

  //Add the other gsv lines to the list
  int i;
  for (i = 1; i < num_lines; i++) {
    node_ptr gsv_line;
    init_node(&gsv_line, parseSentence(read_sentence(file)));
    add_to_list(&gsv_line, &gsv_lines);
    line_count++;
  }


  //Iterator for the GSV lines
  node_ptr gsv_iterator = get_head(&gsv_lines);
  
  //Iterator for sentence tokens in the GSV lines
  node_ptr sentence_token;
  while (gsv_iterator != NULL) {

    int tokencount = 0; //track number of tokens encountered
    int snr_value_token = 7; // first SNR in a line is 7th token

    //get first token in sentence
    sentence_token = get_head((list_ptr *) & gsv_iterator->node_data); 

    while (sentence_token != NULL) {

      if (tokencount == snr_value_token) {

        if (!(strcmp(sentence_token->node_data, "") == 0)) {
          int snr = atoi(sentence_token->node_data);

          if (snr >= 35) {
            good_snr_count++;
          }
          if ((snr >= 30) && (snr < 35)) {
            min_snr_count++;
          }

        }

        snr_value_token += 4; //next SNR in line : every 4 tokens
      }


      sentence_token = sentence_token->next;
      tokencount++;
    }
    gsv_iterator = gsv_iterator -> next;
  }


  if (good_snr_count >= 3) {
    return 2;
  } else if (min_snr_count >= 3) {
    return 1;
  } else {
    return 0;
  }

}

