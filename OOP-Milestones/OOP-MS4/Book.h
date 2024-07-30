/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#ifndef SENECA_BOOK_H__
#define SENECA_BOOK_H__
#include "Publication.h"
namespace seneca {
	class Book: public Publication
	{
	public:
		Book();
		~Book();
		Book(const Book& other);
		Book& operator=(const Book& other);

		char type() const override;
		std::ostream& write(std::ostream&) const override;
		std::istream& read(std::istream& is) override;
		void set(int member_id);
		operator bool() const override;


	private:
		char* m_authorName;
	};
}
#endif
