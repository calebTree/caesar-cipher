#include <iostream>
using namespace std;

void encryption();
void decryption();
string cipherAlpha(int, string);
string cipherMessage(string, string, string);
string decrypt(string, string, int);

int main() {
    cout << "\nWelcome to Julius Ceasar's Substitution Cipher!"
            "\nEnter an integer to shift the normal alphabet left by that number of positions." << endl;
    cout << "Then, enter a message that will be encrypted using your cipher alphabet." << endl;
    cout << "https://en.wikipedia.org/wiki/Caesar_cipher\n" << endl;

    int option;

    while (option != 0) {
        cout << "(1) Encrypt, (2) Decrypt, (0) Quit: ";
        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                encryption();
                break;
            case 2:
                decryption();
                break;
        }
    }

    return 0;
}
void encryption() {
    int key = 0;
    char discard;
    string message, cipherAlphabet, cipherText, alpha = "abcdefghijklmnopqrstuvwxyz";
    // input number of letters to shift
    cout << "Enter a Ceasar Shift Cipher key? (integer, 1-25): ";
    cin >> key;

    // input validation
    if (key > 25 || key < 1) {
        while (key > 25 || key < 1) {
            cout << "Error! Enter an integer between 1 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard); // discard \n

    cout << "Enter the message to encrypt. (lowercase, roman alpha): "; // input message to encrypt
    getline(cin, message);

    // shift alphabet [key] letters to the left
    cipherAlphabet = cipherAlpha(key, alpha);
    // encrypt the message using the cipher alphabet
    cipherText = cipherMessage(cipherAlphabet, alpha, message);

    cout << "\nPlaintext message: " << message << endl;
    cout << "Normal alphabet: " << alpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlphabet << " shifted [" << key << "] place(s) to the left." << endl;
    cout << "Ceasar Shift Cipher message: " << cipherText << endl << endl;
}

void decryption() {
    int key = 0;
    char discard;
    string cipherText;
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter the known cipher key? (integer, 1-25): ";
    cin >> key;
    cin.get(discard); // discard \n
    cout << "Enter the message to decrypt. (lowercase, roman alpha): "; // input message to decrypt
    getline(cin, cipherText);
    cout << "\nCipher message: " << cipherText << endl;
    cout << "Decrypted Ceasar Shift Cipher: " << decrypt(cipherText, alpha, key) << endl << endl;
}

string cipherAlpha(int key, string alpha) {
    string cypherAlpha = alpha; // cypherAlpha same size as alpha
    int p = 0; // wrap around variable
    for (int i = 0; i < alpha.size(); i++) {
        if (i + key >= alpha.size()) {
            cypherAlpha[i] = alpha[p];
            p++;
        } else {
            cypherAlpha[i] = alpha[i + key];
        }
    }
    return cypherAlpha;
}

string cipherMessage(string cipherAlpha, string alpha, string message) {
    string cipherText = message; // cipherText same size as message
    for (int i = 0; i < alpha.size(); i++) {
        for (int j = 0; j < message.size(); j++) {
            if (alpha[i] == message[j])
                cipherText[j] = cipherAlpha[i];
        }
    }
    return cipherText;
}

string decrypt(string cipherText, string alpha, int key) {
    string plainText = cipherText; // plainText same size as cipherText
    string cipherAlphabet = cipherAlpha(key, alpha);
    for (int i = 0; i < cipherAlphabet.size(); i++) {
        for (int j = 0; j < cipherText.size(); j++) {
            if (cipherAlphabet[i] == cipherText[j])
                plainText[j] = alpha[i];
        }
    }
    return plainText;
}
