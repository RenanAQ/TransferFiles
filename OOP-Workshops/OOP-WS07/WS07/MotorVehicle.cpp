/*
Student: Renan de Alencar Queiroz
ID: 129280236
Email: rde-alencar-queiroz@myseneca.ca
Date: 2024-07-11
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"

namespace seneca {
	MotorVehicle::MotorVehicle(const char* plate, const int year)
	{
		m_yearBuilt = year;
		strncpy(m_licensePlate, plate, 8);
		m_licensePlate[8] = '\0';
		strncpy(m_addressVehicle, "Factory",63);
		m_addressVehicle[63] = '\0';
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_addressVehicle, address) != 0)
		{
			std::cout << "|" << std::setw(8) << std::right << m_licensePlate << "| |"
				<< std::setw(20) << std::right << m_addressVehicle
				<< " ---> " << std::setw(20) << std::left << address << "|" << std::endl;
			strncpy(m_addressVehicle, address, 63);
			m_addressVehicle[63] = '\0';
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << m_yearBuilt << " | " << m_licensePlate << " | " << m_addressVehicle;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& in)
	{
		std::cout << "Built year: ";
		in >> m_yearBuilt;
		std::cout << "License plate: ";
		in >> m_licensePlate;
		std::cout << "Current location: ";
		in >> m_addressVehicle;
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& RO)
	{
		return RO.write(os);
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& RO)
	{
		return RO.read(is);
	}
}