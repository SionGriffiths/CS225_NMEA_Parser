
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_temp_debug.h"
#include "linked_list.h"
#include "sentence.h"
#include "gsv_sentence.h"

void make_gsv(list_ptr in_sentence, FILE * file) {

  int num_lines = atoi(get_head(&in_sentence)->next->node_data);
  //  int good_snr_count = 0;
  //  int minS_snr_count = 0;

  list_ptr gsv_lines;
  init_list(&gsv_lines);
  
  node_ptr original_line;
  init_node(&original_line, &in_sentence);
  
  int i;
  for(i = 1; i < num_lines; i++){
    node_ptr gsv_line;
    init_node(&gsv_line, parseSentence(read_sentence(file)));
    add_to_list(&gsv_line, &gsv_lines);
 line_count++;
  }
  
  
  




  printf("%d \n", num_lines);

}

//list_ptr extra_gsv_lines;
//  init_list(&extra_gsv_lines);
// int i;
//  for(i = 1; i < num_lines; i++){
//    node_ptr gsv_line;
//    init_node(&gsv_line, read_sentence(file));
//    add_to_list(&gsv_line, &extra_gsv_lines);
//  }
//  
//  list_ptr line_2 = NULL;
//  list_ptr line_3 = NULL;
//  
//  if(num_lines > 1){
//    line_2 = parseSentence(get_head(&extra_gsv_lines)->node_data);
//  }
//  if(num_lines > 2){
//    line_3 = parseSentence(get_head(&extra_gsv_lines)->next->node_data);
//  }
//  

//gsv_list * gsv_line1;
//  gsv_list * gsv_line2;
//  gsv_list * gsv_line3;
//  
//  gsv_line1 = calloc(1, sizeof (struct gsv_list_struct));
//  gsv_line2 = calloc(1, sizeof (struct gsv_list_struct));  
//  gsv_line3 = calloc(1, sizeof (struct gsv_list_struct));
//  
//  
//  gsv_line1->gsv_line = in_sentence;
//  
//  if (num_lines > 1) {
//    gsv_line2->gsv_line = parseSentence(read_sentence(file));
//  }
//  if (num_lines > 2) {
//    gsv_line3->gsv_line = parseSentence(read_sentence(file));
//  }
//
//  gsv_list * iterator = gsv_line1;