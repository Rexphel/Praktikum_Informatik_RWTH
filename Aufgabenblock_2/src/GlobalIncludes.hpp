//============================================================================
// Name        : GlobalIncludes.h
// Author      : Philip Rexroth
// Version     : 0.6
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : All Classes in Vehicle Sim 1923
//============================================================================


#ifndef GLOBALINCLUDES_HPP_
#define GLOBALINCLUDES_HPP_

#include <conio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <random>

#include "Exceptions/headers/Fahrausnahme.hpp"
#include "Exceptions/headers/Losfahren.hpp"
#include "Exceptions/headers/Streckenende.hpp"
#include "GrafischeAusgabe/SimuClient.h"
#include "Roads/headers/Tempolimit.hpp"
#include "Roads/headers/Weg.hpp"
#include "Roads/headers/Kreuzung.hpp"
#include "Simulationsobjekt.hpp"
#include "Vehicle/headers/Fahren.hpp"
#include "Vehicle/headers/Fahrrad.hpp"
#include "Vehicle/headers/Fahrzeug.hpp"
#include "Vehicle/headers/Parken.hpp"
#include "Vehicle/headers/PKW.hpp"
#include "Vehicle/headers/Verhalten.hpp"
#include "VListe/vertagt_aktion.h"
#include "VListe/vertagt_liste.h"


std::string setStringlength(long long unsigned i, std::string s);																//Function to set a given string to any given size

double randDouble(int lower, int upper);

void console_clear_screen(void);

#endif /* GLOBALINCLUDES_HPP_ */
