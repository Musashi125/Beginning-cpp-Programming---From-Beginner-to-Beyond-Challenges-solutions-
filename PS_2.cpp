 #include <iostream>
 using namespace std;
 int main ()
{
const int Lroom_Price {35}; // Lroom = large rome 
const int Sroom_Price {25};//  Sroom = small  rome 
const double tax_rate {0.06};
const int validation {30}; //Days
int Lrooms {0};
int Srooms {0};
cout << "Good morning and welcome to our room cleaning service:)\n";
cout << "How many Large rooms would you like cleaned ? ";
for (int i = 0 ; i < 1 ; i=i ) // cheking of validation it's an extra step i've done 
{
cin >> Lrooms;
if (Lrooms < 0 )
{
    cout << "Number of room couldn't be negative please try again ";
    
    
}
else
    break ;
}
cout << "How many Small rooms would you like cleaned ? ";
for (int i = 0 ; i < 1 ; i=i )
{
cin >> Srooms;
if (Srooms < 0 )
{
    cout << "Number of room couldn't be negative please try again ";
  
    
}
else
    break ;
}
cout << "number of large rooms : " << Lrooms << endl;
cout << "number of Small rooms : " << Srooms << endl;
cout << "price per Large room is " << Lroom_Price <<  " $"<< endl;
cout << "price per Small room is " << Sroom_Price <<  " $"<< endl;
cout << "Cost : "<< (Lrooms * Lroom_Price) + (Srooms * Sroom_Price)  <<" $" <<endl;
int cost {(Lrooms * Lroom_Price) + (Srooms * Sroom_Price)};
cout << "Tax : " << cost * tax_rate << " $" << endl; 
cout << "================================================================================\n";
cout << "Total estimate : " << cost + cost * tax_rate << " $" << endl;
cout << "This  estimate is vaild for " << validation << " days" << endl;
return 0;
} 
