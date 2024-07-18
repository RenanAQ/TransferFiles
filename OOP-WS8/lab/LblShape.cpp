#include "LblShape.h"
/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

seneca::LblShape::LblShape()
{
    m_label = nullptr;
}

seneca::LblShape::LblShape(const char* Cstring)
{
    delete[] m_label;
    m_label = new char[strlen(Cstring) + 1]; //Allocates memory large enough to hold the incoming Cstring
    strcpy(m_label, Cstring); //copies the Cstring argument to the newly allocated memory.
}

seneca::LblShape::~LblShape()
{
    delete[] m_label;
}

void seneca::LblShape::getSpecs(std::istream& Cstring)
{
    std::string temp;
    std::getline(Cstring, temp, ',');
    delete[] m_label;
    m_label = new char[temp.size() + 1];
    std::strcpy(m_label, temp.c_str());
}

const char* seneca::LblShape::label() const
{
    return m_label;
}
