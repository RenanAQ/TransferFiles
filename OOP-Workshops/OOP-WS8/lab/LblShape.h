/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_LBLSHAPE_H__
#define SENECA_LBLSHAPE_H__
#include "Shape.h"

namespace seneca {
	class LblShape : public Shape
	{
	public:
		LblShape();
		LblShape(const char*);
		~LblShape();

		// Prevent copying and assignment
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;

		void getSpecs(std::istream&);

	protected:
		const char* label()const;

	private:
		char* m_label;

	};

}
#endif