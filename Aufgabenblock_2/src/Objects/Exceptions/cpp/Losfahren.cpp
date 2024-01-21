///============================================================================
// Name        : Losfahren.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for the Exception when starting to drive in Vehicle Sim 1923
//============================================================================

#include "../headers/Losfahren.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"
#include "../../Roads/headers/Weg.hpp"
#include <iostream>

void Losfahren::vBearbeiten(void){
	std::cout<<p_Fzg.getName()<<p_Weg.getName()<<"Losfahren"<<std::endl;
}
