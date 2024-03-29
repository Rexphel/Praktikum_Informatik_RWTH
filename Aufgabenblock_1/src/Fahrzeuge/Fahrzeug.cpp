//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for Class Vehicles in Vehicle Sim 1923
//============================================================================

#include "h/Fahrzeug.hpp"

#define DEBUG

extern double dGlobaleZeit;

std::string setStringlength(long long lengt, std::string s);

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif


Fahrzeug::Fahrzeug(void){							//Default Constructor
	DEBUG_MSG("Vehicle n." << p_iID << " is being created");
	Fahrzeug::vincrMaxID();

};

Fahrzeug::Fahrzeug(std::string s, double d): p_sName(setStringlength(14, s)), p_dMaxGeschwindigkeit(d>0 ? d:0){		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output
	DEBUG_MSG("Vehicle  n." << p_iID << s << " is being created");
	Fahrzeug::vincrMaxID();
};

Fahrzeug::~Fahrzeug(void) {
   DEBUG_MSG("Vehicle n."+std::to_string(Fahrzeug::getID())+" Name:"+Fahrzeug::getName()+" is being deleted");
};

std::ostream& operator <<(std::ostream& o, const Fahrzeug& x){
	x.vAusgeben(o);
	return o;
}

void Fahrzeug::vSimulieren() {
	double ideltaTime = dGlobaleZeit - getLastTime();
	Fahrzeug::setTotalDistance(getTotalDistance()+ dGeschwindigkeit()*ideltaTime);
	Fahrzeug::setTotalTime(getTotalTime()+ideltaTime);
	Fahrzeug::setLastTime(dGlobaleZeit);
}

void Fahrzeug::vAusgeben(std::ostream& out) const{
	out.width(4);																					//4 Space for IDs
	std::resetiosflags(std::ios::left);																	//Reset alignment
	out << std::setiosflags(std::ios::right) << std::to_string(p_iID) << std::resetiosflags(std::ios::right);		//Output p_iID right aligned
	out.width(2);std::cout << "";																	//Create 2 Space between ID and Name
	out.width(15);																				//15 Space for Name. (Name max 15 Chars)
	out << std::setiosflags(std::ios::left) << p_sName << std::resetiosflags(std::ios::left);		//Output p_sName left aligned
	out.width(12);																				//12 Space for MaxSpeed
	out << std::setiosflags(std::ios::right) << p_dMaxGeschwindigkeit;									//Output p_dMaxGeschwindigkeit right aligned
	out.width(20);																				//20 space for Current Speed
	out << dGeschwindigkeit();																	//Output current Speed right aligned
	out.width(20);																				//20 space for TotalDistance
	out << p_dGesamtStrecke << std::resetiosflags(std::ios::right);								//Output p_dGesammtStrecke right aligned
}

bool operator <(const Fahrzeug& x, const Fahrzeug& y){
	if(x.getTotalDistance()<y.getTotalDistance()){
		return true;
	}
	return false;
}


void Fahrzeug::vKopf(void){
	std::cout.width(6);
	std::resetiosflags(std::ios::right);
	std::cout << std::setiosflags(std::ios::left) << "ID";
	std::cout.width(10);
	std::cout << "Name" << std::resetiosflags(std::ios::left);
	std::cout.width(17);
	std::cout << std::setiosflags(std::ios::right) << "MaxSpeed" ;
	std::cout.width(20);
	std::cout << "Current Speed";
	std::cout.width(20);
	std::cout << "TotalDistance" << std::resetiosflags(std::ios::right);
//	std::cout << std::setfill('-') << std::setw(55)<<"\n" << std::setfill(' ');

}
