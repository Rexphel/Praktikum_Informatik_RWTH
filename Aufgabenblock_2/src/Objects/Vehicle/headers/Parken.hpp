//============================================================================
// Name        : Parken.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for parking behavior in Vehicle Sim 1923
//============================================================================


#ifndef OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_
#define OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_

#include "Verhalten.hpp"
class Fahrzeug;
class Weg;

class Parken : public Verhalten{
	private:
		Parken(const Parken&)=delete;
	protected:
		double p_dStartzeitpunkt;
	public:
		Parken(Weg& weg, double dStartzeitpunkt) : Verhalten(weg), p_dStartzeitpunkt(dStartzeitpunkt){};
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);
};

#endif /* OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_ */
