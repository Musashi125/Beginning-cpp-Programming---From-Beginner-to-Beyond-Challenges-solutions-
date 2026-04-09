#ifndef  _MYSTRING_H_
#define  _MYSTRING_H_
#include<iostream>
class Mystring{
friend Mystring operator-(const Mystring &self);
friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
friend Mystring operator*(const Mystring &lhs, const int n);
friend Mystring& operator*=(Mystring &lhs, const int n);
friend Mystring& operator+=(Mystring &lhs, const Mystring &rhs);
friend bool operator==(const Mystring &lhs, const Mystring &rhs);
friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
friend bool operator>(const Mystring &lhs, const Mystring &rhs);
friend bool operator<(const Mystring &lhs, const Mystring &rhs);
friend Mystring& operator++(Mystring &self);
friend Mystring operator++(Mystring &self, int);
friend Mystring& operator--(Mystring &self);
friend Mystring operator--(Mystring &self, int);
friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
friend std::istream &operator>>(std::istream &in, Mystring &rhs);
private:
    char *str;
    size_t len;
public:
Mystring();
Mystring(const char *s);
Mystring(const Mystring &source);
Mystring(Mystring &&source);
~Mystring();
void display()const;
int get_len()const;
const char* get_str()const;
Mystring& get_obj();
Mystring& operator=(const Mystring& rhs);
Mystring& operator=(Mystring&& rhs);

};
#endif //_MYSTRING_H_