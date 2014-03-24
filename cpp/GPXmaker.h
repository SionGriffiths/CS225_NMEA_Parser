/**
 * @file   GPXmaker.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Facilitates creation of a formatted(GPX) XML file. 
 */

#ifndef GPXMAKER_H
#define	GPXMAKER_H
#include "GPSfix.h"
#include <vector>
#include <string>
using namespace std;

class GPXmaker {
public:
    /**
     * Constructs a GPXmaker. Writes GPX formatted GPS fix information to file
     * @param gpsfixes vector of all GPS fixes
     */
    GPXmaker(vector<GPSfix> gpsfixes);
    GPXmaker(const GPXmaker& orig);
    virtual ~GPXmaker();
private:

    /**
     * Appends to a string GPS information from a single fix.
     * Fix information is wrapped in GPX format XML tags
     * @param gps a GPS fix
     * @return string containing the formatted information
     */
    string makeWPT(GPSfix gps);

    /**
     * Appends file header information to string
     * @return string containing file header
     */
    string makeHeader();
};

#endif	/* GPXMAKER_H */

