//============================================================================
// Name        : FreeFunctions.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Main Class for Simulationsobjekte for Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_H_SIMULATIONSOBJEKT_HPP_
#define OBJECTS_H_SIMULATIONSOBJEKT_HPP_

#include <iostream>
#include <iomanip>
#include <string>

class Simulationsobjekt{
	private:
		Simulationsobjekt() = delete;
		Simulationsobjekt(const Simulationsobjekt&) = delete;			//Do not allow Copy Constructor
	protected:
		Simulationsobjekt(std::string name);
		virtual ~Simulationsobjekt();
		static inline int p_iMaxID = 0;
		const std::string p_sName;
		const int p_iID = p_iMaxID + 1;				//Given Object ID is the current MAX ID + 1
		double p_dZeit = 0.0;
	public:
		void setLastTime(double d){p_dZeit=d;}
		int getID(void){return p_iID;}
		std::string getName(void){return p_sName;}
        friend std::ostream& operator<<(std::ostream& o, const Simulationsobjekt& x);
        friend bool operator==(const Simulationsobjekt& x, const Simulationsobjekt& y);
		double getLastTime(void) const{return p_dZeit;}
		void vincrMaxID(void){p_iMaxID++;}
		virtual void vSimulieren() = 0;
		virtual void vAusgeben(std::ostream& out) const;
		static void vKopf(void);
		static void vLinie(int length);

};

#endif /* OBJECTS_H_SIMULATIONSOBJEKT_HPP_ */
