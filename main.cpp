// File: main.cpp
#include <random>
#include <string>
#include <string>
#include <iostream>
using namespace std;
string random_string(string::size_type length);
string random_stringofint(string::size_type length);
int main() {

    string genStr = random_string(16);
    cout << genStr << endl;

    string genInt = random_stringofint(2);
    cout << genInt << endl;

    return 0;
}// end main()
using namespace std;
string random_string(string::size_type length) {
    static auto& chrs =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static mt19937 rg{random_device{}()};
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

string random_stringofint(string::size_type length) {
    static auto& chrs =
        "1234567890";

    thread_local static mt19937 rg{random_device{}()};
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

