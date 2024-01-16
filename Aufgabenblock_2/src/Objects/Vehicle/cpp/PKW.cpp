//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for Class PKW in Vehicle Sim 1923
//============================================================================

#include "../headers/PKW.hpp"

extern double dGlobaleZeit;


PKW::PKW(Fahrzeug f, double dconsuption, double dMaxFuel = 55) : Fahrzeug(f), p_dVerbrauch(dconsuption), p_dTankvolumen(dMaxFuel), p_dTankinhalt(dMaxFuel/2){};

std::ostream& operator <<(std::ostream& o, const PKW& x){
	x.vAusgeben(o);
	return o;
}

void PKW::vSimulieren(void){
	double ddeltaTime = dGlobaleZeit - Fahrzeug::Simulationsobjekt::getLastTime();
	double dusedFuel = getConsumpt()*ddeltaTime;
	double dFuelratio = getFuellevel()!=0 ? 1:0;
	//double dFuelratio = getFuellevel()/dusedFuel<1 ? getFuellevel()/dusedFuel:1;				// More precise calculation.... commented out due to the assignment speciffically asking to.
	double ddeltaFuel = getFuellevel()-dusedFuel;
	Fahrzeug::vUpdateDistance(dGeschwindigkeit()*ddeltaTime*dFuelratio);
	Fahrzeug::setTotalTime(getTotalTime()+ddeltaTime);
	Fahrzeug::setLastTime(dGlobaleZeit);
	setFuellevel((ddeltaFuel>0) ? ddeltaFuel:0);
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

double PKW::dGeschwindigkeit(void) const{	return getFuellevel()==0 ? 0:getMaxSpeed();}

void PKW::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
	o.width(16);																					//15 Space for p_dTankinhalt
	std::resetiosflags(std::ios::left);																		//Reset alignment
	o << std::setiosflags(std::ios::right) << getFuellevel();										//Output p_iID right aligned
	o.width(17);																					//15 Space for Name. (Name max 15 Chars)
	o << Fahrzeug::getTotalDistance()*getConsumpt() << std::resetiosflags(std::ios::right);			//Output p_sName left aligned
}

void PKW::vKopf(void){
	PKW::Fahrzeug::vKopf();
	std::cout.width(16);
	std::cout << std::setiosflags(std::ios::right) << "Fuellevel" ;
	std::cout.width(17);
	std::cout << "Used Fuel" << "\n" << std::resetiosflags(std::ios::right);
	std::cout << std::setfill('-') << std::setw(120)<<std::endl << std::setfill(' ');
}
