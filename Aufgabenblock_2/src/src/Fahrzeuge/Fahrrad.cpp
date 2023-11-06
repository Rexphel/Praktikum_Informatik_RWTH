//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for Fahrrad in Vehicle Sim 1923
//============================================================================

#include "h/Fahrrad.hpp"

#include <cmath>

std::string setStringlength(long long lengt, std::string s);

Fahrrad::Fahrrad(std::string s, double d) : Fahrzeug(setStringlength(14, s), (d>0 ? d:0)){} 		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output

double Fahrrad::dGeschwindigkeit(void) const{
	double dSpeed = getMaxSpeed()*std::pow(0.8,getTotalTime());			//x*0.01+1 is the formula to get the wanted delta
	return dSpeed>12 ? dSpeed:12;
}
