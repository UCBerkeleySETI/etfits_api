#ifndef S6FITS_H_INCLUDED
#define S6FITS_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include <vector>

typedef struct 
{
  double julian_date;
  time_t unix_time;
  double ra;
  int bors;
  double dec;
  int nhits;
  int missedpk;
  float detected_power;
  float mean_power;
  unsigned long fine_channel_bin;
  unsigned short coarse_channel_bin;
  //to be calculated by a seperate function. Not implemented at the moment.
  double ifreq;
  double rfreq;
} s6hits_t;

typedef struct
{
  char * filename;
  //time over the course of one file
  time_t seconds;
  //vector where hits requested will be added onto.
  std::vector<s6hits_t> s6hits;
  int sortby_freq;
  int sortby_time;
  int sortby_bors;
  float threshold;
  std::vector<int> bors;
  //same as above but with channels
  std::vector<int> channels;
  //status in cfitsio
  int errorcode;
} s6dataspec_t;



int get_s6data (s6dataspec_t * s6dataspec);

time_t get_time_over_file (char * filename);

int get_hits_over_file (char * filename);

void print_hits_structure (std::vector<s6hits_t> s6hits);

void print_hits_table (std::vector<s6hits_t> s6hits);

#endif