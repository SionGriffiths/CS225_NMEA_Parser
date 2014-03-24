
/**
 * @file   stream.c
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2013
 * @brief  Holds current data representing the state of a stream of NMEA sentences
 */

#include "stream.h"
#include <stdbool.h>

/**
 * Initialised a stream. Opens the stream file and allocates space
 * for a stream struct
 * @param filename name of stream file
 * @return pointer to a stream struct
 */
stream_ptr init_stream(char * filename){
  stream_ptr stream = calloc(1, sizeof (struct stream_struct));
  stream->stream_file = fopen(filename , "r");
  stream->stream_quality = 2;
  stream->eof = false;
  
  return stream;
}

/**
 * Closes the stream file
 * @param stream pointer to stream
 */
void close_stream(stream_ptr stream){
  fclose(stream->stream_file);
}


/**
 * Updates the offset values held in a stream struct.
 * @param stream pointer to stream
 * @param lat_o latitude offset value
 * @param lng_o longitude offset value
 * @param elev_o elevation offset value
 */
void update_offsets(stream_ptr stream , float lat_o, float lng_o, float elev_o){
  stream->lat_offset = lat_o;
  stream->lng_offset = lng_o;
  stream->elev_offset = elev_o;
}
