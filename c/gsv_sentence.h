/**
 * @file   gsv_sentence.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  NMEA GSV sentence parser
 * 
 * Extracts SNR values from NMEA GSV sentences and returns an indication
 * of the current fix quality
 *  
 */
#ifndef GSV_SENTENCE_H
#define	GSV_SENTENCE_H
#include "linked_list.h"
#include "stream.h"
#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * Counts number of SNR values in a GSV sentence above certain limits.
     * Takes the first sentence of a GSV, counts the number of other sentences 
     * reads next sentences directly from file and tokenises them.
     * iterates through the 1-3 sentences in the list, counting SNR values.
     * @param in_sentence pointer to first tokenised sentence
     * @param pointer to the stream that generated the sentence
     * @return an integer representing the fix quality
     */
       int make_gsv(list_ptr in_sentence, stream_ptr stream);

#ifdef	__cplusplus
}
#endif

#endif	/* GSV_SENTENCE_H */

