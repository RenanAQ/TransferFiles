/*
* Student: Renan de Alencar Queiroz
* ID: 129280236
I have done all the coding by myself and only copied the code that my professor provided 
to complete my workshops and assignments.
*/

#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;
namespace seneca {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](unsigned int index) const 
   {
        return m_content[index];
    }

   Text::Text(const char* filename): m_filename(nullptr), m_content(nullptr)
   {
       if (filename)
       {
           delete[] m_filename;
           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
           read();
       }
   }

   Text::Text(const Text& src) : m_filename(nullptr), m_content(nullptr)
   {
       if (src.m_filename)
       {
           m_filename = new char[strlen(src.m_filename) + 1];
           strcpy(m_filename, src.m_filename);
       }
       if (src.m_content)
       {
           m_content = new char[strlen(src.m_content) + 1];
           strcpy(m_content, src.m_content);
           read();
       }
       
      

   }

   Text& Text::operator=(const Text& src)
   {
       if (this != &src)
       {
           delete[] m_filename;
           delete[] m_content;
           m_filename = nullptr;
           m_content = nullptr;
           if (src.m_filename) //checking if src is not null
           {
               m_filename = new char[strlen(src.m_filename) + 1];
               strcpy(m_filename, src.m_filename);
           }
           if (src.m_content) //checking if src is not null
           {
               m_content = new char[strlen(src.m_content) + 1];
               strcpy(m_content, src.m_content);
               read();
           }
       }
       return *this;
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
       delete[] m_content;
       m_content = nullptr;
       int len = getFileLength();
       if (len > 0)
       {
           m_content = new char[len + 1];
           std::ifstream fin(m_filename);  // defines a file object named fin
           //if file
           fin.read(m_content, len);
           m_content[len] = '\0';
       }
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content)
       {
           os << m_content;
       }
   }

   std::ostream& operator<<(std::ostream& os, const Text& RO)
   {
       RO.write(os);
       return os;
   }

}