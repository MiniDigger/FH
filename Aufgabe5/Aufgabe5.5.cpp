#include <iostream>
#include<fstream>

using namespace std;

void printFile(char *name);

int main(int argc, char *argv[]) {
    int i = 1;
    while (argv[i]) {
        printFile(argv[i++]);
    }
}

void printFile(char *name) {
    cout << "print " << name << endl;
    fstream f(name, fstream::in);
    if (!f) {
        cout << "unbekannte datei" << endl;
        return;
    }
    string s;
    getline(f, s, '\0');

    cout << s << endl;
    f.close();
}