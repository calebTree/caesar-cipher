#include <iostream>
#include "caesar-cipher.h"

using namespace std;

int main() {
    cout << "\nWelcome to Julius Caesar's Shift Cipher!"
            "\nEnter an integer to shift the normal alphabet left by that number of positions." << endl;
    cout << "Then, enter a message that will be encrypted using the generated cipher alphabet." << endl;
    cout << "https://en.wikipedia.org/wiki/Caesar_cipher\n" << endl;

    int option;
    string plainAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(;;) {
        cout << "(1) Encrypt, (2) Decrypt, (0) Quit: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Invalid input." << endl;
            continue;
        }
        switch (option) {
            case 0:
                return 0;
            case 1:
                encryption(plainAlpha);
                break;
            case 2:
                decryption(plainAlpha);
                break;
            default:
                cout << "Error! Invalid choice." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
