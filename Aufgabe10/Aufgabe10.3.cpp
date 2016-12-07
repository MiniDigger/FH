#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m1;
condition_variable cv1;

mutex m2;
condition_variable cv2;

mutex m3;
condition_variable cv3;

void r1() {
    unique_lock<mutex> ul(m1);
    cv1.wait(ul);
    cout << "t1 got signal from main" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cv2.notify_one();
    cout << "t1 send signal to t2" << endl;
}

void r2() {
    unique_lock<mutex> ul(m2);
    cv2.wait(ul);
    cout << "t2 got signal from t1" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cv3.notify_one();
    cout << "t2 send signal to t3" << endl;
}

void r3() {
    unique_lock<mutex> ul(m3);
    cv3.wait(ul);
    cout << "t3 got signal from t2" << endl;
}

int main() {
    thread t1(r1);
    thread t2(r2);
    thread t3(r3);

    cout << "main start" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cv1.notify_one();
    cout << "main send signal to t1" << endl;

    t1.join();
    t2.join();
    t3.join();
}