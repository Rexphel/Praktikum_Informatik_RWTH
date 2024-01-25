//============================================================================
// Name        : Kreuzung.cpp
// Author      : Philip Rexroth
// Version     : 0.6
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Memberfunctions for junctions in Vehicle Sim 1923
//============================================================================

#include "../headers/Kreuzung.hpp"

#include "../headers/Weg.hpp"
#include "../../Vehicle/headers/Fahrzeug.hpp"

void Kreuzung::vVerbinde(std::string sNameWegHin, std::string sNameWegRück, double dWegLänge, std::weak_ptr<Kreuzung> kKreuzungStart, std::weak_ptr<Kreuzung> kKreuzungEnd, Tempolimit tTempolimit, bool bÜberholverbot){

	std::shared_ptr<Weg> wegHin = std::make_shared<Weg>(sNameWegHin, dWegLänge, tTempolimit, kKreuzungEnd);
	std::shared_ptr<Weg> wegRück = std::make_shared<Weg>(sNameWegRück, dWegLänge, tTempolimit, kKreuzungStart);

	wegHin->setRückweg(wegRück);
	wegRück->setRückweg(wegHin);

	kKreuzungStart.lock()->p_pWege.push_back(move(wegHin));
	kKreuzungEnd.lock()->p_pWege.push_back(move(wegRück));

}

void Kreuzung::vTanken(Fahrzeug& aFzg){
	if(p_dTankstelle>0){
		double volume = aFzg.dTanken();
		p_dTankstelle = p_dTankstelle-volume>0 ? p_dTankstelle-volume:0;
	}
}

void Kreuzung::vSimulieren(void){
	for(std::shared_ptr<Weg>& weg : p_pWege){
		weg->vSimulieren();
		weg->vAusgeben();
	}
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> aFzg, double startZeit){
	p_pWege.begin()->get()->vAnnahme(move(aFzg),startZeit);
}

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& iWeg){
	if(p_pWege.size()==1){return *p_pWege.begin();}
	std::shared_ptr<Weg> rndWeg = nullptr;
	while(rndWeg==nullptr){
		int index = rand()%p_pWege.size();
		std::list<std::shared_ptr<Weg>>::iterator it = std::next(p_pWege.begin(), index);
		if(it->get()==iWeg.getRückwet().get()){continue;}
		rndWeg = *it;
	}

	return rndWeg;

}
