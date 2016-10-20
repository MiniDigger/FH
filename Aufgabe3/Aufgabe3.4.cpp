#include <iostream>

using namespace std;

int leseAusdruck();

int leseSummand();

int leseFaktor();

int INVALID_READ = ((unsigned) ~0) >> 1;

int main() {
    int res = leseAusdruck();
    cout << "result " << res;
}

int leseAusdruck() {
    char c;
    int lhs = leseSummand();
    if (lhs != INVALID_READ) {
        // überlese leerzeichen
        cin >> c;
        while (c == ' ') {
            cin >> c;
        }

        while (c == '+' || c == '-') {
            int rhs = leseSummand();
            if (rhs != INVALID_READ) {
                if (c == '+') {
                    cout << "lhs " << lhs << "rhs " << rhs << endl;
                    lhs += rhs;
                } else if (c == '-') {
                    lhs -= rhs;
                }
            }

            //überlese leerzeichen
            cin >> c;
            while (c == ' ') {
                cin >> c;
            }
        }
    }

    return lhs;
}

int leseSummand() {
    char c;
    int lhs = leseFaktor();
    if (lhs != INVALID_READ) {
        // überlese leerzeichen
        cin >> c;
        while (c == ' ') {
            cin >> c;
        }

        while (c == '*' || c == '/') {
            int rhs = leseFaktor();
            if (rhs != INVALID_READ) {
                if (c == '*') {
                    lhs *= rhs;
                } else if (c == '/') {
                    lhs /= rhs;
                }
            }

            //überlese leerzeichen
            cin >> c;
            while (c == ' ') {
                cin >> c;
            }
        }
    }

    return lhs;
}

int leseFaktor() {
    char c;
    int result = INVALID_READ;

    //überlese leerzeichen
    cin >> c;
    while (c == ' ') {
        cin >> c;
    }

    if (c == '-' || c == '+') {
        result = leseFaktor();
        if (result != INVALID_READ) {
            if (c == '-') {
                result *= -1;
            }
        }
    } else {
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' ||
            c == '9') {
            // TODO lese zahl ein
            result = 1;
        } else {
            if (c == '(') {
                result = leseAusdruck();
                if (result != INVALID_READ) {
                    //überlese leerzeichen
                    cin >> c;
                    while (c == ' ') {
                        cin >> c;
                    }
                }
            }
        }
    }

    return result;
}