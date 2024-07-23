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

   const char& Text::operator[](int index) const
   {
       
       /*This index operator provides read-only access to the 
       content of the text for the derived classes of Text.
       The behaviour of the operator is not defined if the index goes out of bounds.
       */

       if (index)//NOT index out of bounds
       {
           return m_content[index];
       }
      
   }

   Text::Text(const char* filename)
   {
       m_content = nullptr;
       delete[] m_filename;
       m_filename = new char[strlen(filename) + 1];
       strcpy(m_filename, filename);
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content != nullptr)
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