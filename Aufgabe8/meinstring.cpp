#include"meinstring.h"
#include<cassert>
#include<cstring>

// Der Default-Konstruktor erzeugt einen leeren String der L�nge 0,
//der nur aus dem Nullbyte besteht
MeinString::MeinString()
        : len(0), cap(0), start(new char[1]) {  // Platz f�r '\0'
    *start = '\0';                         // leerer String
}

// Der allgemeine Konstruktor erzeugt aus einem klassischen C-String ein
// MeinString-Objekt.

MeinString::MeinString(const char *s)      // allg. Konstruktor
        : len(strlen(s)), cap(len), start(new char[cap + 1]) {
    strcpy(start, s);
}

// Der Kopierkonstruktor arbeitet �hnlich, nur dass er die L�nge des
// Objekts, mit dem initialisiert wird, direkt �bernehmen kann:
MeinString::MeinString(const MeinString &m)     // Kopierkonstruktor
        : len(m.len), cap(len), start(new char[cap + 1]) {
    strcpy(start, m.start);
}

MeinString::~MeinString() {                // Destruktor
    delete[] start;
}

void MeinString::reserve(size_t groesse) {
    if (groesse > cap) {
        char *temp = new char[groesse + 1]; // neuen Platz beschaffen
        strcpy(temp, start);              // umkopieren
        delete[] start;                  // alten Platz freigeben
        start = temp;                     // Verwaltungsinformation aktualisieren
        cap = groesse;                    // Verwaltungsinformation aktualisieren
    }
}

void MeinString::reserve_only(size_t groesse) {
    if (groesse > cap) {
        char *temp = new char[groesse + 1]; // neuen Platz beschaffen
        delete[] start;                  // alten Platz freigeben
        start = temp;                     // Verwaltungsinformation aktualisieren
        cap = groesse;                    // Verwaltungsinformation aktualisieren
    }
}

void MeinString::shrink_to_fit() {
    if (cap > len) {
        char *temp = new char[len + 1];   // neuen Platz beschaffen
        strcpy(temp, start);            // umkopieren
        delete[] start;                // alten Platz freigeben
        start = temp;                   // Verwaltungsinformation aktualisieren
        cap = len;                      // Verwaltungsinformation aktualisieren
    }
}

MeinString &MeinString::assign(const MeinString &m) { // Zuweisung eines MeinString
    reserve_only(m.len);
    strcpy(start, m.start);
    len = m.len;
    return *this;
}

MeinString &MeinString::assign(const char *s) {  // Zuweisung eines char*
    size_t temp = strlen(s);
    reserve_only(temp);
    strcpy(start, s);
    len = temp;
    return *this;
}

char &MeinString::at(size_t position) {  // Zeichen per Referenz holen
    assert(position < len);               // Nullbyte lesen ist nicht erlaubt
    return start[position];
}

const char &MeinString::at(size_t position) const { // Zeichen holen
    assert(position < len);                           // Nullbyte lesen ist nicht erlaubt
    return start[position];
}

void MeinString::insert(size_t pos, const MeinString &m) {
    size_t temp = length();
    char *c = new char[temp + m.length()];
    for (unsigned int i = 0; i < temp + m.length(); i++) {
        if (i < pos) {
            c[i] = at(i);
        } else if (i >= pos && i < pos + m.length()) {
            c[i] = m.at(i - pos);
        } else if (i >= pos + m.length()) {
            c[i] = at(i - m.length());
        }
    }
    c[temp + m.length()] = '\0';
    len = temp + m.length();
    cap = temp + m.length();
    start = c;
}

void anzeigen(std::ostream &os, const MeinString &m) {
    os << m.c_str();
}

