#include<iostream>

using namespace std;

int main() {
    int input;
    cout << "input a number: ";
    cin >> input;
    string result;

    for (int i = 0; i < 32; i++) {
        int mod = input % 2;
        input = input >> 1;
        if (mod == 0) {
            result = "0" + result;
        } else {
            result = "1" + result;
        }
    }

    cout << "result: " + result;

    return 0;
}
