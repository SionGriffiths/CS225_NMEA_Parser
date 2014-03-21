/* 
 * File:   file_reader.h
 * Author: sig2
 *
 * Created on 18 March 2014, 13:25
 */

#ifndef FILE_READER_H
#define	FILE_READER_H
#include "linked_list.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct sentence_Str{
        char sentenceData[120];
    }sentence;

    typedef sentence * sent_ptr;

    
    sent_ptr read_sentence(FILE *input_file);
//    int make_stream_list(char *filename);
    list_ptr get_sentence_list();
    
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* FILE_READER_H */

