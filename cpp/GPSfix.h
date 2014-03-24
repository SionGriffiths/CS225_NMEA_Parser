/**
 * @file   GPSfix.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Represents a single GPS fix of a location  
 */


#ifndef GPSFIX_H
#define	GPSFIX_H
#include <iostream>

class GPSfix {
public:
    /**
     * Constructs a GPSfix
     * @param lat latitude
     * @param lng longitude
     * @param elev elevation
     */
    GPSfix(float lat, float lng, float elev);

    /**
     * Copy constructor. Makes a deep copy of GPSfix values.
     * @param orig the original instance of a GPSfix
     */
    GPSfix(const GPSfix& orig);
    virtual ~GPSfix();
    
    /**
     * returns the latitude
     * @return latitude
     */
    float getLat();
    /**
     * returns the longitude
     * @return the longitude
     */
    float getLng();
    /**
     * returns the elevation
     * @return the elevation
     */
    float getElev();

private:
    float lat;
    float lng;
    float elev;

    /**
     * Converts lat/longs from NMEA representation to a more standard format
     * @param nmea nmea representation to convert
     * @return the converted value
     */
    float convertNMEAdegrees(float nmea);
};

#endif	/* GPSFIX_H */

