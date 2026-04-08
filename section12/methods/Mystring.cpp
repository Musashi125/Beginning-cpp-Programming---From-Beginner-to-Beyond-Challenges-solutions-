#include <iostream>
#include <cstring>

class Mystring {
private:
    char *str;
public:
    Mystring(const char *s = ""); // constructor
    Mystring(const Mystring &source); // copy constructor
    ~Mystring(); // destructor

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

Mystring::Mystring(const char *s) {
    if (s) {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    } else {
        str = new char[1];
        *str = '\0';
    }
}

Mystring::Mystring(const Mystring &source) {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring() {
    delete [] str;
}

void Mystring::display() const {
    std::cout << str << std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char *Mystring::get_str() const {
    return str;
}