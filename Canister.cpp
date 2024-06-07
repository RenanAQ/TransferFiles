#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

#define PI 3.14159265;

using namespace std;
namespace seneca {

void Canister::setToDefault(){
    m_contentName = nullptr;
    m_diameter = 10.0; // in centimeters 
    m_height = 13.0;   // in centimeters
    m_contentVolume = 0;  // in CCs
    m_usable = true;
}

bool Canister::isEmpty()const{
    return (m_contentVolume < 0.00001);
}

bool Canister::hasSameContent(const Canister& C)const{
    return (strcmp(m_contentName, C.m_contentName));
}

void Canister::setName(const char* Cstr){
    if(Cstr != nullptr && m_usable){
       int size = sizeof(Cstr)+1;
       strncpy(m_contentName, Cstr, size);
    }
}

Canister::Canister(){ //No argument Constructor (defualt)
    setToDefault();
}
Canister::Canister(const char* contentName){
    setToDefault();
    setName(contentName);
}
Canister::Canister(double height, double diameter, const char* contentName = nullptr){
    setToDefault();
    bool checkHeight = false;
    bool checkDiam = false;
    checkHeight = height >=10.0 && height <= 40.0;
    checkDiam = diameter >= 10.0 && diameter <= 30.0;

    if (checkHeight && checkDiam)//check height and diam))
    {
        m_height = height;
        m_diameter = diameter;
        m_contentVolume = 0;
        strcpy(m_contentName, contentName);
    }
    else{
        m_usable = false;
    }
}

Canister::~Canister(){
    delete[] m_contentName;
    m_contentName = nullptr;
}

void Canister::clear(){
    delete[] m_contentName;
    m_contentName = nullptr;
    m_contentVolume = 0;
    m_usable = true;
}

double Canister::capacity()const{
    double cap = (m_height - 0.267) * (m_diameter/2) * (m_diameter/2) * PI;
    return cap;
}

double Canister::volume()const{
    return m_contentVolume;
}

Canister& Canister::setContent(const char* contentName){
    if (contentName == nullptr){
        m_usable = false;
    }
    else if(isEmpty){
        strcpy(m_contentName, contentName);
    }
    else if (!(strcmp(m_contentName, contentName))){
        m_usable = false;
    }
    
    return *this;
}

Canister& Canister::pour(double quantity){
    if (quantity && m_usable)
    {
        if ((volume() + quantity) <= capacity())
        {
            m_contentVolume += quantity;
        }
        else{
            m_usable = false;
        }
    }
    return *this;
}

Canister& Canister::pour(Canister& C){
    setContent(C.m_contentName);
    if (C.volume() > capacity()-volume())
    {
        C.m_contentVolume = capacity() - volume();
    }
    else{
        pour(m_contentVolume - volume());
        C.m_contentVolume = 0.0;
    }
    return *this;   
}

std::ostream& Canister::display()const{
    cout.width(7);
    cout.precision(2);
    cout << volume() << "cc (";
    cout << m_height <<"x"<<m_diameter<<") Canister";
    if (!m_usable)
    {
        cout<<" of Unusable content, discard!"<<endl;
    }
    else{
        cout<<" of ";
        cout.width(7);
        cout.precision(2);
        cout << volume() << "cc (";
        cout << m_contentName<<endl;
    }
    return ;
}


}