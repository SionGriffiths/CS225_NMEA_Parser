/**
 * @file   GGA.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Extracts GPS information from an NMEA GGA sentence  
 */
#include "Stream.h"
#include "GGA.h"

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * Constructs a GGA
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
GGA::GGA( Stream *stream, vector<string> sentence) {
    makeGGAposition(stream, sentence);
    makeGGAtime(stream, sentence);
}

GGA::GGA(const GGA& orig) {
}

GGA::~GGA() {
}

/**
 * Extracts latitude, longitude and elevation values from NMEA sentence.
 * Updates current Stream with these values
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
void GGA::makeGGAposition(Stream *stream, vector<string> sentence) {
    lat = atof(sentence[2].c_str());
    lng = atof(sentence[4].c_str());
    elev = atof(sentence[9].c_str());
    
    if((sentence[3].compare("S")) == 0){
        lat *= -1;
    }
    if((sentence[5].compare("W")) == 0){
        lng *= -1;
    }
    

    
    stream->setCurrentLatLong(lat, lng);
    stream->setCurrentElev(elev);
}

/**
 * Extracts time values from NMEA sentence.
 * Updates current Stream with these values
 * @param stream pointer to current Stream
 * @param sentence vector of NMEA sentence tokens
 */
void GGA::makeGGAtime(Stream *stream, vector<string> sentence) {
    time = atoi(sentence[1].c_str());
    stream->setCurrentTime(time);
}