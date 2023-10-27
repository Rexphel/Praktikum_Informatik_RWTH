//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Standard Class for Vehicles in Vehicle Sim 1923
//============================================================================
#include <string>
#include <iostream>
#include <iomanip>

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

double dGlobaleZeit = 0.0;

std::string setStringlengt(long long i, std::string s);

class Fahrzeug{
	protected:
		static inline int p_iMaxID = 0;
		const std::string p_sName = "";				//Default Name is Empty Sting
		const int p_iID = p_iMaxID + 1;				//Given Object ID is the current MAX ID + 1
		const double p_dMaxGeschwindigkeit = 0.0;
		double p_dGesamtStrecke = 0.0;
		double p_dGesamtZeit = 0.0;
		double p_dZeit = 0.0;
	private:
		Fahrzeug(const Fahrzeug&) = delete;			//Do not allow Copy Constructor
	public:
		Fahrzeug();
		Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
		virtual ~Fahrzeug();
		std::string getName(void){return p_sName;}
		int getID(void){return p_iID;}
		double getMaxSpeed(void){return p_dMaxGeschwindigkeit;}
		double getTotalDistance(void){return p_dGesamtStrecke;}
		double getTotalTime(void){return p_dGesamtZeit;}
		double getLastTime(void){return p_dZeit;}
		void setTotalDistance(double d){p_dGesamtStrecke=d;}
		void setTotalTime(double d){p_dGesamtZeit=d;}
		void setLastTime(double d){p_dZeit=d;}
		void vincrMaxID(void){p_iMaxID++;}
		virtual void vSimulieren(double dSpeed, double dDelta);
		virtual double dGeschwindigkeit(){return p_dMaxGeschwindigkeit;};
		virtual double dTanken(void){return 0.0;}
		virtual void vAusgeben(void);
		static void vKopf(void);

};

Fahrzeug::Fahrzeug(void){							//Default Constructor
	DEBUG_MSG("Vehicle n." << p_iID << " is being created");
	Fahrzeug::vincrMaxID();

};

Fahrzeug::Fahrzeug(std::string s, double d): p_sName(setStringlengt(14, s)), p_dMaxGeschwindigkeit(d>0 ? d:0){		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output
	DEBUG_MSG("Vehicle  n." << p_iID << s << " is being created");
	Fahrzeug::vincrMaxID();
};

Fahrzeug::~Fahrzeug(void) {
   DEBUG_MSG("Vehicle n."+std::to_string(Fahrzeug::getID())+" Name:"+Fahrzeug::getName()+" is being deleted");
};

std::string setStringlengt(long long i, std::string s){																//Function to set a given string to any given size
	s.resize(i,' ');
	return s;
}

void Fahrzeug::vSimulieren(double dSpeed, double dDelta=1) {
	double ideltaTime = dGlobaleZeit - getLastTime();
	Fahrzeug::setTotalDistance(getTotalDistance()+ dSpeed*ideltaTime*dDelta);
	Fahrzeug::setTotalTime(getTotalTime()+ideltaTime);
	Fahrzeug::setLastTime(dGlobaleZeit);
}

void Fahrzeug::vAusgeben(void){
	std::cout.width(4);																					//4 Space for IDs
	std::resetiosflags(std::ios::left);																	//Reset alignment
	std::cout << std::setiosflags(std::ios::right) << getID() << std::resetiosflags(std::ios::right);		//Output p_iID right aligned
	std::cout.width(2);std::cout << "";																	//Create 2 Space between ID and Name
	std::cout.width(15);																				//15 Space for Name. (Name max 15 Chars)
	std::cout << std::setiosflags(std::ios::left) << getName() << std::resetiosflags(std::ios::left);		//Output p_sName left aligned
	std::cout.width(12);																				//12 Space for MaxSpeed
	std::cout << std::setiosflags(std::ios::right) << getMaxSpeed();									//Output p_dMaxGeschwindigkeit right aligned
	std::cout.width(20);																				//20 space for Current Speed
	std::cout << dGeschwindigkeit();																	//Output current Speed right aligned
	std::cout.width(20);																				//20 space for TotalDistance
	std::cout << getTotalDistance() << std::resetiosflags(std::ios::right);								//Output p_dGesammtStrecke right aligned

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
