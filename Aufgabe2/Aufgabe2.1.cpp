#include<iostream>
#include <cmath>

using namespace std;

int main() {
    string input;
    cout << "enter a number: " << endl;
    cin >> input;

    long result = 0;
    for (unsigned int i = 0; i < input.length(); i++) {
        long charVal = input.at(i) - 48;
        //cout << "charVal " << charVal << endl;
        unsigned long exp = input.length() - i - 1;
        //cout << "exp " << exp << endl;
        double powVal = pow(10, exp);
        //cout << "pow " << powVal << endl;
        result += charVal * powVal;
    }

    cout << "result " << result;

    return 0;
}