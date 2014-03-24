/**
 * @file   RMC.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Extracts GPS information from an NMEA RMC sentence  
 */

#include "RMC.h"
#include <string>
#include <vector>
#include <cstdlib>

/**
 * Constructs an RMC
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
RMC::RMC(Stream *stream, vector<string> sentence) {
    makeRMCtime(stream, sentence);
}

RMC::RMC(const RMC& orig) {
}

RMC::~RMC() {
}

/**
 * Extracts latitude, longitude and elevation values from NMEA sentence.
 * Updates current Stream with these values
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
void RMC::makeRMCposition(Stream* stream, vector<string> sentence) {
    lat = atof(sentence[3].c_str());
    lng = atof(sentence[5].c_str());

    if ((sentence[4].compare("S")) == 0) {
        lat *= -1;
    }
    if ((sentence[6].compare("W")) == 0) {
        lng *= -1;
    }



    stream->setCurrentLatLong(lat, lng);

}

/**
 * Extracts time values from NMEA sentence.
 * Updates current Stream with these values
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
void RMC::makeRMCtime(Stream* stream, vector<string> sentence) {
    time = atoi(sentence[1].c_str());
    stream->setCurrentTime(time);
}