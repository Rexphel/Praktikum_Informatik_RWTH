//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for Class Vehicles in Vehicle Sim 1923
//============================================================================

#include "../headers/Fahrzeug.hpp"
#include "../../Roads/headers/Weg.hpp"
#include "../headers/Fahren.hpp"
#include "../headers/Parken.hpp"
#include "../../Exceptions/headers/Fahrausnahme.hpp"

extern double dGlobaleZeit;

Fahrzeug::Fahrzeug(std::string s, double d): Simulationsobjekt(s), p_dMaxGeschwindigkeit(d>0 ? d:0) {};		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output

void Fahrzeug::vSimulieren() {
	double ideltaTime = dGlobaleZeit - getLastTime();
	try{
		Fahrzeug::p_pVerhalten->dStrecke(*this, ideltaTime);
	}
	catch(Fahrausnahme& e){
		e.vBearbeiten();
	}
}

void Fahrzeug::vAusgeben(std::ostream& out) const{
	Simulationsobjekt::vAusgeben(out);
	out.width(12);																				//12 Space for MaxSpeed
	out << std::setiosflags(std::ios::right) << p_dMaxGeschwindigkeit;									//Output p_dMaxGeschwindigkeit right aligned
	out.width(20);																				//20 space for Current Speed
	out << dGeschwindigkeit();																	//Output current Speed right aligned
	out.width(20);																				//20 space for TotalDistance
	out << p_dGesamtStrecke << std::resetiosflags(std::ios::right);								//Output p_dGesammtStrecke right aligned
}

void Fahrzeug::vUpdateDistance(double distance){
	Fahrzeug::p_dAbschnittStrecke += distance;
	Fahrzeug::p_dGesamtStrecke += distance;
}


void Fahrzeug::vNeueStrecke(Weg& weg){
	Fahrzeug::p_pVerhalten = std::make_unique<Fahren>(weg);
	Fahrzeug::p_dAbschnittStrecke = 0.0 ;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double dStartZeit){
	Fahrzeug::p_pVerhalten = std::make_unique<Parken>(weg, dStartZeit);
	Fahrzeug::p_dAbschnittStrecke = 0.0 ;
}


bool operator <(const Fahrzeug& x, const Fahrzeug& y){
	if(x.getTotalDistance()<y.getTotalDistance()){
		return true;
	}
	return false;
}

std::ostream& operator <<(std::ostream& o, const Fahrzeug& x){
	x.vAusgeben(o);
	return o;
}


void Fahrzeug::vKopf(void){
	Simulationsobjekt::vKopf();
	std::cout.width(17);
	std::cout << std::setiosflags(std::ios::right) << "MaxSpeed" ;
	std::cout.width(20);
	std::cout << "Current Speed";
	std::cout.width(20);
	std::cout << "TotalDistance" << std::resetiosflags(std::ios::right);
//	std::cout << std::setfill('-') << std::setw(55)<<"\n" << std::setfill(' ');

}
