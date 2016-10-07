#include<iostream>
#include <fstream>

using namespace std;

int main() {
    string name;
    cout << "enter name: ";
    cin >> name;

    ifstream file;
    string line;
    file.open(name);
    string content = "";
    while (getline(file, line)) {
        //cout << "read line: " << line << endl;
        content += line;
    }

    line = "";
    for (unsigned int i = 0; i < content.length(); i++) {
        char c = content.at(i);
        line += c;
        cout << hex << (int) c << " ";
        if (i % 16 == 0 && i != 0) {
            cout << "   " << line << endl;
            line = "";
        }
    }

    // print out rest
    if(line != ""){
        cout << "   " << line << endl;
    }

    return 0;
}