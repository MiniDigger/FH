#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

int sum = 0;
mutex sum_mutex;

void run(int i) {
    lock_guard<mutex> lg(sum_mutex);
    cout << "calc " << sum << " + " << i;
    sum += i;
    cout << " = " << sum << endl;
}

int main() {
    unsigned int N;
    cout << "N: ";
    cin >> N;

    vector<thread> threads;
    for (unsigned int i = 1; i <= N; i++) {
        threads.push_back(thread(run, i));
    }

    for (unsigned int i = 0; i < N; i++) {
        threads.at(i).join();
    }

    cout << "result " << sum;
}