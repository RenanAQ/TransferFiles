/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#include "Lib.h"
namespace seneca{
    
    Streamable::~Streamable(){
    
    }
    bool Streamable::conIO(std::iostream& io) const{
        //
    }
    std::ostream& operator<<(std::ostream& os, const Streamable& RO){

    }
    std::istream& operator>>(std::istream& is, Streamable& RO){

    }
    Publication::Publication()
    {
        char* m_title = nullptr; //This attribute is null by default.
        char m_shelfId[5]= {0}; //This attribute is an empty string by default.
        int m_membership = 0; //This attribute is zero by default.
        int m_libRef = -1; //This attribute is -1 by default.
        Date m_date = Date(); //The Date, by default, is set to the current date.
    }

}