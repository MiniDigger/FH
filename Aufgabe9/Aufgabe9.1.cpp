#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    typedef map<string, size_t>::iterator MapIterator;

    stringstream ss("");
    vector<MapIterator> vec;
    map<string, size_t> map;

    ifstream is("/home/student/ClionProjects/FH-github/Aufgabe9/test.txt", ifstream::in);
    if (!is) {
        cout << "could not open file!" << endl;
        exit(-1);
    };

    char c;
    bool started = false;
    while (is.get(c)) {
        if (!started && isalpha(c)) {
            started = true;
            ss << c;
        } else if (started && (isalnum(c) || c == '_')) {
            ss << c;
        } else {
            string s = ss.str();
            ss.str("");

            if (map.count(s) == 0) {
                map.insert(make_pair(s, 1));
                vec.push_back(map.find(s));
            } else {
                map.at(s)++;
            }

            started = false;
        }
    }

    string s = ss.str();
    ss.str("");

    if (map.count(s) == 0) {
        vec.push_back(map.find(s));
        map.insert(make_pair(s, 1));
    } else {
        map.at(s)++;
    }

    cout << "values: " << endl;
    for (auto val : map) {
        cout << val.first << " count: " << val.second << endl;
    }

    sort(vec.begin(), vec.end(), [](const MapIterator it1, const MapIterator it2) -> bool {
        return it1->second > it2->second;
    });

    cout << "sorted: " << endl;
    for (unsigned int i = 0; i < min(20U, vec.size()); i++) {
        auto val = vec.at(i);
        cout << val->first << " count: " << val->second << endl;
    }
}