//============================================================================
// Name        : Fahrausnahme.hpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Abstract Class for Exceptions while Driving in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_EXCEPTIONS_HEADERS_FAHRAUSNAHME_HPP_
#define OBJECTS_EXCEPTIONS_HEADERS_FAHRAUSNAHME_HPP_

#include <exception>

class Fahrzeug;
class Weg;

class Fahrausnahme : public std::exception {
	protected:
		Fahrzeug& p_Fzg;
		Weg& p_Weg;
	public:
		Fahrausnahme()=delete;
		Fahrausnahme(Fahrzeug& aFzg, Weg& aWeg) : p_Fzg(aFzg), p_Weg(aWeg){}
		virtual ~Fahrausnahme(){};
		virtual void vBearbeiten(void){};
};



#endif /* OBJECTS_EXCEPTIONS_HEADERS_FAHRAUSNAHME_HPP_ */
