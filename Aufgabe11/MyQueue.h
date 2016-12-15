//
// Created by student on 15.12.16.
//

#ifndef FH_MYQUEUE_H
#define FH_MYQUEUE_H

#include <initializer_list>
#include <list>
#include <ostream>

using namespace std;

template<class T>
class MyQueue {

    typedef _List_iterator<T> iterator;
    typedef const _List_const_iterator<T> const_iterator;

public:
    MyQueue(initializer_list<T> init) {
        list = init;
    };

    MyQueue(MyQueue &&queue) {
        cout << "move-ctr" << endl;
        swap(list, queue.list);
    }

    MyQueue &operator=(MyQueue &&queue) {
        cout << "move-call" << endl;
        swap(list, queue.list);
        return *this;
    }

    iterator begin() {
        return list.begin();
    }

    const_iterator begin() const {
        return list.begin();
    }

    iterator end() {
        return list.end();
    }

    const_iterator end() const {
        return list.end();
    }

    void push_back(T i) {
        list.push_back(i);
    }

    void pop_front() {
        list.pop_front();
    }

    int size() {
        return list.size();
    }

    bool empty() {
        return list.empty();
    }

private:
    list<T> list;
};

template<typename S>
ostream &operator<<(ostream &stream, const MyQueue<S> &queue) {
    stream << "{";
    for (auto x : queue) {
        stream << x << " ";
    }
    stream << "}";
    return stream;
}

#endif //FH_MYQUEUE_H
