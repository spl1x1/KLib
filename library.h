#ifndef KLIB_LIBRARY_H
#define KLIB_LIBRARY_H
#include <string>
#include <fstream>
using namespace std;


enum Color { black, red, green, yellow, blue, magenta, cyan, white };

string dye(const string& Text, const Color color);

string dye_b(const string& Text, Color background);

int cin_int();

double cin_double();

char cin_char();

class logger {
    ofstream logfile;

public:
    logger(string filename);
    logger();
    int add(string toLog,bool logTime);
};

#endif //KLIB_LIBRARY_H
