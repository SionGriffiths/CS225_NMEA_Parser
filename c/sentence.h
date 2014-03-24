/**
 * @file   sentence.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2013
 * @brief  Defines the structure of an NMEA sentence
 *
 * Defines the structure of an NMEA sentence representation
 * Specifies functions to read and parse sentences from file. 
 */

#ifndef FILE_READER_H
#define	FILE_READER_H
#include "linked_list.h"
#include "stream.h"
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * A structure to represent an NMEA sentence
     */
    typedef struct sentence_Str {
        char sentenceData[120];
    } sentence;

    typedef sentence * sentence_ptr;


    /**
     * Function to read a single line from stream and create
     * a sentence struct
     * @param input_file pointer to stream
     * @return pointer to sentence struct
     */
    sentence_ptr read_sentence(stream_ptr stream);

    /**
     * Function to parse NMEA sentence strings 
     * @param sentence_in pointer to sentence stuct (sentence.h)
     * @return a linked list containing each token of sentence as separate
     * nodes (linked_list.h)
     */
    list_ptr parseSentence(sentence_ptr sentence_in);



#ifdef	__cplusplus
}
#endif

#endif	/* FILE_READER_H */

