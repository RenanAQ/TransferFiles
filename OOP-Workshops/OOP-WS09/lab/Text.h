/*
* Student: Renan de Alencar Queiroz
* ID: 129280236
I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
namespace seneca {
   class Text {
      char* m_filename = nullptr ; //Hold the name of the file dynamically
      char* m_content = nullptr ; //Holds the content of the text file dynamically.
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      
      // rule of three here
      Text(const Text&);
      Text& operator=(const Text&);
      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   // prototype of insertion overload into ostream
   std::ostream& operator<<(std::ostream& os, const Text& RO);
}
#endif // !SENECA_PERSON_H__

