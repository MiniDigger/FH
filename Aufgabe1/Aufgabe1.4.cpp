#include<iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "input 3 numbers: " << endl;
    cin >> a >> b >> c;
    a = a > b ? a : b;
    a = a > c ? a : c;
    cout << "max: " << a;
    return 0;
}
