#include "rational.h"

int main() {
    Rational r1;
    cin >> r1;
    r1.ausgabe();

    Rational r2;
    cin >> r2;
    r2.ausgabe();

    if (r2 == r1) {
        cout << "yeah" << endl;
    } else {
        cout << "nope" << endl;
    }

    (r1 += r2).ausgabe();

    (r1 -= r2).ausgabe();

    cout << "add 2 to ";
    r1.ausgabe();
    cout << endl;
    (r1 + 2).ausgabe();
}