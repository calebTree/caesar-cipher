#include <iostream>
//#include <cmath>
using namespace std;

string cypher(int);

int main() {

    int key = 0;
    char discard;
    string message;
    string alphaCypher;

    cout << "Ceasar Cypher Shift (key), (1-25): ";
    cin  >> key;
    cin.get(discard);

    cout << "Message: ";
    getline(cin, message);

    cout << "Your message in plaintext: " << message << endl;
    cout << "Your Ceasar Cypher message: " << cypher(key) << endl;

    return 0;
}

string cypher(int key) {
//    string cyphertext;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string cypherAlpha = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < alpha.size(); i++) {
        if (i + key >= alpha.size()) {
            cypherAlpha[i] = alpha[--key];
        } else {
            cypherAlpha[i] = alpha[i + key];
        }
    }
    return cypherAlpha;
}
