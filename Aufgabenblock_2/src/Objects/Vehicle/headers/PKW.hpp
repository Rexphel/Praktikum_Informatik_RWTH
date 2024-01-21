//============================================================================
// Name        : PKW.hpp
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
		double p_dVerbrauch = 0.0;
		double p_dTankvolumen;
		double p_dTankinhalt = 0.0;
		PKW(const PKW&) = delete;			//Do not allow Copy Constructor
        friend std::ostream & operator<<(std::ostream& o, const PKW& x);
	public:
		PKW() = delete;
		PKW(std::string sName, double dGesch, double dconsuption, double dMaxFuel = 55);
		PKW operator=(const PKW& f){return PKW(f.p_sName, f.p_dMaxGeschwindigkeit, f.p_dVerbrauch, f.p_dTankvolumen);}
		void vSimulieren(void) override;
		void vAusgeben(std::ostream& o) const override;
		static void vKopf(void);
		double dTanken(void);
		double dTanken(double dquantity);
		double dGeschwindigkeit(void) const override;
		void vZeichnen(const Weg&) override;
		double getConsumpt(void) const override{return p_dVerbrauch;}
		double getVolume(void) const{return p_dTankvolumen;}
		double getFuellevel(void) const{return p_dTankinhalt;}
		void setFuellevel(double dTankinhalt){p_dTankinhalt=dTankinhalt;}
};

#endif // PKW_H
