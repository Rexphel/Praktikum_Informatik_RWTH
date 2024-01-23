//============================================================================
// Name        : Fahren.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member functions for driving behavior in Vehicle Sim 1923
//============================================================================

#include "../headers/Fahren.hpp"

#include <math.h>
#include "../../Exceptions/headers/Streckenende.hpp"
#include "../../Roads/headers/Weg.hpp"
#include "../headers/Fahrzeug.hpp"

extern double dGlobaleZeit;

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){

	double dSpeed = aFzg.dGeschwindigkeit();
	double dLength = p_aWeg.getLength();
	double dMaxDrivenDistance = dSpeed*dZeitIntervall;
	double dTotalDrivenDistance = aFzg.getAbschnittStrecke()+dMaxDrivenDistance;
	double dDrivenDistance= dTotalDrivenDistance<dLength ? dMaxDrivenDistance:dLength-aFzg.getAbschnittStrecke();

	if (std::abs(0-dDrivenDistance)<0.0001) {
		std::cout<<"Still at the End of the Road"<<std::endl;
		throw Streckenende(aFzg, p_aWeg);
	}
	else if (dDrivenDistance<dMaxDrivenDistance|| std::abs(dLength-aFzg.getAbschnittStrecke()-dMaxDrivenDistance)<0.0001){
		std::cout<<"Reached the End of the Road"<<std::endl;
	}
	aFzg.setTotalTime(aFzg.getTotalTime()+dZeitIntervall);
	aFzg.setLastTime(dGlobaleZeit);
	return  dDrivenDistance;

}

