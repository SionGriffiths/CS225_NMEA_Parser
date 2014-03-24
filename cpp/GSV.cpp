/**
 * @file   GSV.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  GSV represents a GSV NMEA sentence. Extracts SNR/signal quality from GSV sentence
 */

#include "GSV.h"
#include "Controller.h"
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Stream.h"

/**
 * Constructs a GSV.
 * @param stream pointer to Stream containing GSV sentence
 * @param sentence vector of tokenised NMEA sentence
 */
GSV::GSV(Stream *stream, vector<string> sentence) {
    updateStreamQuality(stream, sentence);
}

GSV::GSV(const GSV& orig) {
}

GSV::~GSV() {
}

/**
 * Counts number of SNR values in a GSV sentence above certain limits.
 * Takes the first sentence of a GSV, counts the number of other sentences 
 * reads next sentences directly from file and tokenises them.
 * iterates through the 1-3 sentences in the list, counting SNR values.
 * Sets stream quality Enum based on these SNR counts.
 * @param stream pointer to Stream containing GSV sentence
 * @param sentence vector of tokenised NMEA sentence
 */
void GSV::updateStreamQuality(Stream* stream, vector<string> sentence) {
    int goodSNRcount = 0;
    int minSNRcount = 0;
    int numlines = atoi(sentence[1].c_str());
    vector<vector<string> > gsvLines;
    gsvLines.push_back(sentence);

    for (int i = 1; i < numlines; i++) {
        vector<string> line = Controller::split(stream->getNext());
        gsvLines.push_back(line);
    }


    for (unsigned k = 0; k < gsvLines.size(); k++) {
        vector<string> gsv = gsvLines[k];
        for (unsigned i = 7; i < gsv.size(); i += 4) {
            int snr = 0;
            if (i == gsv.size() - 1) { //deal with the * next to the last snr value in a gsv line.
                stringstream ss(gsv[i]);
                string substr;
                getline(ss, substr, '*');
                snr = atoi(substr.c_str());
            } else {
                snr = atoi(gsv[i].c_str());
            }
            if (snr >= 35) {
                goodSNRcount++;
            } else if (snr >= 30) {
                minSNRcount++;
            }


        }
    }


    if (goodSNRcount >= 3) {
        stream->currentQuality = stream->GOOD_FIX;
    } else if (goodSNRcount + minSNRcount >= 3) {
        stream->currentQuality = stream->MIN_FIX;
    } else {
        stream->currentQuality = stream->NO_FIX;
    }

}