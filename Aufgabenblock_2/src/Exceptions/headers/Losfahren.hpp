//============================================================================
// Name        : Fahrausnahme.hpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the Exception when starting to drive in Vehicle Sim 1923
//============================================================================

#ifndef EXCEPTIONS_HEADERS_LOSFAHREN_HPP_
#define EXCEPTIONS_HEADERS_LOSFAHREN_HPP_

#include "../../Exceptions/headers/Fahrausnahme.hpp"

class Losfahren : public Fahrausnahme{
	public:
		Losfahren()=delete;
		Losfahren(Fahrzeug& aFzg, Weg& aWeg) : Fahrausnahme(aFzg,aWeg){}
		~Losfahren(){};
		void vBearbeiten(void);
};



#endif /* EXCEPTIONS_HEADERS_LOSFAHREN_HPP_ */
