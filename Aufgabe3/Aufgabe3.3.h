#include <iostream>

using namespace std;

template<typename T>
T betrag(T t) {
    if (t < 0) return -t;
    return t;
}

template<>
bool betrag(bool i) {
    cout << "Betrag von bool nicht berechenbar";
    exit(-1);
}

template<>
char betrag(char i) {
    cout << "Betrag von char nicht berechenbar";
    exit(-1);
}