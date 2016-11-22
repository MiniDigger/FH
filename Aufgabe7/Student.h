#ifndef FH_STUDENT_H
#define FH_STUDENT_H

#include "Person.h"

class Student : public Person {

public:
    Student(const string &vorname, const string &nachname, const string &matrikelnummer)
            : Person(vorname, nachname), matrikelnummer(matrikelnummer) {};

    const string &getMatrikelnummer() const { return matrikelnummer; };

    const string toString() const {
        return "Student: " + getVorname() + " " + getNachname() + " #" + getMatrikelnummer();
    }

private:
    const string matrikelnummer;
};


#endif //FH_STUDENT_H
