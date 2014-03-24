/**
 * @file   gps_fix.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Holds GPS position data and provides XML formatted output 
 */

#ifndef GPS_FIX_H
#define	GPS_FIX_H
#include "stream.h"
#include "linked_list.h"
#include <math.h>
#ifdef	__cplusplus
extern "C" {
#endif

    /**
     *GPS data struct.
     */
    struct gps_fix {
        float lat;
        float lng;
        float elev;
        int time;
    };

    typedef struct gps_fix * gps_ptr;

    /**
     * Makes a gps fix from data based on the current status of a stream
     * @param stream pointer to the data stream
     * @return pointer to gps_fix struct
     */
    gps_ptr make_gps(stream_ptr stream);
    
    /**
     * Outputs data from all gps fixes formatted in GPX xml tags.
     * @param gps_fixes pointer to the list of gps fixes
     */
    void make_gpx(list_ptr gps_fixes);
    /**
     * Prints XML header to file 
     */
    void make_gpx_header();
    /**
     * Finds highest and lowest values for lat/long in the list of gps fixes
     * Prints out to file in formatted xml
     * @param gps_fixes pointer to list of all gps fixes
     */
    void set_bounds(list_ptr gps_fixes);
    /**
     * Converts lat/longs from NMEA representation to a more standard format
     * @param nmea nmea representation to convert
     * @return the converted value
     */
    float convert_nmea_degrees(float nmea);
#ifdef	__cplusplus
}
#endif

#endif	/* GPS_FIX_H */

