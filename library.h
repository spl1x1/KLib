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
int cin_int(Color errorColor);

double cin_double();
double cin_double(Color errorColor);

char cin_char();

//file logger
class logger {
    ofstream logfile;

public:
    logger();
    explicit logger(string filename);
    int add(string toLog,bool logTime);
};


//datastructures
class heap {
    class heap_node {
        int capacity = 10;
        int usedSize = 0;
        int *heapArray = new int[capacity];

    protected:
        void swap(int indexA, int indexB);
        void increaseHeapArray();
        void insertElement(int toInsert);

    public:
        [[nodiscard]] int getSize() const;
        [[nodiscard]] int getElement(int index) const;
        [[nodiscard]] int getParent (int index) const;
        [[nodiscard]] int getLeftChild(int index) const;
        [[nodiscard]] int getRightChild(int index) const;
        ~heap_node();
    };

    public:
    class min : public heap_node{
        void restoreHeapOrder(int indexOfLatest);
    public:
        void insert(int toInsert);
    };

    class max : public heap_node {
        void restoreHeapOrder(int indexOfLatest);
    public:
        void insert(int toInsert);
    };
};

template <typename T>class queue {
    int capacity = 10;
    int usedSize = 0;
    T *queueArray = new T[capacity];
    void increaseQueueArray();
public:
    ~queue();
    void join(T toInsert);
    void release();
    int getSize();
    T getElement(int index);\
};

#endif //KLIB_LIBRARY_H
