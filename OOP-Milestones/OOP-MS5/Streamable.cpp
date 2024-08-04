/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/

#include "Streamable.h"
namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Streamable& RO) 
    {
        if (RO) RO.write(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Streamable& RO) 
    {
        RO.read(is);
        return is;
    }
}
