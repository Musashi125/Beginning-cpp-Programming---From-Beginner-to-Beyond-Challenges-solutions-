#include <iostream>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

void print_menu_to_user();
char read_selection();
void print_list(char option);
void add_number(char option);
void largest_number(char option);
void smallest_number(char option);
void mean_of_numbers(char option);
void clear_list(char option);
bool quit_list (char option);

vector <int>  list     {5,6,1,0,5,90,8,7,6};
vector <char> valid_Selects {'P', 'A', 'M', 'S', 'L', 'Q', 'p', 'a', 'm', 's', 'l', 'q','C','c'};

int main() 
{
    char user_choice{};
    do
    {
        user_choice = toupper(read_selection());
        print_list(user_choice);
        add_number(user_choice);
        largest_number(user_choice);
        smallest_number(user_choice);
        mean_of_numbers(user_choice);
        clear_list(user_choice);
    } while (quit_list (user_choice));
}
void print_menu_to_user()
{
    // Display the menu 
    cout << "\n-----------------------------------------" << endl ;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear the list - empty the list" << endl;
    cout << "Q - Quit" << endl << "Enter your choice: ";
}
char read_selection()
{
while (true)
{
    print_menu_to_user();
    char selection{};
    cin >> selection;
    for (char x :valid_Selects)
    {
        if (selection == x)
        {
            return selection;
        }
    }  
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "\n*** Invalid input! Please select a valid option: ***\n";
}
}
void print_list(char option)
{
    if (option != 'P')
    {
        return;
    }
    else
    {
        if (list.empty())
        cout << "[] - the list is empty"<< endl;
     else
        {
       
         {
            cout << "[ ";
            for (auto element : list)
            {
            cout << element << " ";
            }
            cout << " ]"<< endl;
           }
        }
    }
}
void add_number(char option)
{
    if (option != 'A')
    {
        return;
    }
    else
    {
        int new_num {0};
        cout << "please provide the list an integer number : ";
        cin >> new_num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "please provide the list an integer number : ";
            cin >> new_num;
        }
        list.push_back(new_num);
        cout << new_num << " added." << endl;
    }
}
void largest_number(char option)
{
if (option !='L')
    return;
if (list.empty())
    cout << "Unable to determine the largest number - list is empty"<<endl;  

int max = list.at(0);
for (auto i : list)
{
    if (i > max)
    {
    max=i;
    }                
}   
cout << "The Largest number is : " << max << endl ; 
}
void smallest_number(char option)
{
if(option != 'S')
    return;
if (list.empty())
    cout << "Unable to determine the smallest number - list is empty"<<endl;
int min = list.at(0);
for (auto i : list)
{
if (i < min)
   min=i;
}                
cout << "The smallest number is : " << min << endl;
}
void mean_of_numbers(char option)
{
    if (option != 'M')
        return;
    double mean {0};
    int sum {0};     
    if(list.empty())
        cout << "Unable to calculate the mean - no data"<<endl;
    for (auto i :list)
        {
        sum+=i;                          
        }
         mean = (sum)/list.size();
    cout << "The mean of the numbers in the list : "  <<  mean << endl;
}
bool quit_list (char option)
{
    return (option !='Q');
}     
void clear_list(char option)
{
if (option != 'C')
        return;
list.clear();
cout << "now list has destroyed";
}
