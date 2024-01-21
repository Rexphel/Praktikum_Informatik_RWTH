//============================================================================
// Name        : FreeFunctions.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Free functions for Vehicles in Vehicle Sim 1923
//============================================================================

#include "GlobalIncludes.hpp"

double dGlobaleZeit = 0.0;

std::string setStringlength(long long unsigned i, std::string s){																//Function to set a given string to any given size
	if(s.size()<=i){return s;}
	s.resize(i,' ');
	return s;
}

double randDouble(int lower, int upper){
	std::default_random_engine rnd{std::random_device{}()};
	std::uniform_real_distribution<double> dist(lower, upper);
	return dist(rnd);
}

void console_clear_screen(void) {
  #if defined _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}
