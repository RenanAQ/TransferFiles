/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/


#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#define MAX_TITLE_LEN 255
#define MAX_SHELF_LEN 4

#include <iostream>
#include <ctime>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"


using namespace seneca;
namespace seneca {
    class Publication : public Streamable {
        char* m_title{};
        char m_shelfId[MAX_SHELF_LEN + 1]{};
        int m_membership{};
        int m_libRef = -1;
        Date m_date;
    public:
        Publication();
        Publication(const Publication&);
        Publication& operator=(const Publication&);
        ~Publication() override;
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type()const;
        bool onLoan()const;
        Date checkoutDate()const;
        bool operator==(const char* title)const;
        operator const char* ()const;
        int getRef()const;
        bool conIO(std::ios& io)const override;
        std::ostream& write(std::ostream&) const override;
        std::istream& read(std::istream&) override;
        operator bool() const override;
        std::ostream& operator<<(std::ostream& os) override;
        std::istream& operator>>(std::istream& is) override;
    };
    std::ostream& operator<<(std::ostream& os, const Publication& right);
    std::istream& operator>>(std::istream& is, Publication& right);

}
#endif


