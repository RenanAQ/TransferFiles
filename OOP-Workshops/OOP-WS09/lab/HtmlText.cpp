/*
* Student: Renan de Alencar Queiroz
* ID: 129280236
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/

#include <fstream>
#include <cstring>
#include "Text.h"
#include "HtmlText.h"
namespace seneca {
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename), m_title(nullptr)
	{
		if (title)
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& other) :Text(other), m_title(nullptr)
	{
		if (other.m_title) {
			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
	}
	HtmlText& HtmlText::operator=(const HtmlText& other)
	{
		if (this != &other) {
			Text::operator=(other);
			delete[] m_title;
			m_title = nullptr;
			if (other.m_title) {
				m_title = new char[strlen(other.m_title) + 1];
				strcpy(m_title, other.m_title);
			}
		}
		return *this;
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}
    void HtmlText::write(std::ostream& os) const
    {
        bool MS = false;
        os << "<html><head><title>";
        if (m_title) os << m_title;
        else os << "No Title";
        os << "</title></head>\n<body>\n";
        if (m_title) os << "<h1>" << m_title << "</h1>\n";
        for (int i = 0; (*this)[i] != '\0'; i++) {
            switch ((*this)[i]) {
            case ' ':
                if (MS) os << "&nbsp;";
                else {
                    MS = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                MS = false;
                os << (*this)[i];
            }
        }
        os << "</body>\n</html>";
    }
}