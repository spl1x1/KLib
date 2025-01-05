#ifndef KLIB_LIBRARY_H
#define KLIB_LIBRARY_H

#include <string>
#include <fstream>
using namespace std;

//console output styling
enum Color { black, red, green, yellow, blue, magenta, cyan, white };
static string dye(const string& Text, Color color);
static string dye_b(const string& Text, Color background);


//data input with check
int cin_int();

double cin_double();

char cin_char();

//file logger
class logger {
    ofstream logfile;

public:
    logger();
    explicit logger(string filename);
    void add(const string& toLog,bool logTime);
};


//datastructures
template <typename T>class heap {
    class heap_node {
        int capacity = 10;
        int usedSize = 0;
        T *heapArray = new T[capacity];
    protected:
        void swap(int indexA, int indexB) const;
        void increaseHeapArray();
        void insertElement(T toInsert);
        void deleteElement(int index);
    public:
        [[nodiscard]] int getSize() const;
        [[nodiscard]] T getElement(int index) const;
        [[nodiscard]] int getParent (int index) const;
        [[nodiscard]] int getLeftChild(int index) const;
        [[nodiscard]] int getRightChild(int index) const;
        ~heap_node();
    };

    public:
    class min : public heap_node {
        void restoreHeapOrder(int indexOfLatest);
        void heapify(int index);
    public:
        void insert(T toInsert);
        void remove(int toRemoveIndex);
    };

    class max : public heap_node {
        void restoreHeapOrder(int indexOfLatest);
        void heapify(int index);
    public:
        void insert(T toInsert);
        void remove(int toRemoveIndex);
    };
};

template <typename T>class queue_s {
    int capacity = 10;
    int usedSize = 0;
    int offset = 0;
    T *queueArray = new T[capacity];
    void increaseQueueArray();
    void removeOffset();
public:
    ~queue_s();
    void join(T toInsert);
    void release();
    [[nodiscard]] int getSize() const;
    T getElement(int index);\
};

#include "library.cpp"
#endif //KLIB_LIBRARY_H
