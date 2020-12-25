#include <iostream>
using namespace std;

string cypher(int, string);

int main() {

    string chars = "abcdefghijklmnopqrstuvwxyz";
    int key = 0;
    char discard;
    string message;

    cout << "Ceasar Cypher Key (1-25): ";
    cin  >> key;
    cin.get(discard);

    cout << "Message: ";
    getline(cin, message);

    cout << "Your message in plaintext: " << message << endl;

    cout << "Your Ceasar Cypher message: " << cypher(key, message) << endl;

    return 0;
}

string cypher(int key, int message) {
    string cyphertext;



    return cyphertext;
}
