/**
 * @file   GGA.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Extracts GPS information from an NMEA GGA sentence  
 */

#ifndef GGA_H
#define	GGA_H
#include <vector>
#include <string>
#include "Stream.h"

class GGA {
public:
    /**
     * Constructs a GGA
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    GGA(Stream *stream, vector<string> sentence);
    GGA(const GGA& orig);
    virtual ~GGA();

private:
    float lat;
    float lng;
    float elev;
    int time;

    /**
     * Extracts latitude, longitude and elevation values from NMEA sentence.
     * Updates current Stream with these values
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    void makeGGAposition(Stream *stream, vector<string> sentence);

    /**
     * Extracts time values from NMEA sentence.
     * Updates current Stream with these values
     * @param stream pointer to current Stream
     * @param sentence vector of NMEA sentence tokens
     */
    void makeGGAtime(Stream *stream, vector<string> sentence);

};

#endif	/* GGA_H */

