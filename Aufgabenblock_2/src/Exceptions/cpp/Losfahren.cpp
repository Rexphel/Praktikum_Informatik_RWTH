///============================================================================
// Name        : Losfahren.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for the Exception when starting to drive in Vehicle Sim 1923
//============================================================================

#include "../../Exceptions/headers/Losfahren.hpp"

#include <iostream>
#include "../../Roads/headers/Weg.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"

void Losfahren::vBearbeiten(void){

	auto temp = p_Weg.pAbgabe(p_Fzg);
	std::cout<<p_Fzg.getName()<<p_Weg.getName()<<"Losfahren"<<std::endl;
	if(temp==nullptr)return;
	p_Weg.vAnnahme(move(temp));
//	std::cout<<p_Fzg.getName()<<p_Weg.getName()<<"Losfahren"<<std::endl;
}
