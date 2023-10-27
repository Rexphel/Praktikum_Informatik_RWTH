//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for PKW in Vehicle Sim 1923
//============================================================================

#include <string>
#include "Fahrzeug.h"

class PKW : public Fahrzeug{

	private:
		double p_dVerbrauch = 0.0;
		double p_dTankvolumen = 55;
		double p_dTankinhalt = 0.0;
	public:
		PKW() = default;
		PKW(std::string sName, double dMaxSpeed, double dconsuption, double dMaxFuel);
		void vSimulieren(void);
		double getConsumpt(void){return p_dVerbrauch;}
		double getVolume(void){return p_dTankinhalt;}
		double getFuellevel(void){return p_dTankinhalt;}
		void setFuellevel(double dTankinhalt){p_dTankinhalt=dTankinhalt;}
		double dTanken(void);
		double dTanken(double dquantity);
		void vAusgeben(void);
		void static vKopf(void);
};

PKW::PKW(std::string sName, double dMaxSpeed, double dconsuption, double dMaxFuel = 55) : Fahrzeug(setStringlengt(14, sName), (dMaxSpeed>0 ? dMaxSpeed:0)), p_dVerbrauch(dconsuption), p_dTankvolumen(dMaxFuel), p_dTankinhalt(dMaxFuel/2){
	Fahrzeug::vincrMaxID();
}

void PKW::vSimulieren(void){
	double ddeltaTime = dGlobaleZeit - Fahrzeug::getLastTime();
	double dusedFuel = getConsumpt()*ddeltaTime;
	double dFuelratio = getFuellevel()/dusedFuel;
	double ddeltaFuel = getFuellevel()-dusedFuel;
	Fahrzeug::vSimulieren(dFuelratio);
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

void vAusgeben(void){

}

