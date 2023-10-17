//============================================================================
// Name        : main.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Main file for Vehicle Simulator 1923
//============================================================================

#include <iostream>
#include <string>
#include "Fahrzeug.h"

int main() {
	void vAufgabe_1();

	std::cout << "Starting Vehicle Simulator 1923" << std::endl;

	vAufgabe_1();

	return 0;
}

void vAufgabe_1(){

	Fahrzeug VW("Golf");
	Fahrzeug BMW("i5");
	Fahrzeug *Mercedes = new Fahrzeug("B-Klasse");
	Fahrzeug *Mini = new Fahrzeug("Cooper");
	Fahrzeug *Empty = new Fahrzeug();
	for (auto &p : {Mercedes, Mini, Empty}){
		delete p;
	};
}
