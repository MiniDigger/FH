#include <iostream>
#include <cmath>

using namespace std;

double ehoch(double x);

double pow(double x, double y);

double facu(int x);

int main() {
    for (int i = -40; i <= 40; i += 10) {
        cout << "ehoch(" << i << ")=" << ehoch(i) << endl;
        cout << "exp(" << i << ")=" << exp(i) << endl;
    }
}

double ehoch(double x) {
    double sum = 0;
    int i = 0;
    while (true) {
        double add = pow(x, i) / facu(i);

        sum += add;
        i++;

        if (abs(add) < 1.0e-10) {
            break;
        }
    }

    return sum;
}

double pow(double x, double y) {
    if (y == 0) {
        return 1;
    }

    double sum = x;
    for (int i = 0; i < y - 1; i++) {
        sum *= x;
    }
    return sum;
}

double facu(int x) {
    if (x == 0 || x == 1) {
        return 1;
    }

    double res = 1;
    for (int i = x; i > 1; i--) {
        res *= i;
    }
    return res;
}