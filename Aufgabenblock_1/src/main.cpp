//============================================================================
// Name        : main.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Main file for Vehicle Simulator 1923
//============================================================================

#include <iostream>
#include <string>
#include <memory>
#include <vector>
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

	std::vector<std::unique_ptr<Fahrzeug>> u_vFahrzeuge;																//Only able to store unique_ptr<Fahrzeuge>... like declared?
	std::vector<std::shared_ptr<Fahrzeug>> s_vFahrzeuge;																//Only able to again store shared_ptr<Fahrzeuge> due to the declaration.

	std::unique_ptr<Fahrzeug> Benz = std::make_unique<Fahrzeug>("AMG");
	std::unique_ptr<Fahrzeug> LWK = std::make_unique<Fahrzeug>("Axor");
	u_vFahrzeuge.push_back(move(Benz));																					//Move declares the change of ownership.
	u_vFahrzeuge.push_back(move(LWK));
	std::shared_ptr<Fahrzeug> Tesla = std::make_shared<Fahrzeug>("Model Y");
	std::shared_ptr<Fahrzeug> Fiat = std::make_shared<Fahrzeug>("500");
	s_vFahrzeuge.push_back(Tesla);																						//No move needed, due to shared_ptr being able to have multiple references/"owners"
	s_vFahrzeuge.push_back(Fiat);

	std::cout << Tesla.use_count() << std::endl;
	std::shared_ptr<std::shared_ptr<Fahrzeug>> ptr_Tesla = std::make_shared<std::shared_ptr<Fahrzeug>>(Tesla);
	std::cout << Tesla.use_count() << std::endl;

	std::unique_ptr<std::unique_ptr<Fahrzeug>> ptr_Benz = std::make_unique<std::unique_ptr<Fahrzeug>>(move(Benz));		//Required to move the unique_ptr due to inheritance rules.

	u_vFahrzeuge.clear();

}
