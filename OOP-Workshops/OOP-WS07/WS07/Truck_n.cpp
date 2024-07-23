/*
Student: Renan de Alencar Queiroz
ID: 129280236
Email: rde-alencar-queiroz@myseneca.ca
Date: 2024-07-11
*/
#include "Truck.h"
#include <iomanip>

namespace seneca {

    Truck::Truck(const char* plate, int year, double capacity, const char* currentAddress)
        : MotorVehicle(plate, year), m_capacity(capacity), m_cargoLoad(0) {
        moveTo(currentAddress);
    }

    bool Truck::addCargo(double cargo)
    {
        if (m_cargoLoad + cargo <= m_capacity)
        {
            m_cargoLoad += cargo;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo()
    {
        if (m_cargoLoad > 0.0)
        {
            m_cargoLoad = 0.0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os) const {
        MotorVehicle::write(os);
        os << " | " << m_cargoLoad << "/" << m_capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in) {
        MotorVehicle::read(in);
        std::cout << "m_capacity: ";
        in >> m_capacity;
        std::cout << "m_cargoLoad: ";
        in >> m_cargoLoad;
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& t) {
        return t.write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& t) {
        return t.read(is);
    }

}
