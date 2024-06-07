#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

using namespace std;
namespace seneca {

const double PI = 3.14159265;

void Canister::setToDefault(){ //OK
    m_contentName = nullptr;
    m_diameter = 10.0; // in centimeters 
    m_height = 13.0;   // in centimeters
    m_contentVolume = 0.0;  // in CCs
    m_usable = true;
}

bool Canister::isEmpty()const{ //ok
    return (m_contentVolume < 0.00001);
}

bool Canister::hasSameContent(const Canister& C)const{
    if (m_contentName && C.m_contentName) //validation of contentName
    {
        return (strcmp(m_contentName, C.m_contentName)== 0);
    }
    return false;
    
    
}

void Canister::setName(const char* Cstr){ //ok
    if(Cstr != nullptr && m_usable){
        m_contentName = new char[strlen(Cstr)+1];
        strcpy(m_contentName, Cstr);
    }
    else{
        m_contentName = nullptr;
    }
}

Canister::Canister(){ //No argument Constructor (defualt) --OK
    setToDefault();
}
Canister::Canister(const char* contentName){ //OK
    setToDefault();
    setName(contentName);
}
Canister::Canister(double height, double diameter, const char* contentName = nullptr){ //ok
    setToDefault();
    bool checkHeight = false;
    bool checkDiam = false;
    checkHeight = height >=10.0 && height <= 40.0;
    checkDiam = diameter >= 10.0 && diameter <= 30.0;

    if (checkHeight && checkDiam)//check height and diam
    {
        m_height = height;
        m_diameter = diameter;
        m_contentVolume = 0.0;
        setName(contentName);
    }
    else{
        m_usable = false;
    }
}

Canister::~Canister(){ //ok
    delete[] m_contentName;
    m_contentName = nullptr;
}

void Canister::clear(){ //ok
    delete[] m_contentName;
    setToDefault();                                        
}

double Canister::capacity()const{ //ok
    double cap = (m_height - 0.267) * (m_diameter/2) * (m_diameter/2) * PI;
    return cap;
}

double Canister::volume()const{ //ok
    return m_contentVolume;
}

Canister& Canister::setContent(const char* contentName){ //Check
    if (contentName == nullptr){
        m_usable = false;
    }
    else if(isEmpty){
        setName(contentName);
    }
    else if (!(strcmp(m_contentName, contentName))){
        m_usable = false;
    }
    
    return *this;
}

Canister& Canister::pour(double quantity){ //ok
    if (quantity > 0 && m_usable)
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

Canister& Canister::pour(Canister& C){ //check
    setContent(C.m_contentName);
    if (C.volume() > capacity()-volume())
    {
        C.m_contentVolume -= capacity() - volume();
        m_contentVolume = capacity();
    }
    else{
        pour(m_contentVolume);
        C.m_contentVolume = 0.0;
    }
    return *this;   
}

std::ostream& Canister::display()const{
    cout.width(7);
    cout.precision(2);
    cout << capacity() << "cc (";
    cout << m_height <<"x"<<m_diameter<<") Canister";
    if (!m_usable)
    {
        cout<<" of Unusable content, discard!"<<endl;
    }
    else{
        cout<<" of ";
        cout.width(7);
        cout.precision(2);
        cout << volume() << "cc  ";
        cout << m_contentName<<endl;
    }
    return std::cout;
}


}