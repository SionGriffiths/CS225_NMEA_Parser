/**
 * @file   GPSfix.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Represents a single GPS fix of a location  
 */

#include "GPSfix.h"
#include <iostream>

/**
 * Constructs a GPSfix
 * @param lat latitude
 * @param lng longitude
 * @param elev elevation
 */
GPSfix::GPSfix(float lat, float lng, float elev) {

    this->lat = convertNMEAdegrees(lat);

    this->lng = convertNMEAdegrees(lng);
    this->elev = elev;
}

/**
 * Copy constructor. Makes a deep copy of GPSfix values.
 * @param orig the original instance of a GPSfix
 */
GPSfix::GPSfix(const GPSfix& orig) {
    lat = (orig.lat);
    lng = (orig.lng);
    elev = (orig.elev);
}

GPSfix::~GPSfix() {
}

/**
 * Converts lat/longs from NMEA representation to a more standard format
 * @param nmea nmea representation to convert
 * @return the converted value
 */
float GPSfix::convertNMEAdegrees(float nmea) {
    int D = (int) (nmea / 100);
    float m = nmea - (D * 100);
    return D + (m / 60);
}

/**
 * returns the latitude
 * @return latitude
 */
float GPSfix::getLat() {
    return lat;
}

/**
 * returns the longitude
 * @return the longitude
 */
float GPSfix::getLng() {
    return lng;
}

/**
 * returns the elevation
 * @return the elevation
 */
float GPSfix::getElev() {
    return elev;
}