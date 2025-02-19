#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
 
int main()
{
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string secret_message {};
    string true_message {};
    
    
    cout << "Write a message to make it secret: "; // prompt the user for a message to cipher 
    getline(cin,true_message);

    
    // for (size_t i {0} ; i < secret_message.size() ; i++)
    // {
    //     bool found {false};
    //     for (size_t j = 0; j < alphabet.size(); j++)
    //     {
    //         if (secret_message.at(i)==alphabet.at(j))
    //         {
    //             true_message.push_back(key.at(j));
    //             found = true;
    //             break;
    //         }           
    //     }       
    //     if (!found)
    //     {
    //         true_message.push_back(secret_message[i]);
    //     }
                
    // }  
    // cout << "\nsecret message is " << true_message << endl;
    
    //-----------------Another better solution--------------------//

    for (auto index : true_message)
    {
        size_t pos =alphabet.find(index);

            if (pos != string::npos)
            {
                secret_message.push_back(key.at(pos));
            }
            else if (pos == string::npos)
            {
                secret_message.push_back(index);
            }         
    }

    cout  << "\nsecret message is " << secret_message << endl;
    return 0;

}

