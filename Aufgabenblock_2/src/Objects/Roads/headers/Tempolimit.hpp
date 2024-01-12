//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Tempolimit in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_ROADS_HEADERS_TEMPOLIMIT_HPP_
#define OBJECTS_ROADS_HEADERS_TEMPOLIMIT_HPP_

#include <limits>

enum class Tempolimit : int{
	Innerorts=50,
	Landstraße=100,
	Autobahn=std::numeric_limits<int>::max()
};


#endif /* OBJECTS_ROADS_HEADERS_TEMPOLIMIT_HPP_ */
