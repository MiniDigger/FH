#include<iostream>

using namespace std;

int main() {
    unsigned int unsignedInt;
    signed int signedInt;
    signed long signedLong;
    unsigned long unsignedLong;

    unsignedInt = ~0;
    signedInt = ~0U >> 1;
    signedLong = ~0Ul >> 1;
    unsignedLong = ~0;

    cout << "unsignedInt: " << unsignedInt << endl;
    cout << "signedInt: " << signedInt << endl;
    cout << "unsignedLong: " << unsignedLong << endl;
    cout << "signedLong: " << signedLong << endl;

    return 0;
}
