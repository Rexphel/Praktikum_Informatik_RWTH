//============================================================================
// Name        : Kreuzung.hpp
// Author      : Philip Rexroth
// Version     : 0.6
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for junctions in Vehicle Sim 1923
//============================================================================

#ifndef ROADS_HEADERS_KREUZUNG_HPP_
#define ROADS_HEADERS_KREUZUNG_HPP_

#include "../../Simulationsobjekt.hpp"
#include "Tempolimit.hpp"
#include "Weg.hpp"

class Kreuzung : public Simulationsobjekt{
	private:
		std::list<std::shared_ptr<Weg>> p_pWege;
		double p_dTankstelle;
	public:
		Kreuzung()=delete;
		Kreuzung(std::string s, double dTankstelle=0) : Simulationsobjekt(s), p_dTankstelle(dTankstelle){};
		static void vVerbinde(std::string sNameWegHin, std::string sNameWegRück, double dWegLänge, std::weak_ptr<Kreuzung> kKreuzungStart, std::weak_ptr<Kreuzung> kKreuzungEnd, Tempolimit tTempolimit=Tempolimit::Autobahn, bool bÜberholverbot=false);
		void vTanken(Fahrzeug&);
		void vSimulieren(void);
		void vAnnahme(std::unique_ptr<Fahrzeug> aFzg, double Starttime);
		std::shared_ptr<Weg> pZufaelligerWeg(Weg&);
		double getTankstelleninhalt(void) {return p_dTankstelle;}
};

#endif /* ROADS_HEADERS_KREUZUNG_HPP_ */
