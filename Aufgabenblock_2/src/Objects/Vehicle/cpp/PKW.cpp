//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for Class PKW in Vehicle Sim 1923
//============================================================================

#include "../headers/PKW.hpp"
#include "../../Roads/headers/Weg.hpp"
#include "../../Exceptions/headers/Losfahren.hpp"
#include "../../Exceptions/headers/Streckenende.hpp"
#include "../../../GrafischeAusgabe/SimuClient.h"

extern double dGlobaleZeit;

PKW::PKW(std::string sName, double dGesch, double dconsuption, double dMaxFuel) : Fahrzeug(sName, dGesch), p_dVerbrauch(dconsuption), p_dTankvolumen(dMaxFuel), p_dTankinhalt(dMaxFuel/2){};

std::ostream& operator <<(std::ostream& o, const PKW& x){
	x.vAusgeben(o);
	return o;
}

void PKW::vSimulieren(void){
	double ideltaTime = dGlobaleZeit - Simulationsobjekt::getLastTime();
	double dFuelratio = getFuellevel()!=0 ? 1:0;
	//double dFuelratio = getFuellevel()/dusedFuel<1 ? getFuellevel()/dusedFuel:1;				// More precise calculation.... commented out due to the assignment speciffically asking to.
	double drivenDistance = 0.0;
	try{
		drivenDistance = Fahrzeug::p_pVerhalten->dStrecke(*this, ideltaTime)*dFuelratio;
	}
	catch(Fahrausnahme& e){
		e.vBearbeiten();
		//e.vBearbeiten();
	}
	double dusedFuel = getConsumpt()*drivenDistance/100;
	double ddeltaFuel = getFuellevel()-dusedFuel;
	setFuellevel(ddeltaFuel>0 ? ddeltaFuel:0);
}

double PKW::dTanken(){
	double deltaTank = getVolume()-getFuellevel();
	setFuellevel(getVolume());
	return deltaTank;
}
double PKW::dTanken(double dquantity){
	setFuellevel(getFuellevel()+dquantity);
	return dquantity;
}

double PKW::dGeschwindigkeit(void) const{
	return p_pVerhalten->getRoad().getSpeedLimit()< getMaxSpeed()? p_pVerhalten->getRoad().getSpeedLimit() : getMaxSpeed();

}

void PKW::vZeichnen(const Weg& weg){
	bZeichnePKW(p_sName, weg.getName(), (p_dAbschnittStrecke/weg.getLength()), dGeschwindigkeit(), p_dTankinhalt);
}

void PKW::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
	o.width(16);																					//15 Space for p_dTankinhalt
	std::resetiosflags(std::ios::left);																		//Reset alignment
	o << std::setiosflags(std::ios::right) << getFuellevel();										//Output p_iID right aligned
	o.width(17);																					//15 Space for Name. (Name max 15 Chars)
	o << Fahrzeug::getTotalDistance()*getConsumpt()/100 << std::resetiosflags(std::ios::right);			//Output p_sName left aligned
}

void PKW::vKopf(void){
	PKW::Fahrzeug::vKopf();
	std::cout.width(16);
	std::cout << std::setiosflags(std::ios::right) << "Fuellevel" ;
	std::cout.width(17);
	std::cout << "Used Fuel" << "\n" << std::resetiosflags(std::ios::right);
	std::cout << std::setfill('-');
	std::cout.width(120);
	std::cout << std::endl << std::setfill(' ');
}
