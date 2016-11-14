#ifndef TEILNEHMER_H
#define TEILNEHMER_H

#include <vector>
#include <string>

class Teilnehmer {
public:
    Teilnehmer(std::string name)  {
        this->name = name;
    }

    void lerntKennen(Teilnehmer teilnehmer);

    void druckeBekannte();

    std::string gibNamen();

private:
    std::string name;
    std::vector<Teilnehmer> friends;
};


#endif