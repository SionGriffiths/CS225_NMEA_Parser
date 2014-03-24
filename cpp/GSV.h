/**
 * @file   GSV.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  GSV represents a GSV NMEA sentence. Extracts SNR/signal quality from GSV sentence
 */

#ifndef GSV_H
#define	GSV_H
#include <vector>
#include <string>
#include "Stream.h"

class GSV {
public:
    /**
     * Constructs a GSV.
     * @param stream pointer to Stream containing GSV sentence
     * @param sentence vector of tokenised NMEA sentence
     */
    GSV(Stream *stream, vector<string> sentence);
    GSV(const GSV& orig);
    virtual ~GSV();
private:

    /**
     * Counts number of SNR values in a GSV sentence above certain limits.
     * Takes the first sentence of a GSV, counts the number of other sentences 
     * reads next sentences directly from file and tokenises them.
     * iterates through the 1-3 sentences in the list, counting SNR values.
     * Sets stream quality Enum based on these SNR counts.
     * @param stream pointer to Stream containing GSV sentence
     * @param sentence vector of tokenised NMEA sentence
     */
    void updateStreamQuality(Stream *stream, vector<string> sentence);
};

#endif	/* GSV_H */

