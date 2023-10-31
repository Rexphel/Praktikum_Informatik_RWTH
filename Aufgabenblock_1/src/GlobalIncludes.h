//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================
#include "Fahrzeuge/Fahrzeug.h"
#include "Fahrzeuge/Fahrrad.h"
#include "Fahrzeuge/PKW.h"

#define WINDOWS 1
#define LINUX 0
#define DEBUG 1

double dGlobaleZeit = 0.0;

std::string setStringlength(long long i, std::string s){																//Function to set a given string to any given size
	s.resize(i,' ');
	return s;
}

double randDouble(int lower, int upper){
	std::default_random_engine rnd{std::random_device{}()};
	std::uniform_real_distribution<double> dist(lower, upper);
	return dist(rnd);
}

void console_clear_screen(void) {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}
