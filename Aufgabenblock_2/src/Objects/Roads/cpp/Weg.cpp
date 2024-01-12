//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Member Functions for Weg in Vehicle Sim 1923
//============================================================================


#include "../headers/Weg.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"
#include "../headers/Tempolimit.hpp"

Weg::Weg(): Simulationsobjekt(""), p_dLaenge(100), p_eTempolimit(Tempolimit::Autobahn){}

Weg::Weg(std::string s, double länge, Tempolimit limit): Simulationsobjekt(s), p_dLaenge(länge), p_eTempolimit(limit){}

Weg::~Weg(void){};

std::unique_ptr<Fahrzeug> Weg::popFahrzeug(int iter){

	std::list<std::unique_ptr<Fahrzeug>>::iterator it = std::next(p_pFahrzeuge.begin(), iter);
	std::unique_ptr<Fahrzeug> temp = move(*it);
	p_pFahrzeuge.erase(it);

	return temp;
}

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
	std::cout.width(1); std::cout <<"";
	o.width(3);																				//20 space for TotalDistance
	o << "( " ;
	for (const std::unique_ptr<Fahrzeug>& f : p_pFahrzeuge){
		o << f->getName() << ", ";
	}
	o << " )" << std::resetiosflags(std::ios::right);								//Output p_dGesammtStrecke right aligned
}

void Weg::vKopf(void){
	Simulationsobjekt::vKopf();
	std::cout.width(1); std::cout <<"";
	std::cout << "|";
	std::cout.width(1); std::cout <<"";
	std::cout.width(10);
	std::cout << std::setiosflags(std::ios::right) << "Road length" << std::resetiosflags(std::ios::right);
	std::cout.width(1); std::cout <<"";
	std::cout << "|";
	std::cout.width(1); std::cout <<"";
	std::cout.width(20);
	std::cout << std::setiosflags(std::ios::left) << "Vehicles" << std::resetiosflags(std::ios::left);
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> f){
	Weg::pushFahrzeug(move(f));
}
