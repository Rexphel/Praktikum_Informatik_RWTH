//============================================================================
// Name        : Verhalten.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the behavior of Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef VEHICLE_HEADERS_VERHALTEN_HPP_
#define VEHICLE_HEADERS_VERHALTEN_HPP_

class Weg;
class Fahrzeug;

class Verhalten{
	private:
		Verhalten(const Verhalten&)=delete;
	protected:
		Weg& p_aWeg;
	public:
		Verhalten()=delete;
		Verhalten(Weg& w): p_aWeg(w){};
		virtual ~Verhalten();
		Weg& getRoad(void){return p_aWeg;};
		virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

};
#endif /* VEHICLE_HEADERS_VERHALTEN_HPP_ */
