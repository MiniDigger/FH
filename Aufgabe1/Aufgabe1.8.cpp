#include<iostream>

using namespace std;

int main() {
    int n1, n2, sum;
    cout << "enter n1 and n2: " << endl;
    cin >> n1 >> n2;

    // a) for schleife
    sum = 0;
    for (int i = n1; i <= n2; i++) {
        sum += i;
    }
    cout << "a) " << sum << endl;

    // b) while
    sum = 0;
    int i = n1;
    while (i <= n2) {
        sum += i;
        i++;
    }
    cout << "b) " << sum << endl;

    // c) do-while
    sum = 0;
    i = n1;
    do {
        sum += i;
        i++;
    } while (i <= n2);
    cout << "c) " << sum << endl;

    // d) ohne schleife
    sum = n2 * (n2 + 1) / 2 - n1 * (n1 - 1) / 2;
    cout << "d) " << sum << endl;

    return 0;
}