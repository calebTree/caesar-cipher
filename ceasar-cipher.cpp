//
// Created by caleb on 5/5/2021.
//
#include "ceasar-cipher.h"
#include <iostream>
using namespace std;

void encryption(const string &plainAlpha, char &discard) {
    int key;
    string message, cipherAlphabet, cipherText;

    // input number of places to shift left
    cout << "Enter your chosen cipher key. (integer, 1-25): ";
    cin >> key;
    // input validation
    if (key > 25 || key < 1) {
        while (key > 25 || key < 1) {
            cout << "Error! Enter an integer between 1 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard);                                                   // discard \n
    cout << "Enter the message to encrypt. (lowercase, roman alpha): ";     // input message to encrypt
    getline(cin, message);

    // shift alphabet [key] letters to the left
    cipherAlphabet = cipherAlpha(key, plainAlpha);
    // encrypt the message using the cipher alphabet
    cipherText = cipherMessage(cipherAlphabet, plainAlpha, message);

    cout << "\nPlaintext: " << message << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlphabet << "; Shifted [" << key << "] place(s) to the left." << endl;
    cout << "Ciphertext: " << cipherText << endl << endl;
}

void decryption(const string &plainAlpha, char &discard) {
    int key;
    string cipherText;

    cout << "Enter the known cipher key. (integer, 1-25): ";
    cin >> key;
    // input validation
    if (key > 25 || key < 1) {
        while (key > 25 || key < 1) {
            cout << "Error! Enter an integer between 1 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard);                                                   // discard \n
    cout << "Enter the message to decrypt. (lowercase, roman alpha): ";     // input message to decrypt
    getline(cin, cipherText);

    cout << "\nCiphertext: " << cipherText << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlpha(key, plainAlpha) << "; Shifted [" << key << "] place(s) to the left." << endl;
    // display decrypted message
    cout << "Plaintext: " << decrypt(cipherText, plainAlpha, key) << endl << endl;
}

string cipherAlpha(int &key, const string &plainAlpha) {
    string cipherAlpha = plainAlpha;                // cypherAlpha same size as plainAlpha
    int p = 0;                                      // wrap around variable
    for (int i = 0; i < plainAlpha.size(); i++) {
        if (i + key >= plainAlpha.size()) {         // wrap around when i + key >= 26
            cipherAlpha[i] = plainAlpha[p];         // shift cipherAlpha
            p++;
        } else {
            cipherAlpha[i] = plainAlpha[i + key];   // shift cipherAlpha
        }
    }
    return cipherAlpha;
}

string cipherMessage(const string &cipherAlpha, const string &plainAlpha, const string &message) {
    string cipherText = message;                        // cipherText same size as message
    for (int i = 0; i < cipherAlpha.size(); i++) {      // loop over all letters in the alphabet
        for (int j = 0; j < message.size(); j++) {      // loop over all letters in the message
            if (plainAlpha[i] == message[j])
                cipherText[j] = cipherAlpha[i];         // replace each plainAlpha letter in the message with the cipherAlpha letter
        }
    }
    return cipherText;
}

string decrypt(const string &cipherText, const string &plainAlpha, int &key) {
    string plainText = cipherText;                                  // plainText same size as cipherText
    string cipherAlphabet = cipherAlpha(key, plainAlpha);       // generate cipherAlphabet
    for (int i = 0; i < cipherAlphabet.size(); i++) {               // loop over all letters in alphabet
        for (int j = 0; j < cipherText.size(); j++) {               // loop over all letters in the cipherText
            if (cipherAlphabet[i] == cipherText[j])
                plainText[j] = plainAlpha[i];                       // replace each cipherAlpha letter in the message with the plainAlpha letter
        }
    }
    return plainText;
}