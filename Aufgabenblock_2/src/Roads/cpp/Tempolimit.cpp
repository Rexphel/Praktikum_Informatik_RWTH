//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member Functions of Tempolimit in Vehicle Sim 1923
//============================================================================

#include "../../Roads/headers/Tempolimit.hpp"

double getTempolimit(Tempolimit t){
	switch(t){
		case Tempolimit::Innerorts: return 50; break;
		case Tempolimit::Landstraße: return 100; break;
		case Tempolimit::Autobahn: return std::numeric_limits<int>::max();
	}
	return 0;
}

