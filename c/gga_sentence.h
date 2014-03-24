/**
 * @file   gga_sentence.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  NMEA GGA sentence representation
 * 
 * Functions to extract GPS position and time data from an NMEA sentence.
 *  
 */
#ifndef GGA_SENTENCE_H
#define	GGA_SENTENCE_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * GGA data structure
     */
     struct gga_struct{
        float lat;
        float lng;
        float elev;
        int time;
        
    };
    
    typedef struct gga_struct * gga_ptr;
    
    /**
     * Extracts gps position data from a tokenised NMEA GGA sentence
     * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
     */
    void gga_set_latlong(list_ptr in_sentence);
    /**
     * Extracts time information from a tokenised NMEA GGA senetcne
     * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
     */
    void gga_make_time(list_ptr in_sentence);
    
    /**
     * Creates a gga structure with data collected from other gga_sentence functions.
     * @param in_sentence pointer to a linked list containing tokenised NMEA sentence
     * @return pointer to a gga_struct
     */
    gga_ptr make_gga(list_ptr in_sentence);

#ifdef	__cplusplus
}
#endif

#endif	/* GGA_SENTENCE_H */

