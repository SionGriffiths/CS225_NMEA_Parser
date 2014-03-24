
/**
 * @file   stream.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2013
 * @brief  Holds current data representing the state of a stream of NMEA sentences
 */

#ifndef STREAM_H
#define	STREAM_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifdef	__cplusplus
extern "C" {
#endif

    struct stream_struct {
        FILE * stream_file;
        int stream_quality;
        int stream_time;
        int stream_date;
        float current_lat;
        float current_lng;
        float current_elev;
        float lat_offset;
        float lng_offset;
        float elev_offset;
        bool eof;
    };

    typedef struct stream_struct * stream_ptr;
    
    /**
     * Initialised a stream. Opens the stream file and allocates space
     * for a stream struct
     * @param filename name of stream file
     * @return pointer to a stream struct
     */
    stream_ptr init_stream(char * filename);
    
    /**
     * Closes the stream file
     * @param stream pointer to stream
     */
    void close_stream(stream_ptr stream);
    
    /**
     * Updates the offset values held in a stream struct.
     * @param stream pointer to stream
     * @param lat_o latitude offset value
     * @param lng_o longitude offset value
     * @param elev_o elevation offset value
     */
    void update_offsets(stream_ptr stream, float lat_o, float lng_o, float elev_o);

#ifdef	__cplusplus
}
#endif

#endif	/* STREAM_H */

