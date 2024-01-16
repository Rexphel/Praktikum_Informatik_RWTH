//============================================================================
// Name        : Fahren.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for driving behavior in Vehicle Sim 1923
//============================================================================

#include "../headers/Fahren.hpp"
#include "../headers/Fahrzeug.hpp"

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	double distance = aFzg.getTotalDistance() + aFzg.dGeschwindigkeit()*dZeitIntervall;
	return distance;
}


