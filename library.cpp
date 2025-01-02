
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
    string value;
        cin >> value;
        try {return stoi(value,nullptr,10);}
        catch(...) {cerr << "Not a valid value" << endl;}
        return NULL;
}

double cin_double() {
    string value;
    cin >> value;
    try {return stod(value,nullptr);}
    catch(...) {cerr << "Not a valid value" << endl;}
    return NULL;
}

char cin_char() {
    string value;
    cin >> value;
    return value[0];
}

//logger
using namespace std;
logger::logger(string filename) {
    filename.append(".log");

    try {
        logfile.open(filename,ios::app);
    } catch (...) {
        cerr << "Error opening file " << filename << endl;
    }
}

logger::logger() {
    try {
        logfile.open("logger.log", ios::app);
    } catch (...) {
        cerr << "Error opening file logger.log" << endl;
    }
}

template<typename T>
void heap<T>::heap_node::increaseHeapArray() {
    const auto newHeapArray = new T[capacity*2];
    for (int i = 0; i < usedSize+1; i++) {
        newHeapArray[i] = heapArray[i];
    }
    delete[] heapArray;
        heapArray = newHeapArray;
    capacity*=2;
}

template<typename T>
void heap<T>::heap_node::insertElement(const T toInsert) {
    heapArray[usedSize]=toInsert;
    usedSize++;
    if(usedSize==capacity) {
        increaseHeapArray();
    }
}

template<typename T>
T heap<T>::heap_node::getElement(const int index) const {
    if(index>=0 && index<usedSize){
        return heapArray[index];}
    return NULL;
}

template<typename T>
int heap<T>::heap_node::getSize() const {return usedSize;}

template<typename T>
int heap<T>::heap_node::getParent(const int index) const {
    if(usedSize==0 || index <=0 || index>=usedSize) {
        cerr << "Element has no parent" << endl;
        return -1;
    }
    return (index-1)/2;
}

template<typename T>
int heap<T>::heap_node::getLeftChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cerr << "Element has no child" << endl;
        return -1;
    }
    return 2*index+1;
}

template<typename T>
int heap<T>::heap_node::getRightChild(const int index) const {
    if(usedSize==0 || index <0 || index>=usedSize) {
        cerr << "Element has no child" << endl;
        return -1;
    }
    return 2*index+2;
}

template<typename T>
void heap<T>::heap_node::swap(const int indexA, const int indexB) const {
    if(indexA==indexB || indexA<0 || indexB<0 ||  indexA>=usedSize || indexB>=usedSize) {
        return;
    }
    const T temp=heapArray[indexA];
    heapArray[indexA]=heapArray[indexB];
    heapArray[indexB]=temp;
}

template<typename T>
void heap<T>::max::restoreHeapOrder(int indexOfLatest) {
    if(indexOfLatest==0){return;}
    const int indexOfParent = this->getParent(indexOfLatest);
    const T currentValue = this->getElement(indexOfLatest);
    const T valueOfParent = this->getElement(indexOfParent);
    if (currentValue>valueOfParent) {
        this->swap(indexOfLatest,indexOfParent);
        restoreHeapOrder(indexOfParent);
    }
}

template<typename T>
void heap<T>::min::restoreHeapOrder(int indexOfLatest) {
    if(indexOfLatest==0){return;}
    const int indexOfParent = this->getParent(indexOfLatest);
    const T currentValue = this->getElement(indexOfLatest);
    const T valueOfParent = this->getElement(indexOfParent);
    if (currentValue<valueOfParent) {
        this->swap(indexOfLatest,indexOfParent);
        restoreHeapOrder(indexOfParent);
    }
}

template<typename T>
void heap<T>::max::insert(const T toInsert) {
    this->insertElement(toInsert);
    restoreHeapOrder(this->getSize()-1);
}

template<typename T>
void heap<T>::min::insert(const T toInsert) {
    this->insertElement(toInsert);
    restoreHeapOrder(this->getSize()-1);
}

template<typename T>
heap<T>::heap_node::~heap_node() {
    delete[] heapArray;
}

template<typename T>
void heap<T>::heap_node::deleteElement(int index) {
        heapArray[index]=heapArray[usedSize-1];
        usedSize--;
}

template<typename T>
void heap<T>::max::heapify(const int index) {
    int greaterChild = this->getLeftChild(index);
    const int indexOfRightChild = this->getRightChild(index);
    T valueOfGreaterChild = this->getElement(greaterChild);
    const T rightChildValue = this->getElement(indexOfRightChild);


    if (rightChildValue>valueOfGreaterChild) {
        valueOfGreaterChild = rightChildValue;
        greaterChild = indexOfRightChild;
    }
    if (valueOfGreaterChild>this->getElement(index)){
        this->swap(index,greaterChild);
        heapify(greaterChild);
    }
}

template<typename T>
void heap<T>::min::heapify(const int index) {
    int lesserChild = this->getLeftChild(index);
    const int indexOfRightChild = this->getRightChild(index);
    T valueOfLesserChild = this->getElement(lesserChild);
    const T rightChildValue = this->getElement(indexOfRightChild);


    if (rightChildValue<valueOfLesserChild) {
        valueOfLesserChild = rightChildValue;
        lesserChild = indexOfRightChild;
    }
    if (valueOfLesserChild<this->getElement(index)){
        this->swap(index,lesserChild);
        heapify(lesserChild);
    }
}

template<typename T>
void heap<T>::max::remove(const int toRemoveIndex) {
    const int indexOfLast = this->getSize()-1;
    if(toRemoveIndex<0 || toRemoveIndex>=indexOfLast) {
        cerr << "Index out of bounds" << endl;
        return;
    }
    this->deleteElement(toRemoveIndex);
    heapify(toRemoveIndex);
}

template<typename T>
void heap<T>::min::remove(const int toRemoveIndex) {
    const int indexOfLast = this->getSize()-1;
    if(toRemoveIndex<0 || toRemoveIndex>=indexOfLast) {
        cerr << "Index out of bounds" << endl;
        return;
    }
    this->deleteElement(toRemoveIndex);
    heapify(toRemoveIndex);
}

template<typename T>
void queue_s<T>::increaseQueueArray() {
    const auto newQueueArray = new T[capacity*2];
    for (int i = 0; i < usedSize+1; i++) {
        newQueueArray[i] = queueArray[i];
    }
    delete[] queueArray;
    queueArray = newQueueArray;
    capacity*=2;
}

template<typename T>
void queue_s<T>::removeOffset() {
    for (int i = offset; i < usedSize; i++) {
        queueArray[i-offset] = queueArray[i];
    }
    usedSize-=offset;
    offset=0;
}


template<typename T>
queue_s<T>::~queue_s() {
    delete[] queueArray;
}

template<typename T>
int queue_s<T>::getSize() const {
    return usedSize-offset;
}

template<typename T>
void queue_s<T>::release() {
    if(usedSize==0){return;}
    offset++;
}

template<typename T>
void queue_s<T>::join(T toInsert) {
    queueArray[usedSize]=toInsert;
    usedSize++;
    if(usedSize!=capacity) {
        return;
    }
    if (offset!=0) {
        removeOffset();
        return;
    }
    increaseQueueArray();
}

template<typename T>
T queue_s<T>::getElement(const int index) {
    if(index>=0 && index<getSize()) {
        return queueArray[index+offset];
    }
    cerr << "Index out of bound" << endl;
    return NULL;
}