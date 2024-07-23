/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_LINE_H__
#define SENECA_LINE_H__
#include "LblShape.h"

namespace seneca {
	class Line: public LblShape
	{
	public:
		Line();
		Line(const char*, int);
		void getSpecs(std::istream&);
		void draw(std::ostream&) const;
	private:
		int m_length = 0;
	};

}
#endif