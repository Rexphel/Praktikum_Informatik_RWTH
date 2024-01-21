//============================================================================
// Name        : Fahrausnahme.hpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the Exception when starting to drive in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_EXCEPTIONS_HEADERS_LOSFAHREN_HPP_
#define OBJECTS_EXCEPTIONS_HEADERS_LOSFAHREN_HPP_

#include "Fahrausnahme.hpp"

class Losfahren : public Fahrausnahme{
	public:
		Losfahren()=delete;
		Losfahren(Fahrzeug& aFzg, Weg& aWeg) : Fahrausnahme(aFzg,aWeg){}
		~Losfahren(){};
		void vBearbeiten(void);
};



#endif /* OBJECTS_EXCEPTIONS_HEADERS_LOSFAHREN_HPP_ */
