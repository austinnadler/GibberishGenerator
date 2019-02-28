// File: main.cpp
#include <random>
#include <string>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "person.h";
using namespace std;

string random_string(string::size_type length);
bool openFileOut(ofstream& ofs, const string& fileName);


vector<string> codes; // codes must be unique

int main() {
    string filename = "data.txt";
    ofstream ofs;
    string first;
    string last;
    // Decided everyone gets at least 60% on everything to make grades seem more realistic looking
    int minGrade = 6;
    int filler = 10 - minGrade;
    int h[10]; // 10 hw
    int q[10]; // 10 quizzes
    int l[10]; // 10 labs
    int p[6];  // 6 projects
    int t[2];  // 2 tests
    int f;     // 1 final exam
    int cnt = 0;
    bool fileOpen = openFileOut(ofs, filename);
    Person people[60];

    if(!fileOpen) {
        cerr << "Error creating file: " << filename << endl;
        exit(1);
    }
    srand(time(0));
    do {
        first = random_string(5);
        last = random_string(5);
        for(int i = 0; i < 10; i++ ) {
            h[i] = rand() % filler + minGrade;
        }
        for(int i = 0; i < 10; i++ ) {
            l[i] = rand() % filler + minGrade;
        }
        for(int i = 0; i < 6; i++ ) {     
            // 50 - 100
            int grade = (rand() % filler * 10 + minGrade * 10) + (rand() % 9 + 1);
            p[i] = grade;
        }
        for(int i = 0; i < 2; i++ ) {
            t[i] = (rand() % filler * 10 + minGrade * 10) + (rand() % 9 + 1);
        } 
        f = (rand() % filler * 10 + minGrade * 10) + (rand() % 9 + 1);

        people[cnt++] = Person(first, last, h, l, p, t, f);
    } while(cnt < 60);

    for(int i = 0; i < 60; i++) {
        ofs << people[i].toStringLecture() << endl;
    }

    ofs << endl;
    ofs << endl;

    for(int i = 0; i < 60; i++) {
        ofs << people[i].toStringLab() << endl;
    }
    
}// end main()

string random_string(string::size_type length) {
    static auto& chrs =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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