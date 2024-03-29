//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_VEHICLES_HEADERS_FAHRZEUG_HPP_
#define OBJECTS_VEHICLES_HEADERS_FAHRZEUG_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

#include "../../Vehicle/headers/Verhalten.hpp"
#include "../../Simulationsobjekt.hpp"
class Weg;

class Fahrzeug: public Simulationsobjekt {
	private:
		Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
		friend std::ostream& operator<<(std::ostream &o, const Fahrzeug &x);
	protected:
		const double p_dMaxGeschwindigkeit = 0.0;
		double p_dGesamtStrecke = 0.0;
		double p_dGesamtZeit = 0.0;
		double p_dAbschnittStrecke = 0.0;
		std::unique_ptr<Verhalten> p_pVerhalten;
	public:
		Fahrzeug() = delete;
		Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
		virtual ~Fahrzeug() {};
		Fahrzeug operator=(const Fahrzeug &f) {return Fahrzeug(f.p_sName, f.p_dMaxGeschwindigkeit);}
		void vSimulieren(void) override;
		static void vKopf(void);
		void vAusgeben(std::ostream &out) const override;
		void vUpdateDistance(double distance);
		virtual double dGeschwindigkeit() const {return p_dMaxGeschwindigkeit;}
		virtual double dTanken(void) {return 0.0;}
		virtual double dTanken(double dquantity) {return 0.0;}
		void vNeueStrecke(Weg& weg);
		void vNeueStrecke(Weg& weg, double dStartZeit);
		virtual void vZeichnen(const Weg&){};
		//Getter&Setter
		int getID(void) const {return p_iID;}
		double getMaxSpeed(void) const {return p_dMaxGeschwindigkeit;}
		double getTotalDistance(void) const {return p_dGesamtStrecke;}
		double getTotalTime(void) const {return p_dGesamtZeit;}
		double getAbschnittStrecke(void) const {return p_dAbschnittStrecke;}
		virtual double getConsumpt(void) const{return 0;}
		void setTotalDistance(double d) {p_dGesamtStrecke = d;}
		void setTotalTime(double d) {p_dGesamtZeit = d;}
		void setVerhalten(std::unique_ptr<Verhalten> verhalten){p_pVerhalten = move(verhalten);}
};

#endif // OBJECTS_VEHICLES_HEADERS_FAHRZEUG_HPP_
