#include <iostream>

using namespace std;

void leerzeichenEntfernen(char *s);

int main() {
    char s[] = " a bb ccc d";
    cout << s << endl;
    leerzeichenEntfernen(s);
    cout << s << endl;
}

void leerzeichenEntfernen(char *s) {
    char *cpy = s;
    char *temp = s;

    while (*cpy) {
        if (*cpy != ' ') {
            *temp++ = *cpy;
        }
        cpy++;
    }
    *temp = 0;
}