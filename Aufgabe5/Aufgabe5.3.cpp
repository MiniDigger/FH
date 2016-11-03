#include <iostream>

template<typename T>
struct Element {
    T value;
    Element<T> *next;

    Element<T>(T v, Element<T> *n)
            : value(v), next(n) {}
};

template<typename T>
void insert(Element<T> *&rp, T v, bool (*func)(T, T)) {
    if (rp != NULL) {
        if (func(v, rp->value)) // Sortieren
            insert(rp->next, v, func); // Rekursion
        else rp = new Element<T>(v, rp);
    } else rp = new Element<T>(v, NULL);
}

template<typename T>
void insert(Element<T> *&rp, T v) {
    if (rp != NULL) {
        if (v > rp->value) // Sortieren
            insert(rp->next, v); // Rekursion
        else rp = new Element<T>(v, rp);
    } else rp = new Element<T>(v, NULL);
}

template<typename T>
void remove(Element<T> *&rp, T v) {
    if (rp != NULL) {
        if (rp->value == v) {
            Element<T> *tmp = rp;
            rp = rp->next;
            delete tmp;
            remove(rp, v);
        } else remove(rp->next, v);// Rekursion
    }
}

template<typename T>
void print(Element<T> *p) {
    while (p) {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

bool sort(int a, int b) {
    return a < b;
}

int main() {
    Element<double> *head = NULL;
    insert(head, 2.5);
    insert(head, 5.5);
    insert(head, 1.5);
    print(head);
    remove(head, 2.5);
    print(head);

    Element<int> *head2 = NULL;
    insert(head2, 2, sort);
    insert(head2, 5, sort);
    insert(head2, 1, sort);
    print(head2);
    remove(head2, 2);
    print(head2);
}