/* 
 * File:   rmc_sentence.h
 * Author: sig2
 *
 * Created on 19 March 2014, 12:17
 */

#ifndef RMC_SENTENCE_H
#define	RMC_SENTENCE_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * Function iterates through a tokenised NMEA RMC sentence 
     * and extracts gps positioning
     * @param in_sentence pointer to linked list of sentence tokens
     */
    void rmc_set_latlong(list_ptr in_sentence);


#ifdef	__cplusplus
}
#endif

#endif	/* RMC_SENTENCE_H */

