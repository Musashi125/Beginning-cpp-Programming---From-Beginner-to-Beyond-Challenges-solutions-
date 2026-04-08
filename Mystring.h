#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    private:
        char *str;
    public:
    Mystring();//no_ags constructor
    Mystring(const char *s);//overloaded_constructor 
    Mystring(const Mystring &source); //Copy_constructor
    Mystring(Mystring &&source);//move_constructor
    ~Mystring();//Destructor 
    // Copy assignment
    Mystring& operator=( Mystring &rhs);
    // Move assignment
    Mystring& operator=(Mystring &&rhs);
    //unary minus 
    Mystring operator-();
    //Equality 
    bool operator==(const Mystring &rhs) const ;
    //Not Equality
    bool operator!=(const Mystring &rhs)const ;
    //concatenation. Returns an object that concatenates the lhs and rhs
    Mystring operator+(const Mystring &rhs)const;
    //concatenate the rhs string to the lhs string and store the result in lhs object
    Mystring& operator+=(const Mystring &rhs);
    //repeat -  results in a string that is copied n times
    Mystring operator*(int x) const;
    //repeat the string on the lhs n times and store the result back in the lhs object
    Mystring& operator*=(int x);
    //greater than
    bool operator>(const Mystring& rhs)const;
    //less than
    bool operator<(const Mystring& rhs)const;
    //All upper case
    Mystring& operator++(); //pre-increment
    Mystring  operator++(int);//post-increment
    //All lower case
    Mystring& operator--(); //pre-decrement
    Mystring  operator--(int);//post-decrement

    void display() const;
    void set(char* name);
    int get_len() const;
};

#endif // _MYSTRING_H_