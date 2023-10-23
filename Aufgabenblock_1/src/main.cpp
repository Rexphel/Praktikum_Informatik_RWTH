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

extern const double dGlobaleZeit;

int main() {

	void vAufgabe_1();
	void vAufgabe_1_verbose();

	std::cout << "Starting Vehicle Simulator 1923" << std::endl;

	vAufgabe_1();

	return 0;
}

void vAufgabe_1(){
	Fahrzeug VW("Golf", 50.0);
	Fahrzeug BMW("i5", 150.0);
	Fahrzeug *Mercedes = new Fahrzeug("B-Klasse", 100.0);
	Fahrzeug *Mini = new Fahrzeug("Cooper" ,85.53);
	Fahrzeug *Empty = new Fahrzeug();

	for (auto &p : {Mercedes, Mini, Empty}){
		delete p;
	};

	std::vector<std::unique_ptr<Fahrzeug>> u_vFahrzeuge;																//Only able to store unique_ptr<Fahrzeuge>... like declared?
	std::vector<std::shared_ptr<Fahrzeug>> s_vFahrzeuge;

	std::unique_ptr<Fahrzeug> Benz = std::make_unique<Fahrzeug>("AMG", 200.9);
	std::unique_ptr<Fahrzeug> LWK = std::make_unique<Fahrzeug>("Axor",30.2);
	u_vFahrzeuge.push_back(move(Benz));																					//Move declares the change of ownership. It does not destroy the object. The original Pointer is set to NULL.
	u_vFahrzeuge.push_back(move(LWK));
	std::shared_ptr<Fahrzeug> Tesla = std::make_shared<Fahrzeug>("Model Y", 180.574);
	std::shared_ptr<Fahrzeug> Fiat = std::make_shared<Fahrzeug>("500", 60.32);

	auto ptr_Tesla = std::make_shared<std::shared_ptr<Fahrzeug>>(Tesla);																					//No move needed, due to shared_ptr being able to have multiple references/"owners"

	s_vFahrzeuge.push_back(move(Tesla));

	s_vFahrzeuge.push_back(Fiat);

	std::unique_ptr<std::unique_ptr<Fahrzeug>> ptr_Benz = std::make_unique<std::unique_ptr<Fahrzeug>>(move(Benz));		//Required to move the unique_ptr due to inheritance rules. After move into the array, the pointer Benz ponits to Null. Therfore ptr_Benz points to Null. (Possible Risk of unexpected behavior due to technically unknown bytes at Benz)

	u_vFahrzeuge.clear();																								//Object Fahrzeug is only destroyed when the reference has been destroyed. Therefore the deconstructor is called here.
	s_vFahrzeuge.clear();

	BMW.vAusgeben();

}

void vAufgabe_1_verbose(){

	Fahrzeug VW("Golf", 50.0);
	Fahrzeug BMW("i5", 150.0);
	Fahrzeug *Mercedes = new Fahrzeug("B-Klasse", 100.0);
	Fahrzeug *Mini = new Fahrzeug("Cooper" ,85.53);
	Fahrzeug *Empty = new Fahrzeug();

	for (auto &p : {Mercedes, Mini, Empty}){
		delete p;
	};

	std::vector<std::unique_ptr<Fahrzeug>> u_vFahrzeuge;																//Only able to store unique_ptr<Fahrzeuge>... like declared?
	std::vector<std::shared_ptr<Fahrzeug>> s_vFahrzeuge;																//Only able to again store shared_ptr<Fahrzeuge> due to the declaration.

	std::unique_ptr<Fahrzeug> Benz = std::make_unique<Fahrzeug>("AMG", 200.9);
	std::unique_ptr<Fahrzeug> LWK = std::make_unique<Fahrzeug>("Axor",30.2);
	u_vFahrzeuge.push_back(move(Benz));																					//Move declares the change of ownership. It does not destroy the object. The original Pointer is set to NULL.
	u_vFahrzeuge.push_back(move(LWK));
	std::shared_ptr<Fahrzeug> Tesla = std::make_shared<Fahrzeug>("Model Y", 180.574);
	std::shared_ptr<Fahrzeug> Fiat = std::make_shared<Fahrzeug>("500", 60.32);


	std::cout << "Tesla ref " << Tesla.use_count() << " " << Tesla->getName() << std::endl;
	auto ptr_Tesla = std::make_shared<std::shared_ptr<Fahrzeug>>(Tesla);																					//No move needed, due to shared_ptr being able to have multiple references/"owners"
	std::cout << "Tesla ref " << Tesla.use_count() << " " << Tesla->getName() << std::endl;

	std::cout << "Addresses: " << std::addressof(Tesla)<< " " << std::addressof(ptr_Tesla)<< " " << ptr_Tesla.get()<< std::endl;

	s_vFahrzeuge.push_back(move(Tesla));

	std::cout << "Tesla null " << (Tesla==NULL) << std::endl;															//Pointers after a move point to Null

	std::cout << "ptr_Tesla ref " << ptr_Tesla.use_count() << " " << ptr_Tesla->get()->getName() << std::endl;			//Even after move, ptr_Tesla still has the Values for the Tesla Object. Therefore it now points to s_vFahrzeuge[Tesla]

	std::cout << "Tesla ref " << Tesla.use_count() << std::endl;														//After move in Array Tesla is empty/"elsewhere" and therefore the refrences are 0
	std::cout << s_vFahrzeuge[0].get() << std::endl;

	std::cout << "Fiat ref " << Fiat.use_count() << std::endl;
	s_vFahrzeuge.push_back(Fiat);
	std::cout << "Fiat ref " << Fiat.use_count() << std::endl;
	Fiat = NULL;

	std::unique_ptr<std::unique_ptr<Fahrzeug>> ptr_Benz = std::make_unique<std::unique_ptr<Fahrzeug>>(move(Benz));		//Required to move the unique_ptr due to inheritance rules. After move into the array, the pointer Benz ponits to Null. Therfore ptr_Benz points to Null. (Possible Risk of unexpected behavior due to technically unknown bytes at Benz)

	std::cout << "ptr_Benz null " << (ptr_Benz==NULL) << std::endl;


	u_vFahrzeuge.clear();																								//Object Fahrzeug is only destroyed when the reference has been destroyed. Therefore the deconstructor is called here.
	s_vFahrzeuge.clear();																								//Object referenced to via a shared are not destroyed, unless every other reference is removed. Thats the case for Fiat. Therefore its dconstructor is called.

	ptr_Tesla = NULL;																									//As soon as the last reference is removed, Tesla is also destroyed and the deconstructor is called.

	BMW.vAusgeben();
}
