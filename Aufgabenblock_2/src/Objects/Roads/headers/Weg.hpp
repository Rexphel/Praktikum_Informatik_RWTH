//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Weg in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_ROADS_HEADERS_WEG_HPP_
#define OBJECTS_ROADS_HEADERS_WEG_HPP_

#include <list>
#include <memory>

#include "../../Vehicle/headers/Fahrzeug.hpp"
#include "Tempolimit.hpp"

class Weg : public Simulationsobjekt {
	private:
		Weg(const Weg&) = delete;			//Do not allow Copy Constructor
		friend std::ostream& operator<<(std::ostream &o, const Weg &x);
	protected:
		const double p_dLaenge;
		const Tempolimit p_eTempolimit;
		std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	public:
		Weg();
		Weg(std::string s, double länge, Tempolimit limit=Tempolimit::Autobahn);
		virtual ~Weg();
		double getLength(void){return p_dLaenge;}
		double getSpeedLimit(void){return getTempolimit(p_eTempolimit); }
		void vSimulieren(void) override;
		void vAusgeben(std::ostream& s)const override;
		static void vKopf(void);

};



#endif /* OBJECTS_ROADS_HEADERS_WEG_HPP_ */
