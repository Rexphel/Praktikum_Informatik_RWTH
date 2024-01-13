<<<<<<< Upstream, based on branch 'master' of https://github.com/Rexphel/Praktikum_Informatik_RWTH.git
//============================================================================
// Name        : Verhalten.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the behavior of Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_
#define OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_

class Weg;
class Fahrzeug;

class Verhalten{
	private:
		Verhalten(const Verhalten&)=delete;
	protected:
		Weg& weg;
	public:
		Verhalten()=delete;
		Verhalten(Weg& w);
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

};



#endif /* OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_ */
=======
//============================================================================
// Name        : Verhalten.hpp
// Author      : Philip Rexroth
// Version     : 0.1
// Copyright   : Copyright (c) 2023 Philip Rexroth
// Description : Class for the behavior of Vehicles in Vehicle Sim 1923
//============================================================================

#ifndef OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_
#define OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_

class Weg;
class Fahrzeug;

class Verhalten{
	private:
		Verhalten(const Verhalten&)=delete;
	protected:
		Weg& weg;
	public:
		Verhalten()=delete;
		Verhalten(Weg& w);
		double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

};



#endif /* OBJECTS_VEHICLE_HEADERS_VERHALTEN_HPP_ */
>>>>>>> 75c89d8 Merged with Laptop
