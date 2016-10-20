#include<iostream>
#include "gettype.h"
using namespace std;
int main() {
    // Ausgabe
    int i;
    cout << getType(i) << endl; // int
    unsigned int ui;
    cout << getType(ui) << endl; // unsigned int
    char c;
    cout << getType(c) << endl; // char
    bool b;
    cout << getType(b) << endl; // bool
    // Annahme: float ist nicht in getType() berücksichtigt:
    float f;
    cout << getType(f) << endl; // unbekannter Typ!
}