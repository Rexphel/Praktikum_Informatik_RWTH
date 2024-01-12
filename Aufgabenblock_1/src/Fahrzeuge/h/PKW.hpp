//============================================================================
// Name        : PKW.h
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for PKW in Vehicle Sim 1923
//============================================================================


#ifndef PKW_H
#define PKW_H

#include <iostream>
#include <string>

#include "Fahrzeug.hpp"

class PKW : public Fahrzeug{

	private:
		const double p_dVerbrauch;
		const double p_dTankvolumen;
		double p_dTankinhalt;
		PKW(const PKW&) = delete;			//Do not allow Copy Constructor
        friend std::ostream & operator<<(std::ostream& o, const PKW& x);
	public:
		PKW() = delete;
		PKW(std::string sName, double dMaxSpeed, double dconsuption, double dMaxFuel = 55);
		virtual ~PKW();
		PKW operator=(const PKW& f){return PKW(f.p_sName,f.p_dMaxGeschwindigkeit,f.p_dVerbrauch,f.p_dTankvolumen);}
		void vSimulieren(void) override;
		double getConsumpt(void) const{return p_dVerbrauch;}
		double getVolume(void) const{return p_dTankvolumen;}
		double getFuellevel(void) const{return p_dTankinhalt;}
		void setFuellevel(double dTankinhalt){p_dTankinhalt=dTankinhalt;}
		double dTanken(void);
		double dTanken(double dquantity);
		double dGeschwindigkeit(void) const override;
		void vAusgeben(std::ostream& o) const override;
		static void vKopf(void);
};

#endif // PKW_H
