/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#ifndef SENECA_STREAMABLE_H__
#define SENECA_STREAMABLE_H__
#include <iostream>
namespace seneca
{
    class Streamable
    {
    private:

    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Streamable& RO);
    std::istream& operator>>(std::istream& is, Streamable& RO);
}
#endif