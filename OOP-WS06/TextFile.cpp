#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;

namespace seneca {
    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    // TextFile methods
    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        std::string filenameStr = isCopy ? "C_" + std::string(fname) : std::string(fname);
        m_filename = new char[filenameStr.length() + 1];
        strcpy(m_filename, filenameStr.c_str());
    }

    void TextFile::setNoOfLines() {
        m_noOfLines = 0;
        if (m_filename) {
            ifstream file(m_filename);
            if (file.is_open()) {
                char ch;
                while (file.get(ch)) {
                    if (ch == '\n') {
                        m_noOfLines++;
                    }
                }
                if (file.peek() != std::ifstream::traits_type::eof()) {
                    m_noOfLines++;
                }
                file.close();
            }
        }
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {
        if (!m_filename) return;
        delete[] m_textLines;
        m_textLines = nullptr;

        ifstream file(m_filename);
        if (file.is_open()) {
            m_textLines = new Line[m_noOfLines];
            std::string lineContent;
            unsigned i = 0;
            while (getline(file, lineContent) && i < m_noOfLines) {
                m_textLines[i] = lineContent.c_str();
                i++;
            }
            m_noOfLines = i;
            file.close();
        }
    }

    void TextFile::saveAs(const char* fileName) const {
        ofstream file(fileName);
        if (file.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; ++i) {
                file << (const char*)m_textLines[i] << '\n';
            }
            file.close();
        }
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {}

    TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile(pageSize) {
        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& other) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(other.m_pageSize) {
        if (other) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& other) {
        if (this != &other) {
            setEmpty();
            if (other) {
                setFilename(other.m_filename);
                other.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        setEmpty();
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {
        if (*this) {
            ostr << m_filename << std::endl;
            for (unsigned i = 0; i < strlen(m_filename); ++i) {
                ostr << "=";
            }
            ostr << std::endl;

            for (unsigned i = 0; i < m_noOfLines; ++i) {
                ostr << (const char*)m_textLines[i] << std::endl;
                if ((i + 1) % m_pageSize == 0) {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore();
                }
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        char filename[256];
        istr >> filename;
        setEmpty();
        setFilename(filename);
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile::operator bool() const {
        return m_filename != nullptr;
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const {
        if (!*this) return nullptr;
        return (const char*)m_textLines[index % m_noOfLines];
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}