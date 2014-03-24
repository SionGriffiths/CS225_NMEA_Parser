/**
 * @file   rmc_sentence.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  NMEA RMC sentence representation
 * 
 * Functions to extract GPS position and  time data from an NMEA sentence.
 *  
 */

#ifndef RMC_SENTENCE_H
#define	RMC_SENTENCE_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct rmc_struct {
        float lat;
        float lng;
        int time;
        int date;
    };

    typedef struct rmc_struct * rmc_ptr;

    /**
     * Function iterates through a tokenised NMEA RMC sentence 
     * and extracts gps positioning
     * @param in_sentence pointer to linked list of sentence tokens
     */
    void rmc_set_latlong(list_ptr in_sentence);
    /**
     * Function extracts time/date from parameter sentence
     * @param in_sentence pointer to tokenised sentence
     */
    void rmc_make_time(list_ptr in_sentence);

    /**
     * Creates an rmc struct containing fix data - gps coordinates
     * and time stamp.
     * @param in_sentence pointer to tokenised sentece
     * @return pointer to an rmc struct
     */
    rmc_ptr make_rmc(list_ptr in_sentence);


#ifdef	__cplusplus
}
#endif

#endif	/* RMC_SENTENCE_H */

