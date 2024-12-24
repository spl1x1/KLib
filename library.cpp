
#include "library.h"
#include <chrono>
#include <iostream>
using namespace std;

//xcolor
string dye(const string& Text, const Color color) {
    string c;
    switch (color) {
        case black: c = "[30m"; break;
        case red: c = "[31m"; break;
        case green: c = "[32m"; break;
        case yellow: c = "[33m"; break;
        case blue: c = "[34m"; break;
        case magenta: c = "[35m"; break;
        case cyan: c = "[36m"; break;
        case white: c = "[37m"; break;
    }
    return "\x1b" +c+Text+ "\x1b[0m";
}


string dye_b(const string& Text, const Color background) {
    string c;
    switch (background) {
        case black: c = "[40m"; break;
        case red: c = "[41m"; break;
        case green: c = "[42m"; break;
        case yellow: c = "[43m"; break;
        case blue: c = "[44m"; break;
        case magenta: c = "[45m"; break;
        case cyan: c = "[46m"; break;
        case white: c = "[47m"; break;
    }
    return "\x1b" +c+Text+ "\x1b[0m";
}

int cin_int() {
    string hodnota;
    while (true) {
        cin >> hodnota;
        try {return stoi(hodnota,nullptr,10);}
        catch(...) {cout << "Neplatna hodnota" << endl;}
    }
}

int cin_int(Color errorColor) {
    string hodnota;
    while (true) {
        cin >> hodnota;
        try {return stoi(hodnota,nullptr,10);}
        catch(...) {cout << dye("Neplatna hodnota",errorColor) << endl;}
    }
}

double cin_double() {
    string hodnota;
    while (true) {
        cin >> hodnota;
        try {return stod(hodnota,nullptr);}
        catch(...) {cout << "Neplatna hodnota" << endl;}
    }
}

double cin_double(Color errorColor) {
    string hodnota;
    while (true) {
        cin >> hodnota;
        try {return stod(hodnota,nullptr);}
        catch(...) {cout << dye("Neplatna hodnota",errorColor) << endl;}
    }
}

char cin_char() {
    string hodnota;
    cin >> hodnota;
    return hodnota[0];
}


//logger
using namespace std;
logger::logger(string filename) {
    filename.append(".log");

    try {
        logfile.open(filename,ios::app);
    } catch (...) {
        cout << "Error opening file " << filename << endl;
    }
}

logger::logger() {
    try {
        logfile.open("logger.log", ios::app);
    } catch (...) {
        cout << "Error opening file logger.log" << endl;
    }
}


void heap::increaseHeapArray() {
    const auto newHeapArray = new int[capacity*2];
    for (int i = 0; i < usedSize+1; i++) {
        newHeapArray[i] = heapArray[i];
    }
    delete[] heapArray;
        heapArray = newHeapArray;
    capacity*=2;
}

void heap::insertElement(const int toInsert) {
    heapArray[usedSize]=toInsert;
    usedSize++;
    if(usedSize==capacity) {
        heap::increaseHeapArray();
    }
}

int heap::getElement(const int index) const {
    if(index>=0 && index<usedSize){
        return heapArray[index];}
    return NULL;
}

int heap::getSize() const {return usedSize;}

int heap::getParent(const int index) const {
    if(usedSize==0 || index <=0 || index>=usedSize) {
        cout << "Element has no parent" << endl;
        return -1;
    }
    return (index-1)/2;
}

int heap::getLeftChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cout << "Element has no child" << endl;
        return -1;
    }
    return 2*index+1;
}

int heap::getRightChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cout << "Element has no child" << endl;
        return -1;
    }
    return 2*index+2;
}
