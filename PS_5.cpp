#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    char selection {'0'};
    
    vector <int>  vec      {5,6,1,0,5,90,8,7,6};
    vector <char> valid_Selects {'P', 'A', 'M', 'S', 'L', 'Q', 'p', 'a', 'm', 's', 'l', 'q'};
    do
    {
        // Display the menu 
        cout << "\n-----------------------------------------" << endl ;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << "Enter your choice: ";
        cin >> selection; // prompt the user for selection
        bool check_validation {false};// check the validation of user input
        for (auto val : valid_Selects)
        {
           if (val == selection)
           {
            check_validation =true;
            break; // EXit the check if the input is valid
           }          
           else 
           continue;
        }      
        if (check_validation)
        {
            switch (selection)
            {
             case 'P':
             case 'p':
             {
                 if (!vec.empty())
                    {
                     cout << "[ ";
                     for (auto i : vec)
                     {
                     cout << i << " ";
                     }
                     cout << " ]"<< endl;
                    }
                 else
                    {
                     cout << "[] - the list is empty"<< endl;
                    }
                 break;
                }         
             case 'A':
             case 'a': 
                {
                int add {0};
                cout << "please provide the list an integer number : "; 
                cin >> add;
                vec.push_back(add);
                cout << add << " added." << endl;
                break;
                }
                
             case 'm':
             case 'M':
                {
                double mean {0};
                int sum {0};
                
                    if(vec.empty())
                    {
                        cout << "Unable to calculate the mean - no data"<<endl;
                        
                    }
                    else
                    {
                        for (auto i :vec)
                        {
                            sum+=i;                          
                        }
                        mean = (sum)/vec.size();
                        cout << "The mean of the numbers in the list : "  <<  mean << endl;
                    }
                    break;
                }
             case 'S':
             case 's':
             {             
             if (vec.empty())
             {
                cout << "Unable to determine the smallest number - list is empty"<<endl;               
             }
             else
             {              
                int min = vec.at(0);
                for (auto i : vec)
                {
                    if (i < min)
                    {
                        min=i;
                    }                
                }
                cout << "The smallest number is : " << min << endl;
             }
             break;
             }
             case 'L':
             case 'l':
             if (vec.empty())
             {
                cout << "Unable to determine the largest number - list is empty"<<endl;               
             }
             else
             {
                int max = vec.at((vec.size()-1));
                for (auto i : vec)
                {
                    if (i > max)
                    {
                        max=i;
                    }                
                }
                cout << "The Largest number is : " << max << endl ; 
             }
            }
        }
        else
        {
            cout << "\n*Unknown selection, please try again*" << endl;
        }
    } while (selection != 'Q' && selection !='q');
    cout << "Good Bye!" << endl;
    return 0;
}