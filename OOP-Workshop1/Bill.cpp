#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {

    double Bill::totalTax()const{
        double sum = 0.0;
        for (int i = 0; i < m_itemsAdded; i++) {
            sum += m_items[i].tax();
        }
        return sum;
    }
    double Bill::totalPrice()const{
        double sum = 0.0;
        for (int i = 0; i < m_itemsAdded; i++) {
            sum += m_items[i].price();
        }
        return sum;
    }
    void Bill::Title()const{
        cout << "+--------------------------------------+";
        if (isValid()){
            cout << endl << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout << " |";
        }
        else{
            cout << endl << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << "Invalid Bill";
            cout << " |";
        }
        cout << endl << "+--------------------------------------+"<< endl;
        cout << "| Item Name            | Price   + Tax |"<<endl;
        cout << "+--------------------------------------+"<< endl;

    }
    void Bill::footer()const{
        cout << "+----------------------+---------+-----+"<< endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax()+totalPrice();
            cout << " |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else{
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << "Invalid Bill";
            cout << " |" << endl;
        }
        cout << "+----------------------+---------+-----+"<< endl;
        
    }
    void Bill::setEmpty(){
        m_title[0] = '\0';
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }
    bool Bill::isValid()const{
        if (m_title[0] == '\0' || m_items == nullptr) {
            return false;
        }
        else
        {
            return m_items[m_itemsAdded].isValid();
        }
    }
    void Bill::init(const char* title, int noOfItems){
        if (!title || !noOfItems) {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strcpy_s(m_title, title);
            m_title[36] = '\0';
            m_items = new Item[noOfItems];
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed){

        if(m_itemsAdded < m_noOfItems){
            //add item
            Item i; //initializing object of Item
            i.set(item_name, price, taxed);
            m_items[m_itemsAdded] = i;
            m_itemsAdded++;
            return true;
        }
        else {
            return false;
        }
    }
    
    void Bill::display()const{
        Title();
        for (int i = 0; i < Bill::m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }
    
    void Bill::deallocate(){
        delete[] m_items;
        m_items = nullptr;
    }

}