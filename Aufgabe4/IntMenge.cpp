#include "IntMenge.h"
#include <iostream>

using namespace std;

void IntMenge::hinzufuegen(int el) {
    if (!istMitglied(el)) {
        els.push_back(el);
    }
}

void IntMenge::entfernen(int el) {
    int index = indexOf(el);
    if (index != -1) {
        els.erase(els.begin() + index);
    }
}

bool IntMenge::istMitglied(int el) {
    return indexOf(el) != -1;
}

size_t IntMenge::size() {
    return els.size();
}

void IntMenge::anzeigen() {
    for (int i = 0; i < size(); i++) {
        cout << els[i] << " ";
    }
    cout << endl;
}

void IntMenge::loeschen() {

}

int IntMenge::getMax() {
    int max = -1000000;
    for (int i = 0; i < size(); i++) {
        if (els[i] > max) {
            max = els[i];
        }
    }
    return max;
}

int IntMenge::getMin() {
    int max = 1000000;
    for (int i = 0; i < size(); i++) {
        if (els[i] < max) {
            max = els[i];
        }
    }
    return max;
}

int IntMenge::indexOf(int el) {
    for (int i = 0; i < size(); i++) {
        if (els[i] == el) {
            return i;
        }
    }
    return -1;
}