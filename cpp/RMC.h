/**
 * @file   RMC.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Extracts GPS information from an NMEA RMC sentence  
 */


#ifndef RMC_H
#define	RMC_H
#include <vector>
#include <string>
#include "Stream.h"

class RMC {
public:

    /**
     * Constructs an RMC
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    RMC(Stream *stream, vector<string> sentence);
    RMC(const RMC& orig);
    virtual ~RMC();
private:
    float lat;
    float lng;
    int time;

    /**
     * Extracts latitude, longitude and elevation values from NMEA sentence.
     * Updates current Stream with these values
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    void makeRMCposition(Stream *stream, vector<string> sentence);

    /**
     * Extracts time values from NMEA sentence.
     * Updates current Stream with these values
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    void makeRMCtime(Stream *stream, vector<string> sentence);
};

#endif	/* RMC_H */

