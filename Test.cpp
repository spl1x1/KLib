//
// Created by lukyk on 24.12.2024.
//


#include <iostream>
#include "library.cpp"

int main() {
    queue<double> h;;
    h.join(3.4);
    h.join(4.87);
    h.join(3.14);
    h.join(2.41);
    h.join(5.45);
    h.join(6.87);
    h.join(7.98);
    h.join(1.47);
    for (int i = 0; i < h.getSize(); i++) {
        cout << h.getElement(i) << endl;
    }
    cout <<"------------------------"<<endl;
    h.release();
    for (int i = 0; i < h.getSize(); i++) {
        cout << h.getElement(i) << endl;
    }
    cout <<"------------------------"<<endl;
    h.release();
    for (int i = 0; i < h.getSize(); i++) {
        cout << h.getElement(i) << endl;
    }
     return 0;
}
