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
#include "../../Roads/headers/Kreuzung.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"

#include "../../GlobalParameters.h"

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

extern double dGlobaleZeit;


void Streckenende::vBearbeiten(void){
	std::shared_ptr<Kreuzung> kreuzung = p_Weg.getKreuzung();
	kreuzung->vTanken(p_Fzg);
	std::shared_ptr<Weg> rückweg = kreuzung->pZufaelligerWeg(p_Weg);

	DEBUG_MSG("Zeit     : "<<dGlobaleZeit<<std::endl
			<<"Kreuzung : "<<kreuzung->getName()<<" "<<kreuzung->getTankstelleninhalt()<<std::endl
			<<"Wechsel  : "<<p_Weg.getName()<<" -> "<<rückweg->getName()<<std::endl
			<<"Fahrzeug : "<<p_Fzg<<std::endl);

	rückweg->vAnnahme(p_Weg.pAbgabe(p_Fzg));
}



