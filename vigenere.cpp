/*
Author: Kartik Vanjani
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 6C
Description: This program takes in an input of a string and outputs
the string generated from the shift that is applied
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift) {
    int y = int(c);
    if(y >= 'A' && y <= 'Z') { 
        c += rshift; 

        if(c > 'Z') {  
            c -= 26;  
            return c;
        }
        else if(c < 'A') {
            c += 26;
            return c;
        }

        return c;
    }
    else if(y >= 'a' && y <= 'z') { 
        int x = y + rshift; 

        if(x > 'z') {
            x -= 26; 
            c = x; 
            return c;
        }
        else if(x < 'a') {
            x += 26; 
            c = x;
            return c;
        }
        c = x;
        return c;
    }

    return c;
}

string encryptCaesar(string plaintext, int rshift) {
    char c;

    for(int i = 0; i < plaintext.size(); i++) {
        c = plaintext[i];
        plaintext[i] = shiftChar(c, rshift); 
    }

    return plaintext;
}
string encryptVigenere(string plaintext, string keyword) {
    int x = 0;
    char c;

    for(int i = 0; i < plaintext.length(); i++) { 
        c = plaintext[i];    
        if(x > keyword.length() - 1){ 
            x = 0;
        }
        if(isalpha(c)) {  
            plaintext[i] = shiftChar(c, keyword[x]-97); 
            x++;
        }
             
        }
        return plaintext;
    }
int main(){
    string plaintext;
    cout << "Enter plaintext: ";
    cin >> plaintext;
    string kshift;
    cout << "Enter keyword: ";
    cin >> kshift;
    cout << encryptVigenere(plaintext,kshift);
    return 0;
}