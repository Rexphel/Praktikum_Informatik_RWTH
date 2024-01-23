///============================================================================
// Name        : Streckenende.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for the Exception when reaching the end of the road in Vehicle Sim 1923
//============================================================================

#include "../../Exceptions/headers/Streckenende.hpp"

#include <iostream>
#include "../../Roads/headers/Weg.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"

void Streckenende::vBearbeiten(void){
	auto f = p_Weg.pAbgabe(p_Fzg);
}



