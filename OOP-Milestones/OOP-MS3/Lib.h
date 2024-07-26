/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#ifndef SENECA_LIB_H__
#define SENECA_LIB_H__
#include <iostream>
#include "Date.h"
namespace seneca
{
    const int SENECA_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SENECA_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SENECA_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SENECA_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SENECA_LIBRARY_CAPACITY = 5000;
    // Maximum number of publications the library can hold.

    class Streamable
    {
    private:
        
    public:
        virtual std::ostream& write(std::ostream &) const = 0;
        virtual std::istream& read(std::istream &) = 0;
        bool conIO(std::iostream& )const;
        virtual operator bool()=0;
        ~Streamable();
    };
    std::ostream& operator<<(std::ostream& os, const Streamable& RO);
    std::istream& operator>>(std::istream& is, Streamable& RO);

    class Publication: public Streamable
    {
    private:
        char* m_title; //This attribute is null by default.
        char m_shelfId[5]; //This attribute is an empty string by default.
        int m_membership; //This attribute is zero by default.
        int m_libRef; //This attribute is -1 by default.
        Date m_date; //The Date, by default, is set to the current date.
    public:
        Publication();
        
        virtual void set(int member_id); // Sets the membership attribute to either zero or a five-digit integer.        
        void setRef(int value); // Sets the **libRef** attribute value
        void resetDate(); // Sets the date to the current date of the system.

        virtual char type()const; //Returns the character 'P' to identify this object as a "Publication object"        
        bool onLoan()const; //Returns true is the publication is checkout (membership is non-zero)        
        Date checkoutDate()const; //Returns the date attribute        
        bool operator==(const char* title)const; //Returns true if the argument title appears anywhere in the title of the //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const; //Returns the title attribute        
        int getRef()const; //Returns the libRef attirbute. 
        
        
    };
}
#endif