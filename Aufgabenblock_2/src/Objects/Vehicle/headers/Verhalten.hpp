//============================================================================
// Name        : Verhalten.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the behavior of Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_
#define OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_

#include "../../Roads/headers/Weg.hpp"
#include "Fahrzeug.hpp"

class Verhalten{
	private:
		Verhalten(const Verhalten&)=delete;
	protected:
		Weg& weg;
	public:
		Verhalten()=delete;
		Verhalten(Weg& w);
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

};



#endif /* OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_ */
