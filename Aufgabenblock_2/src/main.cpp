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
	void vAufgabe_6a(void);

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
	Weg weg1 ("B56_O", 500, Tempolimit::Innerorts);
	Weg weg2 ("B56_W", 500);

	weg1.vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)));
	weg1.vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(12,40)));
	weg2.vAnnahme(std::make_unique<PKW>("Mercedes", randDouble(50, 120), randDouble(4, 15),randDouble(80, 200)),3);


	Weg::vKopf();
	PKW::vLinie(50);
	std::cout << weg1 << std::endl;
	std::cout << weg2 << std::endl;

	bInitialisiereGrafik(800, 500);
	int i [4]= { 700, 250, 100, 250 };
	bZeichneStrasse("B56_O", "B56_W", 500, 2, i);
	vSetzeZeit(dGlobaleZeit);

	for(int i=0; i<50; i++){
		PKW::vKopf();
		weg1.vAusgeben();
		weg2.vAusgeben();

		weg1.vSimulieren();
		weg2.vSimulieren();

		dGlobaleZeit += 0.4;

		vSetzeZeit(dGlobaleZeit);
		vSleep(1000);
	}

	std::cout<<"Stopping"<<std::endl;

	std::string s;
	std::cin >> s;
}

void vAufgabe_6a(void){
	std::list<int> l(10);
	std::iota(l.begin(), l.end(), 1);
	vertagt::VListe<int> testNum (l);

	std::cout<<"Ausgabe 1 (init)"<<std::endl;

	for (auto& item : testNum){
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	for (auto iter = testNum.begin(); iter != testNum.end(); ++iter){
		if(*iter>5){
			testNum.erase(iter);
		}
	}

	std::cout<<"Ausgabe 2 (Löschen eingereiht)"<<std::endl;
	for (auto& item : testNum){
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	testNum.vAktualisieren();

	std::cout<<"Ausgabe 3 (Liste Aktuallisiert)"<<std::endl;
	for (auto& item : testNum){
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	testNum.push_back((int)randDouble(0,100));
	testNum.push_front((int)randDouble(0,100));

	std::cout<<"Ausgabe 4 (Zufalllszahlen Erzeugt)"<<std::endl;
	for (auto& item : testNum){
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	testNum.vAktualisieren();

	std::cout<<"Ausgabe 5 (Liste Aktualisiert)"<<std::endl;
	for (auto& item : testNum){
		std::cout << item << ", ";
	}
	std::cout << std::endl;
}
