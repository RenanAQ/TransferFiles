/*
Student: Renan de Alencar Queiroz
ID: 129280236
Email: rde-alencar-queiroz@myseneca.ca
Date: 2024-07-11
*/

#ifndef SENECA_MOTORVEHICLE_H__
#define SENECA_MOTORVEHICLE_H__
#include <iostream>

namespace seneca {

	class MotorVehicle
	{
		char m_licensePlate[9];
		char m_addressVehicle[64];
		int m_yearBuilt;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);

		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& RO);
	std::istream& operator>>(std::istream& is, MotorVehicle& RO);
}
#endif