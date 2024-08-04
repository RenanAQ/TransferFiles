/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H
#include <iostream>

//using namespace std;
namespace seneca {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream&) const = 0;
        virtual std::istream& read(std::istream&) = 0;
        virtual bool conIO(std::ios& io)const = 0;
        virtual operator bool()const = 0;
        virtual ~Streamable() = default;
        virtual std::ostream& operator<<(std::ostream& os) = 0;
        virtual std::istream& operator>>(std::istream& is) = 0;
    };
}
#endif



