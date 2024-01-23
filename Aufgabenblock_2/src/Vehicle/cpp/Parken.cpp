//============================================================================
// Name        : Parken.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for parking behavior in Vehicle Sim 1923
//============================================================================

#include "../headers/Parken.hpp"
#include "../headers/Fahrzeug.hpp"
#include "../../Exceptions/headers/Losfahren.hpp"

#include <iostream>
#include <math.h>

extern double dGlobaleZeit;

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	aFzg.setTotalTime(aFzg.getTotalTime()+dZeitIntervall);
	aFzg.setLastTime(dGlobaleZeit);
	if(dGlobaleZeit<=p_dStartzeitpunkt) return  0;
	std::cout << "Car should drive" << std::endl;
	throw Losfahren(aFzg, p_aWeg);
}
