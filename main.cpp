#include <iostream>
using namespace std;

string cipherAlpha(int, string);
string cipherMessage(string, string, string);

int main() {

    int key = 0;
    char discard;
    string message, cypherAlpha, cipherText, alpha = "abcdefghijklmnopqrstuvwxyz";

    cout << "Ceasar Shift Cipher key? (0-25): ";
    cin >> key;
    if (key > 25) {
        while(key > 25 || key < 0) {
            cout << "Error! Enter an integer between 0 and 25: ";
            cin >> key;
        }
    }
    cin.get(discard); // discard \n

    cout << "Message: ";
    getline(cin, message);

    cypherAlpha = cipherAlpha(key, alpha); // shift alphabet [key] letters to the left
    cipherText = cipherMessage(cypherAlpha, alpha, message); // encrypt the message with the cipher alphabet

    cout << "Plaintext message: " << message << endl;
    cout << "Normal alphabet: " << alpha << endl;
    cout << "Cipher alphabet: " << cypherAlpha << endl;
    cout << "Ceasar Cipher message: " << cipherText << endl;

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