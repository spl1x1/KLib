
#include "library.h"
#include <chrono>
#include <iostream>
using namespace std;

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


void heap::heap_node::increaseHeapArray() {
    const auto newHeapArray = new int[capacity*2];
    for (int i = 0; i < usedSize+1; i++) {
        newHeapArray[i] = heapArray[i];
    }
    delete[] heapArray;
        heapArray = newHeapArray;
    capacity*=2;
}

void heap::heap_node::insertElement(const int toInsert) {
    heapArray[usedSize]=toInsert;
    usedSize++;
    if(usedSize==capacity) {
        increaseHeapArray();
    }
}

int heap::heap_node::getElement(const int index) const {
    if(index>=0 && index<usedSize){
        return heapArray[index];}
    return NULL;
}

int heap::heap_node::getSize() const {return usedSize;}

int heap::heap_node::getParent(const int index) const {
    if(usedSize==0 || index <=0 || index>=usedSize) {
        cout << "Element has no parent" << endl;
        return -1;
    }
    return (index-1)/2;
}

int heap::heap_node::getLeftChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cout << "Element has no child" << endl;
        return -1;
    }
    return 2*index+1;
}

int heap::heap_node::getRightChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cout << "Element has no child" << endl;
        return -1;
    }
    return 2*index+2;
}

void heap::heap_node::swap(int indexA, int indexB) {
    if(indexA==indexB || indexA<0 || indexB<0 ||  indexA>=usedSize || indexB>=usedSize) {
        return;
    }
    const int temp=heapArray[indexA];
    heapArray[indexA]=heapArray[indexB];
    heapArray[indexB]=temp;
}


void heap::max::restoreHeapOrder(int indexOfLatest) {
    if(indexOfLatest==0){return;}
    const int indexOfParent = getParent(indexOfLatest);
    if (getElement(indexOfLatest)>getElement(indexOfParent)) {
        swap(indexOfLatest,indexOfParent);
        restoreHeapOrder(indexOfParent);
    }
}

void heap::min::restoreHeapOrder(int indexOfLatest) {
    if(indexOfLatest==0){return;}
    const int indexOfParent = getParent(indexOfLatest);
    if (getElement(indexOfLatest)<getElement(indexOfParent)) {
        swap(indexOfLatest,indexOfParent);
        restoreHeapOrder(indexOfParent);
    }
}

void heap::max::insert(const int toInsert) {
    insertElement(toInsert);
    restoreHeapOrder(getSize()-1);
}

void heap::min::insert(const int toInsert) {
    insertElement(toInsert);
    restoreHeapOrder(getSize()-1);
}

heap::heap_node::~heap_node() {
    delete[] heapArray;
}

template<typename T>
void queue<T>::increaseQueueArray() {
    const auto newQueueArray = new T[capacity*2];
    for (int i = 0; i < usedSize+1; i++) {
        newQueueArray[i] = queueArray[i];
    }
    delete[] queueArray;
    queueArray = newQueueArray;
    capacity*=2;
}

template<typename T>
queue<T>::~queue() {
    delete[] queueArray;
}

template<typename T>
int queue<T>::getSize() {
    return usedSize;
}

template<typename T>
void queue<T>::release() {
    if(usedSize==0){return;}
    usedSize--;
}

template<typename T>
void queue<T>::join(T toInsert) {
    queueArray[usedSize]=toInsert;
    usedSize++;
    if(usedSize==capacity) {
        increaseQueueArray();
    }
}

template<typename T>
T queue<T>::getElement(int index) {
    if(index>=0 && index<usedSize) {
        return queueArray[index];
    }
    return NULL;
}





