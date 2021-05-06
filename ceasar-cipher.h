//
// Created by caleb on 5/5/2021.
//

#ifndef CEASAR_CIPHER_CEASAR_CIPHER_H
#define CEASAR_CIPHER_CEASAR_CIPHER_H

#endif //CEASAR_CIPHER_CEASAR_CIPHER_H

#include <iostream>
using namespace std;

void encryption(const string&, char&);                                  // encryption option
void decryption(const string&, char&);                                  // decryption option
string cipherAlpha(int&, const string&);                                // generate cipher alphabet
string cipherMessage(const string&, const string&, const string&);      // encrypt the message
string decrypt(const string&, const string&, int&);                     // decrypt the message
