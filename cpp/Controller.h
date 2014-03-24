/**
 * @file   Controller.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  Controller sets out the central sequence of operations for the system
 * 
 *  
 */
#ifndef CONTROLLER_H
#define	CONTROLLER_H
#include "Stream.h"
#include "GPSfix.h"
#include <vector>
#include "FileParser.h"
using namespace std;

class Controller {
public:

    /**
     * Constructs a controller, instantiates Stream objects 
     * using stream data files
     */
    Controller();
    Controller(const Controller& orig);

    /**
     * Destructor, deletes Stream pointers
     */
    virtual ~Controller();

    /**
     * Run method is the point of entry to the system.
     */
    void run();

    /**
     * Tokenises the next sentence passed through Stream
     * from file. Creates a specific sentence type object
     * and passes through the tokenised sentence as vector
     * @param stream pointer to Stream
     */
    void parseSentence(Stream *stream);

    /**
     * Splits a comma separated sentence, returns sentence as 
     * a vector of tokenised string
     * @param s input string 
     * @return vector of tokens
     */
    static vector<string> split(const string &s);

private:

    Stream *s1;
    Stream *s2;
    vector <GPSfix> gpsfixes;
    int lastFixTime; 
    
    
    /**
     * Makes a new GPSfix from current stream state
     * @param stream pointer to Stream
     */
    void makeGPSfix(Stream *stream);

    /**
     * Synchronises the parsing of sentences from 2 Streams
     * using the current Stream times.
     * @param s1 pointer to first Stream
     * @param s2 pointer to second Stream
     */
    void syncStreams(Stream *s1, Stream *s2);

    /**
     * Checks if current state of streams is good enough
     * to make a new fix. Biased to Stream 1
     */
    void checkForNewFix();

    /**
     * Calculates the offset between 2 Streams and applies offset to values
     * in the second Stream
     * @param s1 pointer to first Stream
     * @param s2 pointer to second Stream
     */
    void calculateOffsets(Stream *s1, Stream *s2);

    /**
     * Checks that a stream has sufficient data to make a fix
     * @param stream pointer to Stream
     * @return true if enough data, false otherwise.
     */
    bool streamHasData(Stream *stream);
};

#endif	/* CONTROLLER_H */

