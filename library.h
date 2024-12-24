#ifndef KLIB_LIBRARY_H
#define KLIB_LIBRARY_H

#include <string>
#include <fstream>
using namespace std;


enum Color { black, red, green, yellow, blue, magenta, cyan, white };

string dye(const string& Text, Color color);

string dye_b(const string& Text, Color background);

int cin_int();
int cin_int(Color errorColor);

double cin_double();
double cin_double(Color errorColor);

char cin_char();

class logger {
    ofstream logfile;

public:
    logger();
    explicit logger(string filename);
    int add(string toLog,bool logTime);
};

class heap {
    int capacity = 10;
    int usedSize = 0;
    int *heapArray = new int[capacity];
    void increaseHeapArray();
    void insertElement(int toInsert);

    public:
    [[nodiscard]] int getSize() const;
    [[nodiscard]] int getElement(int index) const;
    [[nodiscard]] int getParent (int index) const;
    [[nodiscard]] int getLeftChild(int index) const;
    [[nodiscard]] int getRightChild(int index) const;
};

class minHeap : public heap {
    void restoreHeapOrder();
    public:
    void insert(int toInsert);
};

class maxHeap : public heap {
    void restoreHeapOrder();
    public:
    void insert(int toInsert);
};

class queue {

    public:
};

#endif //KLIB_LIBRARY_H
