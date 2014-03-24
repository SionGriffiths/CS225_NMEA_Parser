/* 
 * File:   main.h
 * Author: sig2
 *
 * Created on 20 March 2014, 20:02
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "gps_fix.h"
#include "sentence.h"
#include "linked_list.h"
#include "rmc_sentence.h"
#include "gga_sentence.h"
#include "gsv_sentence.h"
#include "stream.h"
#include "shared_temp_debug.h"
//static int count =0;



list_ptr parseSentence(sentence_ptr sentence_in);
void update(list_ptr sentence_tokens, stream_ptr stream);
void update_fix();
void calculate_offsets(stream_ptr s1, stream_ptr s2);
void make_new_fix(stream_ptr stream);
void sync_streams(stream_ptr s1, stream_ptr s2);
bool stream_has_data(stream_ptr stream);


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

