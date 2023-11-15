//============================================================================
// Name        : Simulationsobjekt.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Functions for Simulationsobjekt in Vehicle Sim 1923
//============================================================================

#include "Simulationsobjekt.hpp"

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

std::string setStringlength(long long lengt, std::string s);

Simulationsobjekt::Simulationsobjekt(std::string s): p_sName(setStringlength(14, s)){
	DEBUG_MSG("Vehicle n." << p_iID << " is being created");
	Simulationsobjekt::vincrMaxID();

}
Simulationsobjekt::~Simulationsobjekt(){
	DEBUG_MSG("Vehicle n."+std::to_string(Fahrzeug::getID())+" Name:"+Fahrzeug::getName()+" is being deleted");

}

bool operator==(const Simulationsobjekt& x, const Simulationsobjekt& y){
	return x.p_iID == y.p_iID;
}

std::ostream& operator <<(std::ostream& o, const Simulationsobjekt& x){
	x.vAusgeben(o);
	return o;
}

void Simulationsobjekt::vAusgeben(std::ostream& out) const{
	out.width(4);																					//4 Space for IDs
	std::resetiosflags(std::ios::left);																	//Reset alignment
	out << std::setiosflags(std::ios::right) << std::to_string(p_iID) << std::resetiosflags(std::ios::right);		//Output p_iID right aligned
	out.width(2);std::cout << "";																	//Create 2 Space between ID and Name
	out.width(15);																				//15 Space for Name. (Name max 15 Chars)
	out << std::setiosflags(std::ios::left) << p_sName << std::resetiosflags(std::ios::left);		//Output p_sName left aligned
}
void Simulationsobjekt::vKopf(void){
	std::cout.width(6);
	std::resetiosflags(std::ios::right);
	std::cout << std::setiosflags(std::ios::left) << "ID";
	std::cout.width(10);
	std::cout << "Name" << std::resetiosflags(std::ios::left);
}
