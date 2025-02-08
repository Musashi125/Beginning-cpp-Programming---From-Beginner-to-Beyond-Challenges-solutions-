#include <iostream> 
int main ()
{

    int a;
    std:: cout << "HI!, Whats's your favorite Number bettwen 1 and 100 ?  :  ";
    std:: cin >> a;
    // note : the for loop function is optional in this challnge it's just me wanted to enhance the code so i searched how to make sure user enter numbers bettwen 1 and 100 
    // it's totally okay if you did't code lines from 10 to 21 
    for (int i=0 ; i < 1 ;i=i)
    {
        if (a > 100 || a < 1)
        {
           std :: cout << "pls enter number bettwen 1~100 \n ";
           std :: cin >> a;
        }
        else
        {
            break;
        }
    }
    std:: cout <<"Amazing!! That's my favorite number too!\n" << "No really!!, "<< a << " is my favorite number!"  ;

    return 0 ;
    
}
