// Clyde Marty
// CIS 7 Final Project
// 12/14/2022
// Professor Nguyen

/*-----------------------------------------------------.
|                                                      |
|   PROJECT CASE 3: VIGENERE CIPHER DECRYPTION (V1)    |
|                                                      |
 -----------------------------------------------------.*/

#include <iostream>
#include <string>
#include <algorithm>                        // I need this to use transform command
#include <cctype>                           // toupper, tolower
using namespace std ;

// Prototypes
void textNkey();
void encrypt(string m, string k);           // m = message  // k = key
void decrypt(string m, string k);

void encrypt (string m, string k)           // begin encryption function
{
    
    cout << endl;
    
    string output;
    
    for (int i = 0; i < m.length(); i++)
    {
        char x = (m[i] + k[i]) % 26;
        
        x = x + 'A';
        
        output.push_back(x);               // pushes output elements in the back of array
    }
    
    cout << "Encrypted text is: " << output << endl;
    
    cout << endl;
    
    char input;
    cout << "Would you like to Decrypt this message? Select Y or N" << endl << endl;
    
    
    do {
        cin >> input;
        
        //char upper = toupper(input);

        if (toupper(input) == 'Y')
        {
            decrypt(output, k);
        }
        else if (toupper(input) == 'N')
        {
            cout << "Exiting... \n";
            
            exit(0);
        }
        else
        {
            cout << "Invalid input. Try again." << endl;
        }
        
    } while (input != 'Y' || input != 'N'); // do - while validation
    
} // end encryption function

void decrypt (string m, string k)           // begin decryption function  // Note : Decryption is inacurrate
{
    cout << endl;
    
    string output;
    
    for (int i = 0; i < m.length(); i++)
    {
        char x = (m[i] - k[i]) % 26;
        
        x = x + 'A';
        
        output.push_back(x);
    }
    
    cout << "Decrypted text is: " << output << endl;
    
    cout << endl;
    
    cout << "Exiting... \n";
    
    exit(0);
}                                           // end decryption function */

void textNkey()   // takes user input for text and key
{
    cout << endl;
    
    // int input;
    string message;
    string key;
    
    cin.ignore();
    cout << "Enter sample message: ";
    getline(cin, message);                                                   // Input plaintext

    
    transform(message.begin(), message.end(), message.begin(), :: toupper);   // capitalizes Plaintext
    
    cout << endl;
    
    cout << "Now, enter a key: ";
    
    do {                                          // do-while validation
        getline(cin, key);                                                          // Input key
        
        transform(key.begin(), key.end(), key.begin(), :: toupper);                //  // capitalizes Key
        
        if (key.length() > message.length())
        {
            cout << "Number of characters in key cannot be larger than original message. Try again." << endl;
        }
        
    } while (key.length() > message.length());    // do- while validation
/*
 
 // Needs: Mapping key to plaintext
 
 for (int i = 0; i <= message; i++)
    {
        key = me
    } */
    
    cout << endl;
   
    cout << "Encrypting... \n";
    encrypt(message, key);
    
}   // end function
 
int main()      // begin main
{
    int input;
    
    cout << "This program simualates a standard Vigenere Cipher. \n";
    cout << "Select an option below (1 or 2): \n";
    cout << "-----------------------------" << endl;
    
    do {  // begin do while for input validation
        cout << "(1) Begin Program "<< endl;
        cout << "(2) End Program " << endl << endl;
        
        cin >> input;
        
        if (input == 1) {
            textNkey();                // begins actual program
        }
        else if (input == 2) {
            exit(0);                    // ends program
        }
        else {
            
            cout << "Invalid input. Try again. " << endl;
        }
        
    } while (input !=1 || input !=2 );  // end do-while
    
    return 0;
    
}   // end main

