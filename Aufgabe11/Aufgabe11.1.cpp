//
// Created by student on 15.12.16.
//

#include <iostream>
#include <string>
#include "MyQueue.h"

using namespace std;

int main() {
    MyQueue<int> queue = {1, 5, 63, 23, 1};
    cout << queue << endl;
    queue.push_back(224);
    cout << queue << endl;
    queue.pop_front();
    cout << queue << endl;
    cout << "size: " << queue.size() << endl;
    cout << "empty: " << queue.empty() << endl;
    while (!queue.empty()) {
        queue.pop_front();
    }
    cout << "size: " << queue.size() << endl;
    cout << "empty: " << queue.empty() << endl;

    MyQueue<int> queue1 = {2, 3, 4};
    MyQueue<int> queue2 = {34, 35, 34};
    MyQueue<int> queue3(move(queue1));
    cout << queue3 << endl;
    queue2 = move(queue3);
    cout << queue2 << endl;

    for (auto x : queue2) {
        cout << x << " ";
    }
    cout << endl;

    MyQueue<string> queue4 = {"wd", "dwd", "wfawff", "awfawf"};
    for (auto x : queue4) {
        cout << x << " ";
    }
}