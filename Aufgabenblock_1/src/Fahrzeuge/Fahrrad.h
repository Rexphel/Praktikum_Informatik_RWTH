//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for Fahrrad in Vehicle Sim 1923
//============================================================================

std::string setStringlength(long long lengt, std::string s);

class Fahrrad : public Fahrzeug{
	private:
		Fahrrad(const Fahrrad&) = delete;			//Do not allow Copy Constructor
	public:
		Fahrrad(std::string s, double d);
		Fahrrad operator=(const Fahrrad& f){return Fahrrad(f.p_sName,f.p_dMaxGeschwindigkeit);}

		double dGeschwindigkeit(void)const;
};

Fahrrad::Fahrrad(std::string s, double d) : Fahrzeug(setStringlength(14, s), (d>0 ? d:0)){} 		//Check if d is smaller than 0 (i.e. negative), set it to 0. Could also use std::abs(d) to set it to remove the -. Depends on application. Use of setStringlength to keep the name sting from breaking the output


double Fahrrad::dGeschwindigkeit(void) const{
	double dSpeed = getMaxSpeed()*(getTotalDistance()*-0.01+1);			//x*0.01+1 is the formula to get the wanted delta
	return dSpeed>12 ? dSpeed:12;
}

