#include <iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]) {
    string name;
    cout << "name: ";
    cin >> name;

    fstream f(name, fstream::in);
    if (!f) {
        cout << "unbekannte datei" << endl;
        return 0;
    }
    string s;
    getline(f, s, '\0');
}