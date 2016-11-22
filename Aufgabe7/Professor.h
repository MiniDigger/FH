#ifndef FH_PROFESSOR_H
#define FH_PROFESSOR_H

#include "Person.h"

class Professor : public Person {
public:
    Professor(const string &vorname, const string &nachname, const string &lehrgebiet)
            : Person(vorname, nachname), lehrgebiet(lehrgebiet) {};

    const string &getLehrgebiet() const { return lehrgebiet; };

    const string toString() const {
        return "Student: " + getVorname() + " " + getNachname() + " #" + getLehrgebiet();
    }

private:
    string lehrgebiet;
};


#endif //FH_PROFESSOR_H
