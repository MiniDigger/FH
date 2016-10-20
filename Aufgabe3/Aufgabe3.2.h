#include <string>

template<typename T>
std::string getType(T t) {
    return "unknown type!";
}

template<>
std::string getType(bool b) {
    return "bool";
}

template<>
std::string getType(int b) {
    return "int";
}

template<>
std::string getType(unsigned int ui) {
    return "unsigned int";
}

template<>
std::string getType(char c) {
    return "char";
}