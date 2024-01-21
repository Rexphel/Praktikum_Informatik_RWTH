//============================================================================
// Name        : Parken.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for parking behavior in Vehicle Sim 1923
//============================================================================

#include "../headers/Parken.hpp"
#include "../../Exceptions/headers/Losfahren.hpp"
#include <iostream>
#include <math.h>

extern double dGlobaleZeit;

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	if(dGlobaleZeit-p_dStartzeitpunkt<-0.0001) return  0;
	std::cout << "Car should drive" << std::endl;
	throw Losfahren(aFzg, p_aWeg);
	return 0;
}