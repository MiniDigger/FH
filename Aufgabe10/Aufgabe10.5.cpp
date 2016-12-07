#include <iostream>
#include <functional>

using namespace std;

double eval(function<double(double)> f, double x) {
    return f(x);
}

int main() {
    cout << "f(x)=x " << eval([](double x) -> double { return x; }, 10) << endl;
    cout << "f(x)=x*x " << eval([](double x) -> double { return x * x; }, 10) << endl;
}