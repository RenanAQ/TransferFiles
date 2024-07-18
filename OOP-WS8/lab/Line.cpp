
/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Line.h"
seneca::Line::Line(): LblShape()
{
	m_length = 0;
}

seneca::Line::Line(char* Cstring, int length): LblShape(Cstring)// Passes the Cstring to the constructor of the base class 
{
 
	m_length = length;
}

void seneca::Line::getSpecs(std::istream& in)
{
	LblShape::getSpecs(in);//call the getSpecs function of the base class
	in >> m_length;
	in.ignore(1000, '\n');
	//it will read the value of the m_length attribute from the istream argument, 
	// and then it will ignore The rest of the characters up to and including the newline character '\n'.

}

void seneca::Line::draw(std::ostream& os) const
{
	if (m_length > 0 && label() != NULL)
	{
		os << label() << std::endl; //first print the label()
		for (int i = 0; i < m_length; i++) //printing the '=' to the value of the m_length member variable.
		{
			os << "="; //os.put('=');
		}
		os << std::endl;
	}
}
