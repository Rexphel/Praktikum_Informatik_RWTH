//============================================================================
// Name        : GlobalIncludes.h
// Author      : Philip Rexroth
// Version     : 0.6
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================


#ifndef GLOBALINCLUDES_HPP_
#define GLOBALINCLUDES_HPP_

#include <conio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <random>

#include "Fahrzeuge/h/Fahrrad.hpp"
#include "Fahrzeuge/h/Fahrzeug.hpp"
#include "Fahrzeuge/h/PKW.hpp"

#define WINDOWS 1
#define LINUX 0
#define DEBUG TRUE

std::string setStringlength(long long i, std::string s);																//Function to set a given string to any given size

double randDouble(int lower, int upper);

void console_clear_screen(void);

#endif /* GLOBALINCLUDES_HPP_ */
