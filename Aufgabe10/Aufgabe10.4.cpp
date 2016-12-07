#include <iostream>

using namespace std;

int main() {
    auto l1 = [](double d1, double d2, double d3) -> double {
        return d1 + d2 + d3;
    };

    cout << "1+2+3=" << l1(1, 2, 3) << endl;

    int a = 5;
    int b = 10;
    int c = 7;

    auto l2 = [&](double d) -> bool {
        return a <= d && b >= d;
    };

    cout << "[5,10] = 7? " << l2(c) << endl;

    int z = 10;
    auto l3 = [&](){
        z = -z;
    };
    cout << z << " ";
    l3();
    cout << z << endl;
}