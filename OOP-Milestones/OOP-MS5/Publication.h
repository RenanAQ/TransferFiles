/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#ifndef SENECA_PUBLICATION_H__
#define SENECA_PUBLICATION_H__
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace seneca {
    class Publication : public Streamable {
    private:
        char* m_title; // This attribute is null by default.
        char m_shelfId[SENECA_SHELF_ID_LEN + 1]; // This attribute is an empty string by default.
        int m_membership; // This attribute is zero by default.
        int m_libRef; // This attribute is -1 by default.
        Date m_date; // The Date, by default, is set to the current date.
    public:
        Publication();
        virtual ~Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        
        bool conIO(std::ios&) const override;
        std::ostream& write(std::ostream&) const override;
        std::istream& read(std::istream& is) override;
        operator bool() const override;

        void set(int member_id); // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value); // Sets the libRef attribute value.
        void resetDate(); // Sets the date to the current date of the system.
        virtual char type() const; // Returns the character 'P' to identify this object as a "Publication object".
        bool onLoan() const; // Returns true if the publication is checked out (membership is non-zero).
        Date checkoutDate() const; // Returns the date attribute.
        bool operator==(const char* title) const; // Returns true if the argument title appears anywhere in the title of the publication.
        operator const char* () const; // Returns the title attribute.
        int getRef() const; // Returns the libRef attribute.
    };
}
#endif
