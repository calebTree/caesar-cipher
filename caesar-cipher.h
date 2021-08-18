#ifndef CAESAR_CIPHER_CAESAR_CIPHER_H
#define CAESAR_CIPHER_CAESAR_CIPHER_H

#endif //CAESAR_CIPHER_CAESAR_CIPHER_H

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

string cipherMessage(const string&, int&);
// Function to encrypt the message
// Postcondition: string message shifted left by int positions

string decrypt(const string&, int&);
// Function to decrypt the message
// Postcondition: string ciphertext shifted back to the right by int positions