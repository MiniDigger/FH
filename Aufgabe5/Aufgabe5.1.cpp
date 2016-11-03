#include <iostream>

using namespace std;

int main() {
    int matrix[2][3];

    // benötigter speicherplatz: 2*3*4=24

    int i;
    int j;

    cout << "i: ";
    cin >> i;
    cout << "j: ";
    cin >> j;

    int pos = (i * 3 + j) * 4;
    cout << "pos: " << pos << endl;
}