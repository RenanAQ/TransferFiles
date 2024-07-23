/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_SHAPE_H__
#define SENECA_SHAPE_H__

#include <iostream>
#include <cstring>
#include <iomanip>
namespace seneca {
	class Shape
	{
	public:
		virtual ~Shape() = default;
		virtual void draw(std::ostream&) const = 0;
		virtual void getSpecs(std::istream&) = 0;

	private:

	};

	std::ostream& operator<<(std::ostream& os, const Shape& RO);
	std::istream& operator>>(std::istream& is, Shape& RO);

}
#endif