#include <iostream>
#include "Aufgabe3.3.h"

using namespace std;

int main() {
    cout << "betrag von -10 " << betrag(-10) << endl;
    cout << "betrag von 10 " << betrag(10) << endl;
    cout << "betrag von -10.10 " << betrag(-10.10) << endl;
    cout << "betrag von 10.10 " << betrag(10.10) << endl;
    cout << "betrag von 'c'" << betrag('c') << endl;
}