#include <iostream>
#include "rational.cpp"

using namespace std;

Rational add(long a, Rational b);

Rational add(Rational a, long b);

int main() {
    Rational a = Rational(10, 1);
    add(10, a).ausgabe();

    Rational b = Rational(4, 2);
    add(b, 5).ausgabe();
}

Rational add(long a, Rational b) {
    Rational aa = Rational(a, 1);
    aa.add(b);
    return aa;
}

Rational add(Rational a, long b) {
    Rational bb = Rational(b, 1);
    bb.add(a);
    return bb;
}