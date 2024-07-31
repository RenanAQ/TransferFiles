/*
Student: Renan de Alencar Queiroz
ID: 129280236
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace seneca
{
    template <typename T>
    void listArrayElements(const char* m_title, const T* m_arr, int m_num) {
        cout << m_title << endl;

        for (int i = 0; i < m_num; i++) {
            cout << i + 1 << ": " << m_arr[i] << endl;
        }
    }
    template <typename T1, typename T2>
    bool search(Collection<T1>& m_obj, const T1* m_arr, int m_num, T2 m_key) {
        bool result = false;

        for (int i = 0; i < m_num; i++) {
            if (m_arr[i] == m_key) { 
                m_obj.add(m_arr[i]);
                result = true;
            }
        }
        return result;
    }
}
#endif