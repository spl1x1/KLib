
#include "library.h"
#include <iostream>
#include <chrono>
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


string dye_b(const string& Text, Color background) {
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
        catch(...) {cout << dye("Neplatna hodnota",red) << endl;}
    }
}

double cin_double() {
    string hodnota;
    while (true) {
        cin >> hodnota;
        try {return stod(hodnota,nullptr);}
        catch(...) {cout << dye("Neplatna hodnota",red) << endl;}
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