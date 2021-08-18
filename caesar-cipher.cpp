#include "caesar-cipher.h"

// https://www.tutorialspoint.com/cplusplus-program-to-implement-caesar-cypher
// https://www.asciihex.com/

using namespace std;

void encryption(const string &plainAlpha) {
    int key;
    string message, cipherAlphabet, cipherText;

    // input number of places to shift left
    cout << "Enter your chosen cipher key. (integer, 1-25): ";
    cin >> key;
    // input validation
    while (!cin || key > 25 || key < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error! Enter an integer between 1 and 25: ";
        cin >> key;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');     // discard \n
    cout << "Enter the message to encrypt: ";     // input message to encrypt
    getline(cin, message);

    // shift alphabet [key] letters to the left
    cipherAlphabet = cipherAlpha(key, plainAlpha);
    // encrypt the message using the cipher alphabet
    cipherText = cipherMessage(message, key);

    cout << "\nPlaintext: " << message << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlphabet << "; Shifted [" << key << "] place(s) to the left." << endl;
    cout << "Ciphertext: " << cipherText << endl << endl;
}

void decryption(const string &plainAlpha) {
    int key;
    string cipherText;

    cout << "Enter your known cipher key. (integer, 1-25): ";
    cin >> key;
    // input validation
    while (!cin || key > 25 || key < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error! Enter an integer between 1 and 25: ";
        cin >> key;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');                // discard \n
    cout << "Enter the message to decrypt: ";     // input message to decrypt
    getline(cin, cipherText);

    cout << "\nCiphertext: " << cipherText << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlpha(key, plainAlpha) << "; Shifted [" << key << "] place(s) to the left." << endl;
    // display decrypted message
    cout << "Plaintext: " << decrypt(cipherText, key) << endl << endl;
}

string cipherAlpha(int &key, const string &plainAlpha) {
    string cipherAlpha;
    for (char c : plainAlpha) {
        cipherAlpha += static_cast<char>((c + key - 65) % 26 + 65);
    }
    return cipherAlpha;
}

string cipherMessage(const string &message, int &key) {
    string cipherText;
    for (char c : message) {
        if (c >= 65 && c <= 122)
            if (isupper(c)) {
                cipherText += static_cast<char>((c + key - 65) % 26 + 65);
            } else {
                cipherText += static_cast<char>((c + key - 97) % 26 + 97);
            }
        else
            cipherText += c;
    }
    return cipherText;
}

string decrypt(const string &cipherText, int &key) {
    string plainText;
    for (char c : cipherText) {
        if (c >= 65 && c <= 122)
            if (isupper(c)) {
                plainText += static_cast<char>((c - key - 65 % 26 + 26) % 26 + 65);
            } else {
                plainText += static_cast<char>((c - key - 97 % 26 + 26) % 26 + 97);
            }
        else
            plainText += c;
    }
    return plainText;
}
