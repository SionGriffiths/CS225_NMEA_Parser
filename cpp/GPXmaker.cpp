/**
 * @file   GPXmaker.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Facilitates creation of a formatted(GPX) XML file. 
 */

#include "GPXmaker.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Constructs a GPXmaker. Writes GPX formatted GPS fix information to file
 * @param gpsfixes vector of all GPS fixes
 */
GPXmaker::GPXmaker(vector<GPSfix> gpsfixes) {
    std::ofstream outputFile("cpp_output.gpx");
    outputFile << makeHeader();
    string output;
    for (unsigned i = 0; i < gpsfixes.size(); i++) {
        output = makeWPT(gpsfixes[i]);
        outputFile << output << "\n";

    }
    string footer = "</gpx>";
    outputFile << footer;

}


GPXmaker::GPXmaker(const GPXmaker& orig) {
}

GPXmaker::~GPXmaker() {
}

/**
 * Appends to a string GPS information from a single fix.
 * Fix information is wrapped in GPX format XML tags
 * @param gps a GPS fix
 * @return string containing the formatted information
 */
string GPXmaker::makeWPT(GPSfix gps) {
    string wpt;
    ostringstream lat;
    ostringstream lng;
    ostringstream elev;
    
    wpt.append("<wpt lat=\"");    
    lat.precision(7);
    lat << gps.getLat();
    wpt.append(lat.str());
    
    wpt.append("\" lon=\"");
    lng.precision(7);
    lng << gps.getLng();
    wpt.append(lng.str());
    wpt.append("\">\n");
    
    wpt.append("<ele>");
    elev << gps.getElev();
    wpt.append(elev.str());
    wpt.append("</ele>\n");
    
    wpt.append("</wpt>");
    
    return wpt;
}

/**
 * Appends file header information to string
 * @return string containing file header
 */
string GPXmaker::makeHeader() {
    string header;
    header.append("<?xml version=\"1.0\"?> \n");
    header.append("<gpx \n");
    header.append("version=\"1.0\" \n");
    header.append("creator=\"sig2GPS\" \n");
    header.append("xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" \n");
    header.append(" xmlns=\"http://www.topografix.com/GPX/1/0\" \n");
    header.append(" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/0 http://www.topografix.com/GPX/1/0/gpx.xsd\"> \n");

    return header;
}