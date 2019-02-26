// File: main.cpp
#include <random>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string random_string(string::size_type length);
string random_stringofint(string::size_type length);
bool openFileOut(ofstream& ofs, const string& fileName);

int main() {
    string input;
    bool it = false;
    int tries = 0;
    ofstream ofs;
    cout << "1-3 letters: instant" << endl
         << "4 letters:   about 1-8 seconds" << endl
         << "5 letters:   about 30 seconds - 1 minute" << endl
         << "6+ letters:   over 2 minutes"
         << "Enter the word / name in lowercase: ";
    getline(cin, input);
    openFileOut(ofs, "guesses.txt");
    do {
        string randomString = random_string(input.length());
        ofs << randomString << endl;
        tries++;
        if(randomString == input) {
            cout << "Guess #" << tries << ": " << randomString << endl;
            it = true;
        } 
        if(tries % 10000 == 0) {
            cout << "Guess #" << tries << ": " << randomString << endl;
        }
    } while(!it);
    cout << "Guess #" << tries << " was correct." << endl;
    ofs.close();

}// end main()


string random_string(string::size_type length) {
    static auto& chrs =
        "abcdefghijklmnopqrstuvwxyz";

    thread_local static mt19937 rg{random_device{}()};
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}//end random_string()

string random_stringofint(string::size_type length) {
    static auto& chrs =
        "123456789";

    thread_local static mt19937 rg{random_device{}()};
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}//end random_stringofint()

bool openFileOut(ofstream& ofs, const string& fileName){
    ofs.open(fileName);
    return ofs.is_open();
}// end openFileOut()