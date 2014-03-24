/**
 * @file   Controller.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Controller sets out the central sequence of operations for the system
 * 
 *  
 */

#include "Controller.h"
#include "FileParser.h"
#include "GGA.h"
#include "RMC.h"
#include "GSV.h"
#include "GPXmaker.h"
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

/**
 * Constructs a controller, instantiates Stream objects 
 * using stream data files
 */
Controller::Controller() {
    lastFixTime = 0;
    s1 = new Stream("gps_1.dat");
    s2 = new Stream("gps_2.dat");
}

Controller::Controller(const Controller& orig) {
}

/**
 * Destructor, deletes Stream pointers
 */
Controller::~Controller() {
    delete s1;
    delete s2;
}

/**
 * Run method is the point of entry to the system.
 */
void Controller::run() {

    while (!s1->isEndOfStream()) {
        syncStreams(s1, s2);
    }
    cout << gpsfixes.size();
    new GPXmaker(gpsfixes);
}

/**
 * Tokenises the next sentence passed through Stream
 * from file. Creates a specific sentence type object
 * and passes through the tokenised sentence as vector
 * @param stream pointer to Stream
 */
void Controller::parseSentence(Stream *stream) {

    string input;
    if ((input = stream->getNext()).empty()) {
        stream->setEndOfStream(true);
        return;
    } else {

        vector<string> sentence = split(input);

        string type = sentence[0];
        if ((type.compare("$GPGGA")) == 0) {
            GGA(stream, sentence);
        } else if ((type.compare("$GPRMC")) == 0) {
            RMC(stream, sentence);
        } else if ((type.compare("$GPGSV")) == 0) {
            GSV(stream, sentence);
        }
    }
}

/**
 * Splits a comma separated sentence, returns sentence as 
 * a vector of tokenised string
 * @param s input string 
 * @return vector of tokens
 */
vector<string> Controller::split(const string &s) {

    vector <string> sentenceTokens;
    stringstream ss(s);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');

        sentenceTokens.push_back(substr);
    }
    return sentenceTokens;
}

/**
 * Calculates the offset between 2 Streams and applies offset to values
 * in the second Stream
 * @param s1 pointer to first Stream
 * @param s2 pointer to second Stream
 */
void Controller::calculateOffsets(Stream* s1, Stream* s2) {
    float latOffset = s1->getCurrentLat() - s2->getCurrentLat();
    float lngOffset = s1->getCurrentLng() - s2->getCurrentLng();
    float elevOffset = s1->getCurrentElev() - s2->getCurrentElev();

    s2->updateLatLngOffsets(latOffset, lngOffset);
    s2->updateElevOffset(elevOffset);
}

/**
 * Synchronises the parsing of sentences from 2 Streams
 * using the current Stream times.
 * @param s1 pointer to first Stream
 * @param s2 pointer to second Stream
 */
void Controller::syncStreams(Stream *s1, Stream *s2) {

    bool synced = false;


    while (synced == false) {
        checkForNewFix();

        if (s1->getStreamTime() < (s2->getStreamTime())) {
            parseSentence(s1);
            synced = false;

        } else if (s1->getStreamTime() > (s2->getStreamTime())) {
            parseSentence(s2);
            synced = false;

        } else {

            calculateOffsets(s1, s2);
            parseSentence(s1);
            parseSentence(s2);
            synced = true;

        }
    }
}

/**
 * Checks if current state of streams is good enough
 * to make a new fix. Biased to Stream 1
 */
void Controller::checkForNewFix() {

    if (s1->currentQuality == s1->GOOD_FIX) {
        makeGPSfix(s1);

    } else if (s2->currentQuality == s2->GOOD_FIX) {
        makeGPSfix(s2);

    } else {
        if (s1->currentQuality == s1->MIN_FIX) {
            makeGPSfix(s1);

        } else if (s2->currentQuality == s2->MIN_FIX) {
            makeGPSfix(s2);

        }
    }
}

/**
 * Makes a new GPSfix from current stream state
 * @param stream pointer to Stream
 */
void Controller::makeGPSfix(Stream *stream) {
    if ((lastFixTime == 0) || (stream->getStreamTime() > lastFixTime)) {
        if(streamHasData(stream)){
            gpsfixes.push_back(stream->makeGPSfix());
            lastFixTime = stream->getStreamTime();
        }
    }
}

/**
 * Checks that a stream has sufficient data to make a fix
 * @param stream pointer to Stream
 * @return true if enough data, false otherwise.
 */
bool Controller::streamHasData(Stream *stream) {
    float elev = stream->getCurrentElev();
    float lat = stream->getCurrentLat();
    float lng = stream->getCurrentLng();

    return (lng != 0 && lat != 0 && elev != 0);
}