//============================================================================
// Name        : main.cpp
// Author      : Philip Rexroth
// Version     : 1.0
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Main file for Vehicle Simulator 1923
//============================================================================

#include "GlobalIncludes.hpp"

extern double dGlobaleZeit;

int main() {

	void vAufgabe_4(void);
	void vAufgabe_5(void);
	void vAufgabe_6(void);

	std::cout << "Starting Vehicle Simulator 1923" << std::endl;

	dGlobaleZeit = 1;

	vAufgabe_6();

	return 0;
}

void vAufgabe_4(void){
	Weg weg1 = Weg("B5600000000000", 5000, Tempolimit::Innerorts);
	Weg weg2 = Weg("B56", 10000);

	weg1.vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 350),randDouble(4, 20),randDouble(30, 200)));
	weg1.vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(12,40)));
	weg1.vAnnahme(std::make_unique<PKW>("Mercedes", randDouble(50, 350),randDouble(4, 20),randDouble(30, 200)));

	weg2.vAnnahme(weg1.popFahrzeug(1));

	Weg::vKopf();
	Weg::vLinie(50);
	std::cout << weg1 << std::endl;
	std::cout << weg2 << std::endl;

	std::string s;
	std::cin >> s;

}

void vAufgabe_5(void){
	Weg weg1 ("B5600000000000", 70, Tempolimit::Innerorts);
	Weg weg2 = Weg("B56", 200);

	weg1.vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)));
	weg1.vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(12,40)));
	weg1.vAnnahme(std::make_unique<PKW>("Mercedes", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)),3);

	weg2.vAnnahme(weg1.popFahrzeug(1));

	Weg::vKopf();
	PKW::vLinie(50);
	std::cout << weg1 << std::endl;
	std::cout << weg2 << std::endl;

	bool stop = false;
		while(!stop){
			PKW::vKopf();
			weg1.vAusgeben();
			weg2.vAusgeben();

			std::string s;
			std::cin >> s;

			if(s == "stop"){stop=true;}
			else if(s=="t"||s=="tanken"){
				weg1.vTanken();
			}
			else if(s=="f"||s=="fahren"){
				weg1.vFahren(0, weg1);
			}
			else if(s=="i"){
				weg1.printTank();
			}
			else{
				weg1.vSimulieren();
				weg2.vSimulieren();

				dGlobaleZeit += 0.4;
			}

//			console_clear_screen();

		}

}

void vAufgabe_6(void){
	Weg weg1 ("B5600000000000", 70, Tempolimit::Innerorts);
	Weg weg2 = Weg("B56", 200);

	weg1.vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)));
	weg1.vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(12,40)));
	weg1.vAnnahme(std::make_unique<PKW>("Mercedes", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)),3);

	weg2.vAnnahme(weg1.popFahrzeug(1));

	Weg::vKopf();
	PKW::vLinie(50);
	std::cout << weg1 << std::endl;
	std::cout << weg2 << std::endl;

	bool b = bInitialisiereGrafik(800, 500);

	for(int i=0; i<10; i++){
		PKW::vKopf();
		weg1.vAusgeben();
		weg2.vAusgeben();



		weg1.vSimulieren();
		weg2.vSimulieren();
		dGlobaleZeit += 0.4;
	}
}
