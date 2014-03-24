/* 
 * File:   main.c
 * Author: sig2
 *
 * Created on 18 March 2014, 13:08
 */

#include "main.h"
int line_count = 0;

static stream_ptr stream1;
static stream_ptr stream2;
static int last_fix_time = 0;
static list_ptr gps_list;

int main(int argc, char** argv) {

  stream1 = init_stream("gps_1.dat");
  stream2 = init_stream("gps_2.dat");
  init_list(&gps_list);



  if (stream1->stream_file == NULL || stream2->stream_file == NULL) {
    printf("Missing stream file. Aborting.");
    return (EXIT_FAILURE);
  }


  while (stream1->eof == false) {
    sync_streams(stream1, stream2);
  }



  close_stream(stream1);
  close_stream(stream2);
  make_gpx(gps_list);

  return (EXIT_SUCCESS);
}

void update(list_ptr sentence_tokens, stream_ptr stream) {

  if (stream->eof == true) {
    return;
  } else {
    char * type = get_head(&sentence_tokens)->node_data;

    if ((strcmp(type, "$GPGSV") == 0)) {
      int quality = make_gsv(sentence_tokens, stream);
      stream->stream_quality = quality;

    } else if ((strcmp(type, "$GPGGA") == 0)) {
      gga_ptr gga = make_gga(sentence_tokens);
      stream->current_elev = gga->elev;
      stream->current_lat = gga->lat;
      stream->current_lng = gga->lng;
      stream->stream_time = gga->time;
    } else if (((strcmp(type, "$GPRMC") == 0))) {
      rmc_ptr rmc = make_rmc(sentence_tokens);
      stream->current_lat = rmc->lat;
      stream->current_lng = rmc->lng;
      stream->stream_time = rmc->time;
    }
  }
}

void sync_streams(stream_ptr s1, stream_ptr s2) {

  bool synced = false;
  sentence_ptr sentence_in = NULL;

  while (synced == false) {
    update_fix();

    if (s1->stream_time < (s2->stream_time)) {
      sentence_in = read_sentence(s1);
      update(parseSentence(sentence_in), s1);
      synced = false;

    } else if (s1->stream_time > (s2->stream_time)) {
      sentence_in = read_sentence(s2);
      update(parseSentence(sentence_in), s2);
      synced = false;

    } else {

      calculate_offsets(s1, s2);
      sentence_in = read_sentence(s1);
      update(parseSentence(sentence_in), s1);
      sentence_in = read_sentence(s2);
      update(parseSentence(sentence_in), s2);
      synced = true;

    }
  }
}

void update_fix() {

  if (stream1->stream_quality == 2) {
    make_new_fix(stream1);
  } else if (stream2->stream_quality == 2) {
    make_new_fix(stream2);
  } else {
    if (stream1->stream_quality == 1) {
      make_new_fix(stream1);
    } else if (stream2->stream_quality == 1) {
      make_new_fix(stream2);
    }
  }
}

void make_new_fix(stream_ptr stream) {
  if ((last_fix_time == 0) || (stream->stream_time > last_fix_time)) {
    if (stream_has_data(stream)) {
      gps_ptr gps = make_gps(stream);
      node_ptr gps_data;
      init_node(&gps_data, gps);
      add_to_list(&gps_data, &gps_list);
      last_fix_time = stream->stream_time;
    }
  }
}

void update_fix_time(stream_ptr stream) {
  last_fix_time = stream->stream_time;
}

void calculate_offsets(stream_ptr s1, stream_ptr s2) {
  float lat_offset = s1->current_lat - s2->current_lat;
  float lng_offset = s1->current_lng - s2->current_lng;
  float elev_offset = s1->current_elev - s2->current_elev;

  update_offsets(s2, lat_offset, lng_offset, elev_offset);
}

bool stream_has_data(stream_ptr stream) {
  float elev = stream->current_elev;
  float lat = stream->current_lat;
  float lng = stream->current_lng;

  return (lng != 0 && lat != 0 && elev != 0);
}