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

	void vTest(void);
	void vAufgabe_4(void);
	void vAufgabe_5(void);
	void vAufgabe_6(void);
	void vAufgabe_6a(void);
	void vAufgabe_7(void);
	std::cout << "Starting Vehicle Simulator 1923" << std::endl;

	dGlobaleZeit = 1;

	vAufgabe_7();

	return 0;
}

void vTest(void){
	for (int i = 0; i<20; i++) std::cout << rand()%6;
}

void vAufgabe_4(void){
	Weg weg1 = Weg("B5600000000000", 5000, Tempolimit::Innerorts);
	Weg weg2 = Weg("B56", 10000);

	weg1.vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 350),randDouble(4, 20),randDouble(30, 200)));
	weg1.vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(25,40)));
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

				dGlobaleZeit += 0.8;
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

void vAufgabe_7(void){
	std::shared_ptr<Kreuzung> Kr1 = std::make_shared<Kreuzung>("Kreuzung 1");
	std::shared_ptr<Kreuzung> Kr2 = std::make_shared<Kreuzung>("Kreuzung 2", 1000);
	std::shared_ptr<Kreuzung> Kr3 = std::make_shared<Kreuzung>("Kreuzung 3");
	std::shared_ptr<Kreuzung> Kr4 = std::make_shared<Kreuzung>("Kreuzung 4");


	Kreuzung::vVerbinde("B1_S", "B1_N", 260, std::weak_ptr<Kreuzung>(Kr1), std::weak_ptr<Kreuzung>(Kr2), Tempolimit::Landstraße);
	Kreuzung::vVerbinde("A2_S", "A2_N", 768.924, std::weak_ptr<Kreuzung>(Kr2), std::weak_ptr<Kreuzung>(Kr3));
	Kreuzung::vVerbinde("I3_S", "I3_N", 270, std::weak_ptr<Kreuzung>(Kr2), std::weak_ptr<Kreuzung>(Kr3), Tempolimit::Innerorts);
	Kreuzung::vVerbinde("I4_W", "I4_O", 360, std::weak_ptr<Kreuzung>(Kr2), std::weak_ptr<Kreuzung>(Kr4), Tempolimit::Innerorts);
	Kreuzung::vVerbinde("B5_W", "B5_O", 556.423, std::weak_ptr<Kreuzung>(Kr3), std::weak_ptr<Kreuzung>(Kr4), Tempolimit::Landstraße);
	Kreuzung::vVerbinde("A6_W", "A6_N", 845.809, std::weak_ptr<Kreuzung>(Kr4), std::weak_ptr<Kreuzung>(Kr4));

	int B1 [4] = {680, 40, 680, 300};
	int A2 [12] = {680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	int I3 [4] = {680, 300, 680, 570};
	int I4 [4] = {680, 300, 320, 300};
	int B5 [10] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300};
	int A6 [14] = {320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300};

	bInitialisiereGrafik(1000, 700);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	bZeichneStrasse("B1_S", "B1_N", 260, 2, B1);
	bZeichneStrasse("A2_S", "A2_N", 768.924, 6, A2);
	bZeichneStrasse("I3_S", "I3_N", 270, 2, I3);
	bZeichneStrasse("I4_W", "I4_O", 360, 2, I4);
	bZeichneStrasse("B5_W", "B5_O", 556.423, 5, B5);
	bZeichneStrasse("A6_W", "A6_N", 845.809, 7, A6);

	Kr1->vAnnahme(std::make_unique<PKW>("Mercedes", randDouble(50, 200), randDouble(4, 15),randDouble(90, 130)),3);
//	Kr1->vAnnahme(std::make_unique<PKW>("Audi", randDouble(50, 120), randDouble(4, 15),randDouble(80, 90)),3);
	Kr2->vAnnahme(std::make_unique<PKW>("Jaguar", randDouble(50, 340), randDouble(4, 15),randDouble(90, 130)),3);
	Kr3->vAnnahme(std::make_unique<Fahrrad>("MTB", randDouble(12,40)),3);
	Kr4->vAnnahme(std::make_unique<PKW>("BMW", randDouble(50, 100), randDouble(4, 15),randDouble(90, 130)),3);

	for(int i=0; i<100; i++){

		vSetzeZeit(dGlobaleZeit);

		Kr1->vSimulieren();
		Kr2->vSimulieren();
		Kr3->vSimulieren();
		Kr4->vSimulieren();


		dGlobaleZeit += 0.2;

		vSleep(100);
	}

	std::string s;
	std::cin >> s;

	std::cout<<"Stopping"<<std::endl;

}

