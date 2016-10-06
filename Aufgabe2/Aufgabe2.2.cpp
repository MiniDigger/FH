#include<iostream>

using namespace std;

int main() {
    cout << "gebe N > 2 ein:" << endl;
    unsigned long long n;
    cin >> n;

    long it = 0;

    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }
        it++;
        cout << n << endl;

        string dummy;
     //   getline(cin, dummy); // weiter mit Tastendruck
    }

    cout << "finished after " << it << " iterations";
    return 0;
}