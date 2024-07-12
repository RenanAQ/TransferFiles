/*
Student: Renan de Alencar Queiroz
ID: 129280236
Email: rde-alencar-queiroz@myseneca.ca
Date: 2024-07-11
*/

#ifndef SENECA_TRUCK_H__
#define SENECA_TRUCK_H__
#include "MotorVehicle.h"

namespace seneca {

	class Truck: public MotorVehicle
	{
		double m_capacity;
		double m_cargoLoad;

	public:
		Truck(const char* plate, int year, double capacity, const char* currentAddress);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	
	std::ostream& operator<<(std::ostream& os, const Truck& RO);
	std::istream& operator>>(std::istream& is, Truck& RO);

}
#endif
