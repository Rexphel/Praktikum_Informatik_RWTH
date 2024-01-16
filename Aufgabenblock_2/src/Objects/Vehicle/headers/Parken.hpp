//============================================================================
// Name        : Parken.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for parking behavior in Vehicle Sim 1923
//============================================================================


#ifndef OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_
#define OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_

class Verhalten;
class Weg;

class Parken : public Verhalten{
	private:
	protected:
		double p_dStartzeitpunkt;
	public:
		Parken(Weg& weg, double dStartzeitpunkt);

};


#endif /* OBJECTS_VEHICLE_HEADERS_PARKEN_HPP_ */
