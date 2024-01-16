//============================================================================
// Name        : Fahren.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for driving behavior in Vehicle Sim 1923
//============================================================================


#ifndef OBJECTS_VEHICLE_HEADERS_FAHREN_HPP_
#define OBJECTS_VEHICLE_HEADERS_FAHREN_HPP_

#include "Verhalten.hpp"
class Fahrzeug;

class Fahren : public Verhalten{
	private:
	protected:
	public:
		Fahren()=delete;
		Fahren(Weg& weg):Verhalten(weg){};
		~Fahren();
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);
};



#endif /* OBJECTS_VEHICLE_HEADERS_FAHREN_HPP_ */
