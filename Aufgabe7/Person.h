#ifndef FH_PERSON_H
#define FH_PERSON_H

#include <string>

using namespace std;

class Person {

public:
    Person(const string &vorname, const string &nachname) : vorname(vorname), nachname(nachname) {};

    const string &getNachname() const { return nachname; };

    const string &getVorname() const { return vorname; };

    virtual const string toString() const = 0;

private:
    const string vorname;
    const string nachname;
};


#endif //FH_PERSON_H
