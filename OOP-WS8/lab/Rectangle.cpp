
/*
Student: Renan de Alencar Queiroz
ID: 129280236
email: rde-alencar-queiroz@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Rectangle.h"


seneca::Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0)
{
	//invoke the default constructor of the base class.
}

seneca::Rectangle::Rectangle(const char* Cstring, int width, int height) : 
	LblShape(Cstring), m_width(width), m_height(height)
{
	if (height < 3 || width < static_cast<int>(std::strlen(label()) +2)) //used static_cast to solve the problem: comparison between signed and unsigned integer expressions
	{
		//set the Rectangle to an empty state
		m_width = 0;
		m_height = 0;
	}
}

void seneca::Rectangle::getSpecs(std::istream& is)
{
	LblShape::getSpecs(is);//call the getSpecs function of the base class
	
	//read two comma-separated values from istream for m_width and m_length 
	char comma;
	is >> m_width >> comma >> m_height;
	is.ignore(1000, '\n');
	if (m_height < 3 || m_width < static_cast<int>(std::strlen(label()) + 2)) {
		m_width = 0;
		m_height = 0;
	}
}

void seneca::Rectangle::draw(std::ostream& os) const
{
	if (m_width > 0 && m_height > 0)
	{
		os << "+"; //start of the first line
		for (int i = 0; i < (m_width - 2); i++)
		{
			os << "-"; //os.put('-');
		}
		os << "+" << std::endl; //end of the first line

		//second line
		os << "|";
		os << std::left << std::setw(m_width - 2) << label() << '|' << std::endl;
		
		//next(m_height - 3) lines:
		for (int i = 0; i < (m_height - 3); i++)
		{
			os << '|' << std::setw(m_width - 2) << ' ' << '|' << std::endl;
		}
		
		//start of the last line
		os << "+";
		for (int i = 0; i < (m_width - 2); i++)
		{
			os << "-";//os.put('-');
		}
		os << "+";
		//<< std::endl; //end of the last line
	}
}
