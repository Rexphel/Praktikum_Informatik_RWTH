//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.5
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for PKW in Vehicle Sim 1923
//============================================================================

#include <string>

extern double dGlobaleZeit;

std::string setStringlength(long long lengt, std::string s);

class PKW : public Fahrzeug{

	private:
		double p_dVerbrauch = 0.0;
		double p_dTankvolumen;
		double p_dTankinhalt = 0.0;
		PKW(const PKW&) = delete;			//Do not allow Copy Constructor
	public:
		PKW() = delete;
		PKW(std::string sName, double dMaxSpeed, double dconsuption, double dMaxFuel);
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

PKW::PKW(std::string sName, double dMaxSpeed, double dconsuption, double dMaxFuel = 55) : Fahrzeug(setStringlength(14, sName), (dMaxSpeed>0 ? dMaxSpeed:0)), p_dVerbrauch(dconsuption), p_dTankvolumen(dMaxFuel), p_dTankinhalt(dMaxFuel/2){}

void PKW::vSimulieren(void){
	double ddeltaTime = dGlobaleZeit - Fahrzeug::getLastTime();
	double dusedFuel = getConsumpt()*ddeltaTime;
	double dFuelratio = getFuellevel()!=0 ? 1:0;
	//double dFuelratio = getFuellevel()/dusedFuel<1 ? getFuellevel()/dusedFuel:1;				// More precise calculation.... commented out due to the assignment speciffically asking to.
	double ddeltaFuel = getFuellevel()-dusedFuel;
	Fahrzeug::setTotalDistance(getTotalDistance()+ dGeschwindigkeit()*ddeltaTime*dFuelratio);
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

std::ostream& operator<<(std::ostream& o, const PKW& x){											//another definition needed, for each class
	x.vAusgeben(o);
	return o;
}

void PKW::vKopf(void){
	PKW::Fahrzeug::vKopf();
	std::cout.width(16);
	std::cout << std::setiosflags(std::ios::right) << "Fuellevel" ;
	std::cout.width(17);
	std::cout << "Used Fuel" << "\n" << std::resetiosflags(std::ios::right);
	std::cout << std::setfill('-') << std::setw(120)<<"\n" << std::setfill(' ');
}

