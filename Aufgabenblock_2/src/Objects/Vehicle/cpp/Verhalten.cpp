//============================================================================
// Name        : Verhalten.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member Functions for the behavior of Vehicles in Vehicle Sim 1923
//============================================================================

#include "../headers/Verhalten.hpp"
#include "../headers/Fahrzeug.hpp"
#include "../../Roads/headers/Weg.hpp"

Verhalten::Verhalten(Weg& w): weg(w){}


double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){

	double dMaxDistance = aFzg.dGeschwindigkeit()*dZeitIntervall;
	double dDrivenDistance = aFzg.getAbschnittStrecke()+dMaxDistance;
	double dLength = weg.getLength();
	double dRealDistance= dDrivenDistance<dLength ? dMaxDistance:(dMaxDistance-(dDrivenDistance-dLength));

	if (dRealDistance<dMaxDistance){
		std::cout<<"Reached the End of the Road"<<std::endl;
	}
	else if (dRealDistance==0) {
		std::cout<<"Still at the End of the Road"<<std::endl;
	}

	return  dRealDistance;
}
