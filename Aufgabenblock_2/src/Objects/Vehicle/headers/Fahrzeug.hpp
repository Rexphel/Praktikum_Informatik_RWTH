//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef Fahrzeug_H
#define Fahrzeug_H

#include <string>
#include <iostream>
#include <iomanip>

#include "../../Simulationsobjekt.hpp"

class Fahrzeug: public Simulationsobjekt {
protected:
	const double p_dMaxGeschwindigkeit = 0.0;
	double p_dGesamtStrecke = 0.0;
	double p_dGesamtZeit = 0.0;
private:
	Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
	friend std::ostream& operator<<(std::ostream &o, const Fahrzeug &x);
public:
	Fahrzeug() = delete;
	Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
	Fahrzeug operator=(const Fahrzeug &f) {
		return Fahrzeug(f.p_sName, f.p_dMaxGeschwindigkeit);
	}
	int getID(void) {
		return p_iID;
	}
	double getMaxSpeed(void) const {
		return p_dMaxGeschwindigkeit;
	}
	double getTotalDistance(void) const {
		return p_dGesamtStrecke;
	}
	double getTotalTime(void) const {
		return p_dGesamtZeit;
	}
	void setTotalDistance(double d) {
		p_dGesamtStrecke = d;
	}
	void setTotalTime(double d) {
		p_dGesamtZeit = d;
	}
	void vSimulieren(void) override;
	static void vKopf(void);
	void vAusgeben(std::ostream &out) const override;
	virtual double dGeschwindigkeit() const {
		return p_dMaxGeschwindigkeit;
	}
	;
	virtual double dTanken(void) {
		return 0.0;
	}

};

#endif // Fahrzeug_H
