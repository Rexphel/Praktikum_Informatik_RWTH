//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member Functions for Weg in Vehicle Sim 1923
//============================================================================


#include "../headers/Weg.hpp"

Weg::Weg(): Simulationsobjekt(""), p_dLaenge(100), p_eTempolimit(Tempolimit::Autobahn){}

Weg::Weg(std::string s, double länge, Tempolimit limit): Simulationsobjekt(s), p_dLaenge(länge), p_eTempolimit(limit){}

Weg::~Weg(void){};

void Weg::vSimulieren(void){
	for (std::unique_ptr<Fahrzeug>& f : p_pFahrzeuge){
		f->vSimulieren();
	}
}

std::ostream& operator<<(std::ostream &o, const Weg &x){
	x.vAusgeben(o);
	return o;
}

void Weg::vAusgeben(std::ostream& o)const{
	Simulationsobjekt::vAusgeben(o);
	o.width(12);																				//12 Space for Length
	o << std::setiosflags(std::ios::right) << p_dLaenge;									//Output p_dMaxGeschwindigkeit right aligned
	o.width(3);																				//20 space for TotalDistance
	o << "(" ;
	for (const std::unique_ptr<Fahrzeug>& f : p_pFahrzeuge){
		o.width(15);
		o << f->getName() << ",";
	}
	o << ")" << std::resetiosflags(std::ios::right);								//Output p_dGesammtStrecke right aligned
}

void Weg::vKopf(void){
	Simulationsobjekt::vKopf();
	std::cout.width(17);
	std::cout << std::setiosflags(std::ios::right) << "Road length" ;
	std::cout.width(20);
	std::cout << "Vehicles" << std::resetiosflags(std::ios::right);
	std::cout << std::setfill('-') << std::setw(55)<<"\n" << std::setfill(' ');
}
