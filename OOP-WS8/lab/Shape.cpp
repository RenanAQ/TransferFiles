
/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Shape.h"

std::ostream& seneca::operator<<(std::ostream& os, const Shape& RO)
{
	RO.draw(os);
	return os;
}

std::istream& seneca::operator>>(std::istream& is, Shape& RO)
{
	RO.getSpecs(is);
	return is;
}


