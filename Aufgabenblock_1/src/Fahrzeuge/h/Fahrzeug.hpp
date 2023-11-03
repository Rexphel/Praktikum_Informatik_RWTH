//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.6
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef Fahrzeug_H
#define Fahrzeug_H

#include <string>
#include <iostream>
#include <iomanip>

class Fahrzeug{
	protected:
		static inline int p_iMaxID = 0;
		const std::string p_sName = "";				//Default Name is Empty Sting
		const int p_iID = p_iMaxID + 1;				//Given Object ID is the current MAX ID + 1
		const double p_dMaxGeschwindigkeit = 0.0;
		double p_dGesamtStrecke = 0.0;
		double p_dGesamtZeit = 0.0;
		double p_dZeit = 0.0;
	private:
		Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
        friend std::ostream & operator<<(std::ostream& o, const Fahrzeug& x);
	public:
		Fahrzeug();
		Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
		virtual ~Fahrzeug();
		Fahrzeug operator=(const Fahrzeug& f){return Fahrzeug(f.p_sName,f.p_dMaxGeschwindigkeit);}
		std::string getName(void){return p_sName;}
		int getID(void){return p_iID;}
		double getMaxSpeed(void) const{return p_dMaxGeschwindigkeit;}
		double getTotalDistance(void) const{return p_dGesamtStrecke;}
		double getTotalTime(void) const{return p_dGesamtZeit;}
		double getLastTime(void) const{return p_dZeit;}
		void setTotalDistance(double d){p_dGesamtStrecke=d;}
		void setTotalTime(double d){p_dGesamtZeit=d;}
		void setLastTime(double d){p_dZeit=d;}
		void vincrMaxID(void){p_iMaxID++;}
		virtual void vSimulieren();
		virtual double dGeschwindigkeit()const {return p_dMaxGeschwindigkeit;};
		virtual double dTanken(void){return 0.0;}
		virtual void vAusgeben(std::ostream& out) const;
		static void vKopf(void);

};

#endif // Fahrzeug_H
