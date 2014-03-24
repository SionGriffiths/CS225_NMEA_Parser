/**
 * @file   Stream.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Stream holds current stream status. Current position, time and Stream quality.
 */
#include <vector>

#include "Stream.h"

/**
 * Constructs a Stream. Instantiates a new FileParser instance
 * with a file containing stream data. Initialises default values.
 * @param fileName the filename of the stream file
 */
Stream::Stream(string fileName) {
    fp = new FileParser(fileName);
    endOfStream = false;
    currentQuality = GOOD_FIX;
}

Stream::Stream(const Stream& orig) {
}

/**
 * Destructor, delete FileParser pointer
 */
Stream::~Stream() {
    delete fp;
}

/**
 * Gets the next line from the stream file
 * @return string containing next line
 */
string Stream::getNext() const{
    string test = fp->readLine();    
    return test;
}

/**
 * Creates a GPSfix from current state of stream
 * @return the GPSfix
 */
GPSfix Stream::makeGPSfix(){
    currentLat += latOffset;
    currentLng += lngOffset;
    currentElev += elevOffset;
    
    return GPSfix(currentLat, currentLng, currentElev);
}




/**
 * Sets current latitude and longitude
 * @param lat latitude
 * @param lng longitude
 */
void Stream::setCurrentLatLong(float lat, float lng){
    currentLat = lat;
    currentLng = lng;
}

/**
 * Sets current elevation
 * @param elev elevation
 */
void Stream::setCurrentElev(float elev){
    currentElev = elev;
}

/**
 * returns current elevation
 * @return the current elevation
 */
float Stream::getCurrentElev(){
    return currentElev;
}

/**
 * Sets the current time
 * @param time time
 */
void Stream::setCurrentTime(int time){
    this->time = time;
}

/**
 * returns current time
 * @return the current time
 */
int Stream::getStreamTime(){
    return time;
}

/**
 * returns current latitude
 * @return current latitude
 */
float Stream::getCurrentLat(){
    return currentLat;
}

/**
 * returns current longitude
 * @return current longitude
 */
float Stream::getCurrentLng(){
    return currentLng;
}

/**
 * Returns a boolean representing whether the stream has finished
 * @return true for finished false otherwise
 */
bool Stream::isEndOfStream(){
    return endOfStream;
}

/**
 * Sets whether the stream is finished
 * @param eos is stream finished - boolean
 */
void Stream::setEndOfStream(bool eos){
    endOfStream = eos;
}

/**
 * Updates the current lat/long offsets
 * @param latOffset latitude offset
 * @param lngOffset longitude offset
 */
void Stream::updateLatLngOffsets(float latOffset, float lngOffset){
    this->latOffset = latOffset;
    this->lngOffset = lngOffset;
}

/**
 * updates the current elevation offset
 * @param elevOffset elevation offset
 */
void Stream::updateElevOffset(float elevOffset){
    this->elevOffset = elevOffset;
}


 
