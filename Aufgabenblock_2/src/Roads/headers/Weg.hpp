//============================================================================
// Name        : Fahrrad.cpp
// Author      : Philip Rexroth
// Version     : 0.2
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Weg in Vehicle Sim 1923
//============================================================================

#ifndef ROADS_HEADERS_WEG_HPP_
#define ROADS_HEADERS_WEG_HPP_

#include <list>
#include <memory>

#include "Tempolimit.hpp"
#include "../../Simulationsobjekt.hpp"
#include "../../VListe/vertagt_liste.h"

class Fahrzeug;
class Kreuzung;

class Weg : public Simulationsobjekt {
	private:
		Weg(const Weg&) = delete;			//Do not allow Copy Constructor
		friend std::ostream& operator<<(std::ostream &o, const Weg &x);
	protected:
		const double p_dLaenge;
		Tempolimit p_eTempolimit;
		vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
		std::weak_ptr<Weg> p_wRückweg;
		const std::weak_ptr<Kreuzung> p_kKreuzung;
	public:
		Weg();
		Weg(std::string s, double länge, Tempolimit limit= Tempolimit::Autobahn, std::weak_ptr<Kreuzung> kKreuzung=std::weak_ptr<Kreuzung>());
		virtual ~Weg();
		void vSimulieren(void) override;
		void vAusgeben(void);
		void vAusgeben(std::ostream& s)const override;
		static void vKopf(void);
		void vAnnahme(std::unique_ptr<Fahrzeug> f);
		void vAnnahme(std::unique_ptr<Fahrzeug> f, double dStartZeit);
		std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug&);
		void vTanken(double vol=0);
		void vTanken(int iter, double vol=0);
		void vFahren(int iter, Weg& );
		void printTank(void);
		double vGetSpeedLimit(void);
		double getLength(void) const {return p_dLaenge;}
		double getSpeedLimit(void) const {return static_cast<int>(p_eTempolimit); }
		std::unique_ptr<Fahrzeug> popFahrzeug(int iter);
		std::shared_ptr<Weg> getRückwet(void)	{return p_wRückweg.lock();}
		std::shared_ptr<Kreuzung> getKreuzung(void) const {return p_kKreuzung.lock();}
		void setRückweg(std::weak_ptr<Weg> weg) {p_wRückweg=weg;}
};



#endif /* ROADS_HEADERS_WEG_HPP_ */
