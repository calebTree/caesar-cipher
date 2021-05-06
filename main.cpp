#include <iostream>
#include "ceasar-cipher.h"
using namespace std;

int main() {
    cout << "\nWelcome to Julius Ceasar's Shift Cipher!"
            "\nEnter an integer to shift the normal alphabet left by that number of positions." << endl;
    cout << "Then, enter a message that will be encrypted using your cipher alphabet." << endl;
    cout << "https://en.wikipedia.org/wiki/Caesar_cipher\n" << endl;

    int option = -1;
    string plainAlpha = "abcdefghijklmnopqrstuvwxyz";
    char discard;

    while (option != 0) {
        cout << "(1) Encrypt, (2) Decrypt, (0) Quit: ";
        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                encryption(plainAlpha, discard);
                break;
            case 2:
                decryption(plainAlpha, discard);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
