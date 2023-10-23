//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================
#include <string>
#include <iostream>
#include <iomanip>

const double dGlobaleZeit=0.0;


class Fahrzeug{
	protected:
		static inline int p_iMaxID = 0;
	private:
		const std::string p_sName = "";				//Default Name is Empty Sting
		const int p_iID = p_iMaxID + 1;				//Given Object ID is the current MAX ID + 1
		Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
		const double p_dMaxGeschwindigkeit = 0.0;
		double p_dGesamtStrecke = 0.0;
		double p_dZeit = 0.0;
	public:
		void vAusgeben(void);
		Fahrzeug();
		Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
		virtual ~Fahrzeug();
		std::string getName(void);
		int getID(void);

};

Fahrzeug::Fahrzeug(void){							//Default Constructor
	std::cout << "Vehicle n." << p_iID << " is being created" << std::endl;
	Fahrzeug::p_iMaxID++;

};

Fahrzeug::Fahrzeug(std::string s, double d): p_sName(s), p_dMaxGeschwindigkeit(d>0 ? d:0){		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application.
	std::cout << "Vehicle  n." << p_iID << s << " is being created" << std::endl;
	Fahrzeug::p_iMaxID++;
};

Fahrzeug::~Fahrzeug(void) {
   std::cout << "Vehicle n."+std::to_string(Fahrzeug::getID())+" Name:"+Fahrzeug::getName()+" is being deleted" << std::endl;
   Fahrzeug::p_iMaxID--;
};

std::string Fahrzeug::getName(void){
	return p_sName;
}

int Fahrzeug::getID(void){
	return p_iID;
}

void Fahrzeug::vAusgeben(void){
	void vKopf(int iWidth);

	int iWidth = 13;

	vKopf(iWidth);
}

void vKopf(int iWidth){
		std::cout << std::left << "ID" << std::setw(iWidth);
		std::cout << "Name" << std::setw(iWidth)
				<< "MaxSpeed"<< std::setw(1.5*iWidth);
		std::cout	<< "Total distance\n" <<std::endl;
		std::cout << std::setw(60) << std::setfill('-');
}
