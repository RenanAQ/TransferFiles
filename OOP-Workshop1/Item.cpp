#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {

    void Item::setName(const char* name){
        strcpy_s(m_itemName, name);
        m_itemName[20] = '\0';
    }
    void Item::setEmpty(){
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = false;
    }
    void Item::set(const char* name, double price, bool taxed){
        if (!name || price < 0.0) {
            Item::setEmpty();
        }
        else {
            Item::setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    void Item::display()const{
        if (isValid())
        {
            cout << flush;
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout.setf(ios::left);
            cout << m_itemName; //"milk" is printed here
            cout << " | ";
            
            cout.fill(' ');
            cout.width(7);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::right);

            cout << " | ";
            cout.fill(' ');
            cout.width(4);            
            cout.setf(ios::left);
            if (m_taxed)
                cout << "Yes";
            else
                cout << "No";
            cout << "|";
            cout << endl;
        }
        //| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx | //Newline
        else{
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |";
            cout << endl;
        }
    }
    bool Item::isValid()const{
        return (m_itemName[0] !='\0' && m_price > 0.0);
    }
    double Item::price()const{
        return m_price;
    }
    double Item::tax()const{
        if (m_taxed) {
            return m_price * TAX_VALUE;
        }
        else
        {
            return 0.0;
        } 
    }
}