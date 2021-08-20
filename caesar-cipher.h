#ifndef CAESAR_CIPHER_CAESAR_CIPHER_H
#define CAESAR_CIPHER_CAESAR_CIPHER_H

#endif //CAESAR_CIPHER_CAESAR_CIPHER_H

#include <iostream>
#include<limits>

using namespace std;

void encryption(const string&);
// Function to display encrypt interface.
// Postcondition: const string is the alphabet displayed in plain then in ciphered.

void decryption(const string&);
// Function to display decrypt interface.
// Postcondition: const string is the alphabet displayed in plain then in ciphered.

string cipherAlpha(int&, const string&);
// Function to generate cipher alphabet.
// Postcondition: const string is alphabet shifted left by int positions.

string cipherMessage(const string&, int&);
// Function to encrypt the message.
// Postcondition: const string is message shifted left by int positions.

string decrypt(const string&, int&);
// Function to decrypt the message.
// Postcondition: const string is ciphertext shifted back by int positions.