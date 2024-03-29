//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for Fahrrad in Vehicle Sim 1923
//============================================================================

#include "../headers/Fahrrad.hpp"
#include "../../Roads/headers/Weg.hpp"
#include "../../GrafischeAusgabe/SimuClient.h"
#include <cmath>

Fahrrad::Fahrrad(std::string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit){} 		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output

double Fahrrad::dGeschwindigkeit(void) const{
	double dSpeed = getMaxSpeed()*std::pow(0.8,getTotalTime());			//x*0.01+1 is the formula to get the wanted delta
	return dSpeed>12 ? dSpeed:12;
}

void Fahrrad::vZeichnen(const Weg& weg){
	bZeichneFahrrad(p_sName, weg.getName(), (p_dAbschnittStrecke/weg.getLength()), dGeschwindigkeit());
};
