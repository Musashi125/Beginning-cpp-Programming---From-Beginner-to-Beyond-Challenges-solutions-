#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

Mystring::Mystring()
:str{nullptr}{
    str = new char [1];
    *str = '\0';
    len = 0;
}
Mystring::Mystring(const char *s)
:str{nullptr}{
    if (s==nullptr){
        str = new char[1];
        *str = '\0';
        len =0;
    }else{
    len = strlen(s);
    str = new char[strlen(s) + 1];
    strcpy(str,s);
    }
}
Mystring::Mystring(const Mystring &source){
if (source.str == nullptr){
    str = new char[1];
    *str = '\0';
    len = 0;
}else{
    str = new char[(source.len) + 1];
    strcpy(str,source.str);
    len = source.len;
}
}
Mystring::Mystring(Mystring &&source):str{source.str},len{source.len}{
source.str = nullptr;
}
Mystring::~Mystring(){
    delete [] str;
}
void Mystring::display()const{
    cout << "This is " <<  str << endl;
}
int Mystring::get_len()const{
    return this->len;
}
const char* Mystring::get_str()const{
    return str;
}
Mystring& Mystring::get_obj(){
    return *this;
}

Mystring& Mystring::operator=(const Mystring& rhs){
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char [rhs.len+1];
    len = rhs.len;
    strcpy(str,rhs.str);
    return *this;
}
Mystring& Mystring::operator=(Mystring&& rhs){
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring operator-(const Mystring &self) {
    size_t len = self.len;
    char *buff = new char[len + 1];
    for (size_t i = 0; i < len; i++) {
        buff[i] = tolower(self.str[i]);
    }
    buff[len] = '\0';
    Mystring result{buff};
    delete[] buff;
    return result;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {

    size_t l_len = lhs.len;
    size_t r_len = rhs.len;

    char *buff = new char [l_len + r_len + 1];

    memcpy(buff,lhs.str,l_len);

    memcpy(buff + l_len,rhs.str,r_len);

    buff[l_len + r_len]='\0';
    Mystring result {buff};
    delete [] buff;
    return result;
}

Mystring operator*(const Mystring &lhs,const int n) {

    if(n <= 0 || lhs.str == nullptr)
        return Mystring{""};

    size_t len = lhs.len;
    size_t total_len = len * n;

    char *buff = new char [total_len + 1];

    for (int i = 0; i < n; i++){
        memcpy(buff + (i * len),lhs.str,len);
    
    }
    buff[total_len] = '\0';
    
    Mystring result {buff};
    delete [] buff;
    return result;
}

Mystring& operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Mystring& operator*=(Mystring &lhs, const int n) {
    lhs = lhs * n;
    return lhs;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    if(lhs.str == nullptr && rhs.str == nullptr)
        return true;
    if(lhs.str == nullptr || rhs.str == nullptr)
        return false;
    return !(strcmp(rhs.str,lhs.str));
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
   return !(lhs == rhs);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    if(lhs.str == nullptr)
        return false;
    if(rhs.str == nullptr)
        return true;
    return(strcmp(lhs.str,rhs.str) > 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    if(lhs.str == nullptr)
        return true;
    if(rhs.str == nullptr)
        return false;
    return(strcmp(lhs.str,rhs.str) < 0);
}

Mystring& operator++(Mystring &self) {
    char *p = self.str;
    while(*p)
    {
       *p = toupper(*p);
        p++;
    }
    return self;
}

Mystring operator++(Mystring &self, int) {

    Mystring old {self};
    ++self;
    return old;
}

Mystring& operator--(Mystring &self) {
    char *p = self.str;
    while(*p)
        {
            *p = tolower(*p);
             p++;
        }
    return self;
}

Mystring operator--(Mystring &self, int) {

    Mystring old {self};
    --self;
    return old;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
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