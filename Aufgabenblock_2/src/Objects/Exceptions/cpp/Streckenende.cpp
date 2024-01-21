///============================================================================
// Name        : Streckenende.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for the Exception when reaching the end of the road in Vehicle Sim 1923
//============================================================================

#include "../headers/Streckenende.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"
#include "../../Roads/headers/Weg.hpp"

#include <iostream>

void Streckenende::vBearbeiten(void){
	std::cout<<p_Fzg.getName()<<p_Weg.getName()<<"Streckenende"<<std::endl;
}



