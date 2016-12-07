#include <thread>
#include <iostream>

using namespace std;

void run(int id) {
    cout << "Thread " << id << " startet" << endl;
    this_thread::sleep_for(chrono::milliseconds(id * 1000));
    cout << "Thread " << id << " stopt" << endl;
}

int main() {
    thread t1(run, 1);
    thread t2(run, 2);
    thread t3(run, 3);
    t1.join();
    t2.join();
    t3.join();
}