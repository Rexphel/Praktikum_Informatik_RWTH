//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.2
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Weg in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_ROADS_HEADERS_WEG_HPP_
#define OBJECTS_ROADS_HEADERS_WEG_HPP_

#include <list>
#include <memory>

#include "../../Simulationsobjekt.hpp"
#include "Tempolimit.hpp"

class Fahrzeug;

class Weg : public Simulationsobjekt {
	private:
		Weg(const Weg&) = delete;			//Do not allow Copy Constructor
		friend std::ostream& operator<<(std::ostream &o, const Weg &x);
	protected:
		const double p_dLaenge;
		Tempolimit p_eTempolimit;
		std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	public:
		Weg();
		Weg(std::string s, double länge, Tempolimit limit= Tempolimit::Autobahn);
		virtual ~Weg();
		double getLength(void) const {return p_dLaenge;}
		double getSpeedLimit(void) const {return static_cast<int>(p_eTempolimit); }
		void pushFahrzeug(std::unique_ptr<Fahrzeug> f){p_pFahrzeuge.push_back(move(f));}
		std::unique_ptr<Fahrzeug> popFahrzeug(int iter);
		void vSimulieren(void) override;
		void vAusgeben(void);
		void vAusgeben(std::ostream& s)const override;
		static void vKopf(void);
		void vAnnahme(std::unique_ptr<Fahrzeug> f);
		void vAnnahme(std::unique_ptr<Fahrzeug> f, double dStartZeit);
		void vTanken(double vol=0);
		void vTanken(int iter, double vol=0);
		void vFahren(int iter, Weg& );
		double vGetSpeedLimit(void);
		void printTank(void);
};



#endif /* OBJECTS_ROADS_HEADERS_WEG_HPP_ */
