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

#include "GrafischeAusgabe/SimuClient.h"
#include "Objects/Simulationsobjekt.hpp"

#include "Objects/Roads/headers/Weg.hpp"
#include "Objects/Roads/headers/Tempolimit.hpp"

#include "Objects/Vehicle/headers/Fahren.hpp"
#include "Objects/Vehicle/headers/Fahrrad.hpp"
#include "Objects/Vehicle/headers/Fahrzeug.hpp"
#include "Objects/Vehicle/headers/Parken.hpp"
#include "Objects/Vehicle/headers/PKW.hpp"
#include "Objects/Vehicle/headers/Verhalten.hpp"

#include "Objects/Exceptions/headers/Fahrausnahme.hpp"
#include "Objects/Exceptions/headers/Losfahren.hpp"
#include "Objects/Exceptions/headers/Streckenende.hpp"


#define _WIN32 1
#define DEBUG TRUE

std::string setStringlength(long long unsigned i, std::string s);																//Function to set a given string to any given size

double randDouble(int lower, int upper);

void console_clear_screen(void);

#endif /* GLOBALINCLUDES_HPP_ */