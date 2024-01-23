//============================================================================
// Name        : Parken.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for parking behavior in Vehicle Sim 1923
//============================================================================


#ifndef VEHICLE_HEADERS_PARKEN_HPP_
#define VEHICLE_HEADERS_PARKEN_HPP_

#include "../../Vehicle/headers/Verhalten.hpp"
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

#endif /* VEHICLE_HEADERS_PARKEN_HPP_ */
