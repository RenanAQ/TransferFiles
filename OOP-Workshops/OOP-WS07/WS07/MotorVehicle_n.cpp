/*
Student: Renan de Alencar Queiroz
ID: 129280236
Email: rde-alencar-queiroz@myseneca.ca
Date: 2024-07-11
*/
#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    MotorVehicle::MotorVehicle(const char* plate, int year) : m_yearBuilt(year) {
        strncpy(m_licensePlate, plate, 8);
        m_licensePlate[8] = '\0';
        strcpy(m_addressVehicle, "Factory");
    }

    void MotorVehicle::moveTo(const char* address) {
        if (strcmp(m_addressVehicle, address) != 0) {
            std::cout << "|" << std::setw(8) << std::right << m_licensePlate << "| |"
                << std::setw(20) << std::right << m_addressVehicle << " ---> "
                << std::setw(20) << std::left << newm_addressVehicle << "|" << std::endl;
            strncpy(m_addressVehicle, newm_addressVehicle, 63);
            m_addressVehicle[63] = '\0';
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << m_yearBuilt << " | " << m_licensePlate << " | " << m_addressVehicle;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in) {
        std::cout << "Built m_yearBuilt: ";
        in >> m_yearBuilt;
        std::cout << "License plate: ";
        in >> m_licensePlate;
        std::cout << "Current location: ";
        in >> m_addressVehicle;
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {
        return mv.write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& mv) {
        return mv.read(is);
    }

}
