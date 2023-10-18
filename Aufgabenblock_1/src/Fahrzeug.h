//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================
#include <string>
#include <iostream>

class Fahrzeug{
	protected:
		static inline int p_iMaxID=0;
	private:
		const std::string p_sName = "";				//Default Name is Empty Sting
		const int p_iID = p_iMaxID + 1;				//Given Object ID is the current MAX ID + 1
		Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
	public:
		Fahrzeug();
		Fahrzeug(std::string p_sName);
		virtual ~Fahrzeug();
		std::string getName(void);
		int getID(void);

};

Fahrzeug::Fahrzeug(void){							//Default Constructor
	std::cout << "Vehicle n." << p_iID << " is being created" << std::endl;
	Fahrzeug::p_iMaxID++;

};

Fahrzeug::Fahrzeug(std::string s) : p_sName(s){		//
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

