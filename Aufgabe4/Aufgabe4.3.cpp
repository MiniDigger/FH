#include "IntMenge.h"
#include <iostream>

using namespace std;

int main() {
    IntMenge menge;
    menge.hinzufuegen(2); // ok
    menge.hinzufuegen(-9); // ok
    menge.hinzufuegen(2); // keine Wirkung, 2 gibt es schon
    menge.entfernen(99); // keine Wirkung, nicht vorhanden
    menge.entfernen(-9); // ok
    menge.anzeigen();
    menge.loeschen();
    for (int i = 17; i < 33; ++i) {
        menge.hinzufuegen(i * i);
    }
    menge.anzeigen();
    cout << "Anzahl=" << menge.size() << " Minimum=" << menge.getMin() << endl;
    if (menge.istMitglied(-11)) {
        cout << "-11 ist mitglied" << endl;
    }
    IntMenge mengeB(menge);
    if (mengeB.istMitglied(-11)) {
        cout << "-11 ist mitglied" << endl;
    }
}