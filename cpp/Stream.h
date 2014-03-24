/**
 * @file   Stream.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Extracts GPS information from an NMEA RMC sentence  
 */

#ifndef STREAM_H
#define	STREAM_H
#include "FileParser.h"
#include "GPSfix.h"
#include <string>

class Stream {
public:

    enum fixQuality {
        NO_FIX, MIN_FIX, GOOD_FIX
    };
    fixQuality currentQuality;

    /**
     * Constructs a Stream. Instantiates a new FileParser instance
     * with a file containing stream data. Initialises default values.
     * @param fileName the filename of the stream file
     */
    Stream(string fileName);
    Stream(const Stream& orig);

    /**
     * Gets the next line from the stream file
     * @return string containing next line
     */
    virtual ~Stream();

    /**
     * Gets the next line from the stream file
     * @return string containing next line
     */
    string getNext() const;


    /**
     * Sets current latitude and longitude
     * @param lat latitude
     * @param lng longitude
     */
    void setCurrentLatLong(float lat, float lng);

    /**
     * Sets current elevation
     * @param elev elevation
     */
    void setCurrentElev(float elev);

    /**
     * Sets the current time
     * @param time time
     */
    void setCurrentTime(int time);

    /**
     * returns current latitude
     * @return current latitude
     */
    float getCurrentLat();

    /**
     * returns current longitude
     * @return current longitude
     */
    float getCurrentLng();

    /**
     * returns current elevation
     * @return the current elevation
     */
    float getCurrentElev();

    /**
     * Returns a boolean representing whether the stream has finished
     * @return true for finished false otherwise
     */
    bool isEndOfStream();

    /**
     * Sets whether the stream is finished
     * @param eos is stream finished - boolean
     */
    void setEndOfStream(bool eos);

    /**
     * returns current time
     * @return the current time
     */
    int getStreamTime();

    /**
     * Creates a GPSfix from current state of stream
     * @return the GPSfix
     */
    GPSfix makeGPSfix();
    /**
     * Updates the current lat/long offsets
     * @param latOffset latitude offset
     * @param lngOffset longitude offset
     */
    void updateLatLngOffsets(float latOffset, float lngOffset);

    /**
     * updates the current elevation offset
     * @param elevOffset elevation offset
     */
    void updateElevOffset(float elevOffset);

private:
    FileParser *fp;
    float currentLat;
    float currentLng;
    float currentElev;

    float latOffset;
    float lngOffset;
    float elevOffset;
    int time;
    bool endOfStream;

};

#endif	/* STREAM_H */

