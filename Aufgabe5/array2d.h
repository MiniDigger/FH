#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <cassert>
#include <iostream>

template<typename T>
class Array2d {
public:
    Array2d(size_t z, size_t s)
            : zeilen{z}, spalten{s}, ptr{new T[z * s]} {}

    Array2d(size_t z, size_t s, const T &wert)
            : Array2d(z, s) { // an obigen Konstruktor delegieren
        init(wert);
    }

    template<size_t Z, size_t S>
    Array2d(const T (&a)[Z][S]) : Array2d(Z, S) {
        for (unsigned int z = 0; z < Z; z++) {
            for (unsigned int s = 0; s < S; s++) {
                this->at(z, s) = a[z][s];
            }
        }
    }

    Array2d(const Array2d &a)
            : Array2d(a.zeilen,
                      a.spalten) { // an obigen Konstruktor delegieren
        size_t anzahl = zeilen * spalten;
        for (size_t i = 0; i < anzahl; ++i) {
            ptr[i] = a.ptr[i];
        }
    }

    ~Array2d() { delete[] ptr; }

    Array2d &operator=(const Array2d &arr) = delete; // (noch) verbieten

    Array2d &assign(Array2d tmp) {
        swap(tmp);
        return *this;
    }

    size_t getZeilen() const { return zeilen; }

    size_t getSpalten() const { return spalten; }

    void init(const T &wert) { // Alle Elemente mit wert initialisieren
        size_t anzahl = zeilen * spalten;
        for (size_t i = 0; i < anzahl; ++i) {
            ptr[i] = wert;
        }
    }

    const T &at(size_t z, size_t s) const {
        assert(z < zeilen && s < spalten);
        return ptr[z * spalten + s];
    }

    T &at(size_t z, size_t s) {
        assert(z < zeilen && s < spalten);
        return ptr[z * spalten + s];
    }

    void swap(Array2d &rhs) {
        size_t temp = zeilen;
        zeilen = rhs.zeilen;
        rhs.zeilen = temp;
        temp = spalten;
        spalten = rhs.spalten;
        rhs.spalten = temp;
        T *tempPtr = ptr;
        ptr = rhs.ptr;
        rhs.ptr = tempPtr;
    }

private:
    size_t zeilen;
    size_t spalten;
    T *ptr;
};

// Globale Funktion zur Ausgabe
template<typename T>
void printArray(const Array2d<T> &a) {
    for (size_t z = 0; z < a.getZeilen(); ++z) {
        for (size_t s = 0; s < a.getSpalten(); ++s) {
            std::cout << a.at(z, s) << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Array2d<T> mmult(const Array2d<T> &a, const Array2d<T> &b) {
    assert(a.getSpalten() == b.getZeilen());

    Array2d<T> result = Array2d<T>(a.getZeilen(), b.getSpalten());

    for (unsigned int i = 0; i < a.getZeilen(); i++) {
        for (unsigned int k = 0; k < b.getSpalten(); k++) {
            int sum = 0;
            for (unsigned int j = 0; j < a.getSpalten(); j++) {
                sum += a.at(i, j) * b.at(j, k);
            }
            result.at(i, k) = sum;
        }
    }

    return result;
}

#endif
