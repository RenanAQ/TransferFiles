/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__
#include <iostream>
namespace seneca {
    class Utils {
    public:
        size_t getInt(size_t, size_t);
        int getMemberNum();
        char getType(unsigned int);
    };
    extern Utils ut;
}
#endif // SENECA_UTILS_H__


