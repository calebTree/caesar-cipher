#include <iostream>
using namespace std;

string cipherAlpha(int, string);
string cipherMessage(string, string, string);

int main() {

    int key = 0;
    char discard;
    string message, cypherAlpha, cipherText, alpha = "abcdefghijklmnopqrstuvwxyz";

    cout << "\nJulius Ceasar's Substitution Cipher!"
            "\nEnter an integer to shift the normal alphabet by that number of positions." << endl;
    cout << "Then, enter a message to encrypt using your cipher alphabet." << endl;

    // input number of letters to shift
    cout << "\nEnter the Ceasar Shift Cipher key? (integer, 1-25): ";
    cin >> key;

    // input validation
    if (key > 25 || key < 1) {
        while(key > 25 || key < 1) {
            cout << "Error! Enter an integer between 1 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard); // discard \n

    cout << "Enter the message to encrypt. (lowercase, roman alpha): "; // input message to encrypt
    getline(cin, message);

    // shift alphabet [key] letters to the left
    cypherAlpha = cipherAlpha(key, alpha);
    // encrypt the message using the cipher alphabet
    cipherText = cipherMessage(cypherAlpha, alpha, message);

    cout << "\nPlaintext message: " << message << endl;
    cout << "Normal alphabet: " << alpha << "." << endl;
    cout << "Cipher alphabet: " << cypherAlpha << ". Shifted [" << key << "] place(s) to the left." << endl;
    cout << "Ceasar Shift Cipher message: " << cipherText << endl;

    return 0;
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
    for(int i = 0; i < alpha.size(); i++) {
        for(int j = 0; j < message.size(); j++) {
            if(alpha[i] == message[j])
                cipherText[j] = cipherAlpha[i];
        }
    }
    return cipherText;
}
