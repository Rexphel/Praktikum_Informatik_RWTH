//============================================================================
// Name        : Streckenende.hpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the Exception when reaching the end of the road in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_EXCEPTIONS_HEADERS_STRECKENENDE_HPP_
#define OBJECTS_EXCEPTIONS_HEADERS_STRECKENENDE_HPP_

#include "Fahrausnahme.hpp"

class Streckenende : public Fahrausnahme{
	public:
		Streckenende()=delete;
		Streckenende(Fahrzeug& aFzg, Weg& aWeg) : Fahrausnahme(aFzg,aWeg){}
		~Streckenende(){};
		void vBearbeiten(void);
};




#endif /* OBJECTS_EXCEPTIONS_HEADERS_STRECKENENDE_HPP_ */
