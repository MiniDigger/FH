#include "rational.cpp"

using namespace std;

void ausgabe(Rational a);

int main() {
    ausgabe(Rational(1337, 42));
}

void ausgabe(Rational a) {
    cout << a.getZaehler() << "/" << a.getNenner() << endl;
}