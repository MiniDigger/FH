#include "Teilnehmer.h"
#include <algorithm>
#include <iostream>

void Teilnehmer::lerntKennen(Teilnehmer teilnehmer) {
    if (teilnehmer.name.compare(this->name)) return;
    if (std::find(friends.begin(), friends.end(), teilnehmer) != friends.end()) return;

    friends.push_back(teilnehmer);
    teilnehmer.friends.push_back(*this);
}

void Teilnehmer::druckeBekannte() {
    for (unsigned int i = 0; i < friends.size(); i++) {
        std::cout << friends.at(i).name << " ";
    }
    std::cout << std::endl;
}

std::string Teilnehmer::gibNamen() {
    return name;
}
