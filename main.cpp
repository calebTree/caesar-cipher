#include <iostream>
using namespace std;

void encryption();
void decryption();
string cipherAlpha(int, string);
string cipherMessage(string, string, string);
string decrypt(string, string, int);

int main() {
    cout << "\nWelcome to Julius Ceasar's Shift Cipher!"
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
    string message, cipherAlphabet, cipherText, plainAlpha = "abcdefghijklmnopqrstuvwxyz";

    // input number of letters to shift
    cout << "Enter your chosen cipher key. (integer, 1-25): ";
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
    cipherAlphabet = cipherAlpha(key, plainAlpha);
    // encrypt the message using the cipher alphabet
    cipherText = cipherMessage(cipherAlphabet, plainAlpha, message);

    cout << "\nPlaintext: " << message << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlphabet << "; Shifted [" << key << "] place(s) to the left." << endl;
    cout << "Ciphertext: " << cipherText << endl << endl;
}

void decryption() {
    int key = 0;
    char discard;
    string cipherText;
    string plainAlpha = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter the known cipher key. (integer, 1-25): ";
    cin >> key;
    // input validation
    if (key > 25 || key < 1) {
        while (key > 25 || key < 1) {
            cout << "Error! Enter an integer between 1 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard); // discard \n
    cout << "Enter the message to decrypt. (lowercase, roman alpha): "; // input message to decrypt
    getline(cin, cipherText);
    cout << "\nCiphertext: " << cipherText << endl;
    cout << "Plain alphabet:  " << plainAlpha << "." << endl;
    cout << "Cipher alphabet: " << cipherAlpha(key, plainAlpha) << "; Shifted [" << key << "] place(s) to the left." << endl;
    // display decrypted message
    cout << "Plaintext: " << decrypt(cipherText, plainAlpha, key) << endl << endl;
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

string cipherMessage(string cipherAlpha, string plainAlpha, string message) {
    string cipherText = message; // cipherText same size as message
    for (int i = 0; i < plainAlpha.size(); i++) {
        for (int j = 0; j < message.size(); j++) {
            if (plainAlpha[i] == message[j])
                cipherText[j] = cipherAlpha[i];
        }
    }
    return cipherText;
}

string decrypt(string cipherText, string plainAlpha, int key) {
    string plainText = cipherText; // plainText same size as cipherText
    string cipherAlphabet = cipherAlpha(key, plainAlpha);
    for (int i = 0; i < cipherAlphabet.size(); i++) {
        for (int j = 0; j < cipherText.size(); j++) {
            if (cipherAlphabet[i] == cipherText[j])
                plainText[j] = plainAlpha[i];
        }
    }
    return plainText;
}
