//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Fahrrad in Vehicle Sim 1923
//============================================================================

#ifndef Fahrrad_H
#define Fahrrad_H

#include <string>

#include "Fahrzeug.hpp"

class Fahrrad : public Fahrzeug{
	private:
		Fahrrad(const Fahrrad&) = delete;			//Do not allow Copy Constructor
	public:
		Fahrrad(std::string s, double d);
		Fahrrad operator=(const Fahrrad& f){return Fahrrad(f.p_sName, f.getMaxSpeed());}

		double dGeschwindigkeit(void)const;
};


#endif // Fahrrad_H

