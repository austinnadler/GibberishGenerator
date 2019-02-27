// File: Person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Person {
private:
    static const int numHQL = 10;
    static const int numP = 6;
    static const int numT = 2;
    string first, last;
    int h[numHQL]; // 10 hw
    int l[numHQL]; // 10 labs
    int p[numP];  // 6 projects
    int t[numT];  // 2 tests
    int f;     // 1 final exam
public:
    Person () {
        first = "first";
    }

    Person(string& first, string& last, int h[], int l[], int p[], int t[], int& f) {
        this->first = first;
        this->last = last;
        for(int i = 0; i < numHQL; i++) {
            this->h[i] = h[i];
            this->l[i] = l[i];
        }
        for(int i = 0; i < 6; i++) {
            this->p[i] = p[i];
        }
        for(int i = 0; i < 2; i++) {
            this->t[i] = t[i];
        }
        this->f = f;
    }

    virtual string toStringLecture() const {
        ostringstream oss;
        oss << first << " " << last << " ";
        for(int i = 0; i < 10; i++) {
            oss << h[i] << " ";
        }
        for(int i = 0; i < 6; i++) {
            oss << p[i] << " ";
        }
        for(int i = 0; i < 2; i++) {
            oss << t[i] << " ";
        }
        oss  << f;
        return oss.str();
    }

    virtual string toStringLab() const {
        ostringstream oss;
        oss << first << " " << last << " ";
        for(int i = 0; i < 9; i++) {
            oss << l[i] << " ";
        }
        oss << l[9];
        return oss.str();
    }
};

ostream& operator <<(ostream& os, const Person& o);

#endif
