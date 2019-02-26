// File: main.cpp
#include <random>
#include <string>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

string random_string(string::size_type length);
string random_stringofint(string::size_type length);
bool codeAv(string& code);
bool openFileOut(ofstream& ofs, const string& fileName);


vector<string> codes; // codes must be unique

int main() {
    const string filename = "items.csv";
    string name, price, numOnHand, code, warning, age;
    ostringstream oss;
    ofstream ofs;
    const int BOUND = 500;
    int length;
    bool validCode = false;
    bool validAge = false;
    bool validNumOnHand = false;
    bool validPrice = false;
    for(int i = 0; i < BOUND; i++) {
        length = 5 + (rand() % ( 20 - 5 + 1 ) );
        name = random_string(length);
        length = rand() % 4 + 1;
        price = random_stringofint(length);
        length = rand() % 4 + 1;
        numOnHand = random_stringofint(length);
        do {
            code = random_stringofint(5);
            validCode = codeAv(code);
        } while(!validCode);
        if(validCode) {
            codes.push_back(code);
        }
        oss << "gm," << name << "," << price << "," << numOnHand << "," << code << endl;
    }
    
    for(int i = 0; i < BOUND; i++) {
        validAge = false;

        length = 5 + (rand() % ( 20 - 5 + 1 ) );
        name = random_string(length);

        length = rand() % 4 + 1;
        do {
            try {
                price = random_stringofint(length);
                if(stoi(price) > 0) {
                    validPrice = true;
                }
            } catch(invalid_argument e) {
                validPrice = false;
            }
            
        } while(!validPrice);
        
        length = rand() % 4 + 1;
        numOnHand = random_stringofint(length);

        length = rand() % 21 + 5;
        warning = random_string(length);

        length = rand() % 2 + 1;
        age = random_stringofint(length);
        do {
            code = random_stringofint(5);
            validCode = codeAv(code);
        } while(!validCode);
        if(validCode) {
            codes.push_back(code);
        }
        oss << "ar," << age << "," << name << "," << price << "," << numOnHand << "," << code << endl;
    }

    for(int i = 0; i < BOUND; i++) {
        validAge = false;

        length = 5 + (rand() % ( 20 - 5 + 1 ) );
        name = random_string(length);

        length = rand() % 4 + 1;
        do {
            try {
                price = random_stringofint(length);
                if(stoi(price) > 0) {
                    validPrice = true;
                }
            } catch(invalid_argument e) {
                validPrice = false;
            }
            
        } while(!validPrice);
        
        length = rand() % 4 + 1;
        numOnHand = random_stringofint(length);

        length = rand() % 21 + 5;
        warning = random_string(length);

        length = rand() % 20 + 1;
        warning = random_string(length);
        do {
            code = random_stringofint(5);
            validCode = codeAv(code);
        } while(!validCode);
        if(validCode) {
            codes.push_back(code);
        }
        oss << "warn," << warning << "," << name << "," << price << "," << numOnHand << "," << code << endl;
    }    
    bool fileStatus = openFileOut(ofs, filename);
    ofs << oss.str();
    return 0;
}// end main()

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
        "123456789";

    thread_local static mt19937 rg{random_device{}()};
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

bool codeAv(string& code) {
    if(codes.size() == 0) {
        return true;
    } else {
        for(int i = 0; i < codes.size(); i++) {
            if(code == codes.at(i)) {
                return false;
            }
        }
        return true;
    }
}

bool openFileOut(ofstream& ofs, const string& fileName){
    ofs.open(fileName);
    return ofs.is_open();
}// end openFileOut()