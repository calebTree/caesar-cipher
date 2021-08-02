#ifndef CEASAR_CIPHER_CEASAR_CIPHER_H
#define CEASAR_CIPHER_CEASAR_CIPHER_H

#endif //CEASAR_CIPHER_CEASAR_CIPHER_H

#include <iostream>
using namespace std;

void encryption(const string&, char&);
// Function to display encrypt interface
// Postcondition: string is the plain alphabet displayed and ciphered;
//                char discards \n

void decryption(const string&, char&);
// Function to display decrypt interface
// Postcondition: string is the plain alphabet displayed and ciphered;
//                char discards \n

string cipherAlpha(int&, const string&);
// Function to generate cipher alphabet.
// Postcondition: const string shifted left by int positions

string cipherMessage(const string&, const string&, const string&);
// Function to encrypt the message
// Postcondition: string A (plain alphabet), compared to string B (cipher alphabet)
//                string C (message) enciphered

string decrypt(const string&, const string&, int&);
// Function to decrypt the message
// Postcondition: string A (ciphertext), compared to string B (plain alphabet)
//                deciphered (shifted) by int positions
