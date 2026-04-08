#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring():str{nullptr}{
    str = new char[1];
    *str = '\0';
    std::cout << "No-args constructor called for " << str << std::endl;
}
// Overloaded constructor
Mystring::Mystring(const char *s)
    :str{nullptr}{
        if(s==nullptr){
            str = new char[1];
            *str = '\0';
        }else{
            str = new char[strlen(s)+1];
            strcpy(str,s);
        }
        std::cout << "overloaded constructor called for " << str << std::endl;

}
// Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}{
        if(source.str == nullptr){
            str = new char[1];
            *str = '\0'; 
        }
        else{
            str = new char [strlen(source.str) + 1];
            strcpy(str,source.str);
        }
        std::cout << "Copy constructor called for " << str << std::endl;
}
// Move constructor
Mystring::Mystring(Mystring &&source)
:str{source.str}{
    std::cout << "Move constructor called for " << str << std::endl;
    source.str = nullptr;
}
 // Destructor
Mystring::~Mystring(){
    if(str != nullptr)
        std::cout << "Destructor called for " << str << std::endl;
    else
        std::cout << "Destructor called for nullptr" << std::endl;
    delete [] str;
}
// Copy assignment
Mystring& Mystring::operator=(Mystring &rhs){
if (this == &rhs)
    return *this;
delete [] str;
str = new char [strlen(rhs.str) + 1];
strcpy(str,rhs.str);
std::cout << "Copy assignment called for " << str << std::endl;
return *this;
}
// Move assignment
Mystring& Mystring::operator=(Mystring &&rhs){
if (this == &rhs)
    return *this;
delete [] str;
str=rhs.str;
rhs.str=nullptr;
std::cout << "Move assignment called for " << str << std::endl;
return *this;
}
// Display method
void Mystring::display()const{
std::cout << "This is : " << str << std::endl;
}
// getters
int Mystring::get_len() const{
return strlen(str);
}
// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}
// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}
//lower case
Mystring Mystring::operator-(){
    if (this->str == nullptr)
        return *this;
    size_t len = strlen(str);
    char *buffer = new char[len + 1];
    for (size_t i = 0; i < len; i++){
        buffer[i] = tolower(str[i]);
    }
    buffer[len] = '\0';
    Mystring result{buffer};
    delete [] buffer;
    return result; 
}
//Equality 
bool Mystring::operator==(const Mystring &rhs)const {
    if (rhs.str == nullptr && this->str == nullptr){
        return true;
    }
    if (rhs.str == nullptr || this->str == nullptr){
        return false;
    }
    return !(strcmp(this->str,rhs.str));
}
//Not Equality
bool Mystring::operator!=(const Mystring &rhs)const {
    return !(*this == rhs);
}
//concatenation. Returns an object that concatenates the lhs and rhs
Mystring Mystring::operator+(const Mystring &rhs)const{
    if (this->str == nullptr && rhs.str == nullptr)
        return Mystring{""};
    if (rhs.str == nullptr)
        return *this;  
    if (this->str == nullptr)
        return rhs;
    char *buffer = new char [strlen(rhs.str) + strlen(this->str) + 1];
    buffer = strcpy(buffer,this->str);
    buffer = strcat(buffer,rhs.str);
    Mystring temp{buffer};
    delete [] buffer;
    return temp;
}
//concatenate the rhs string to the lhs string and store the result in lhs object
Mystring& Mystring::operator+=(const Mystring &rhs){
    *this = *this + rhs;
    return *this;
}
//repeat -  results in a string that is copied n times
Mystring Mystring::operator*(int x)const {
    if(x <= 0 || str == nullptr)
        return Mystring{""};
    size_t len = strlen(str);
    char* buffer = new char[len * x + 1];
    buffer[0] = '\0';
    for (size_t i = 0; i < x; i++){
        buffer = strcat(buffer,str);
    }
    Mystring result {buffer};
    delete [] buffer;
    return result;
}
//repeat the string on the lhs n times and store the result back in the lhs object
Mystring& Mystring::operator*=(int x) {
    if(x <= 0 || str == nullptr)
        return*this;
    return *this = *this * x;
}
//Greater than
bool Mystring::operator<(const Mystring& rhs)const {
    if (this->str == nullptr)
        return true;
    if (rhs.str == nullptr)
        return false;
    return(strcmp(str,rhs.str) < 0);
}
//less than
bool  Mystring::operator>(const Mystring& rhs)const {
    if (this->str == nullptr)
        return true;
    if (rhs.str == nullptr)
    return false;
    return(strcmp(str,rhs.str) > 0);
}
//pre-increment
Mystring& Mystring::operator++(){
    size_t len = strlen(this->str);
    for (size_t i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
    return *this;
}
//post-increment
Mystring Mystring::operator++(int){
    Mystring old(*this);
    ++(*this);
    return old;
}
//pre-decrement
Mystring& Mystring::operator--(){
    size_t len = strlen(this->str);
    for (size_t i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
    return *this;
}
//post-decrement
Mystring Mystring::operator--(int){
    Mystring old(*this);
    --(*this);
    return old;
}