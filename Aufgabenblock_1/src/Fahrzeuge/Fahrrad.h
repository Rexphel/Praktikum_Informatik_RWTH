//============================================================================
// Name        : Aufgabenblock_1.cpp
// Author      : Philip Rexroth
// Version     : 0.0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for PKW in Vehicle Sim 1923
//============================================================================

class Fahrrad : public Fahrzeug{
	private:
	public:
		double dGeschwindigkeit(void);
};

double Fahrrad::dGeschwindigkeit(void){
	double dSpeed = getMaxSpeed()*((getTotalDistance()*0.01)+1);			//x*0.01+1 is the formula to get the wanted delta
	return dSpeed>12 ? dSpeed:12;
}
