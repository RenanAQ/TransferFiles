/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_RECTANGLE_H__
#define SENECA_RECTANGLE_H__
#include "LblShape.h"

namespace seneca
{
	class Rectangle : public LblShape
	{
	public:
		Rectangle();
		Rectangle(const char *, int, int);
		void getSpecs(std::istream &);
		void draw(std::ostream &) const;

	private:
		int m_width = 0;
		int m_height = 0;
	};
}
#endif