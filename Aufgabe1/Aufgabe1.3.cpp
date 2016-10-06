#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double p, q, x1, x2;
    cout << "enter p and q: ";
    cin >> p >> q;
    x1 = -p / 2 + sqrt((p / 2) * (p / 2) - q);
    x2 = -p / 2 - sqrt((p / 2) * (p / 2) - q);
    cout << "x1 " << x1 << ", x2 " << x2;
    return 0;
}
