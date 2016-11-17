// Klasse für rationale Zahlen
//////////////////////////////

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational {
public:
    Rational();

    Rational(long z, long n);   // allgemeiner Konstruktor
    Rational(long z) : Rational(z, 1) {};             // Typumwandlungskonstruktor

    // Abfragen
    long getZaehler() const;

    long getNenner() const;

    // arithmetische Methoden
    // (werden später durch überladene Operatoren ergänzt)
    void add(const Rational &r);

    void sub(const Rational &r);

    void mult(const Rational &r);

    void div(const Rational &r);

    // weitere Methoden
    void set(long zaehler, long nenner);

    void eingabe();

    void ausgabe() const;

    void kehrwert();

    void kuerzen();

    friend istream &operator>>(istream &input, Rational &r) {
        input >> r.zaehler >> r.nenner;
        return input;
    }

    friend bool operator==(Rational &r1, Rational &r2) {
        return (r1.getNenner() == r2.getNenner()) && (r1.getZaehler() == r2.getZaehler());
    }

    const Rational &operator+=(const Rational &rhs) {
        add(rhs);
        return *this;
        // return type is Rational& damit man mit dem ergebnis weiterarbeiten kann
    }

    const Rational &operator-=(const Rational &rhs) {
        sub(rhs);
        return *this;
    }

    const Rational &operator*=(const Rational &rhs) {
        mult(rhs);
        return *this;
    }

    const Rational &operator/=(const Rational &rhs) {
        div(rhs);
        return *this;
    }

    friend Rational operator+(const Rational &lhs, const Rational &rhs) {
        Rational r = Rational(lhs.getZaehler(), lhs.getNenner());
        r.add(rhs);
        return r;
    }

    friend Rational operator-(const Rational &lhs, const Rational &rhs) {
        Rational r = Rational(lhs.getZaehler(), lhs.getNenner());
        r.sub(rhs);
        return r;
    }

    friend Rational operator*(const Rational &lhs, const Rational &rhs) {
        Rational r = Rational(lhs.getZaehler(), lhs.getNenner());
        r.mult(rhs);
        return r;
    }

    friend Rational operator/(const Rational &lhs, const Rational &rhs) {
        Rational r = Rational(lhs.getZaehler(), lhs.getNenner());
        r.div(rhs);
        return r;
    }

private:
    long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational() : zaehler(0), nenner(1) {}

inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {}
//inline Rational::Rational(long ganzeZahl) : zaehler(ganzeZahl), nenner(1) {}

inline long Rational::getZaehler() const { return zaehler; }

inline long Rational::getNenner() const { return nenner; }

// globale Funktionen
const Rational add(const Rational &a, const Rational &b);

const Rational sub(const Rational &a, const Rational &b);

const Rational mult(const Rational &a, const Rational &b);

const Rational div(const Rational &z, const Rational &n);

#endif
