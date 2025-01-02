//
// Created by lukyk on 24.12.2024.
//


#include <iostream>
#include "library.cpp"

int main() {
    cout <<"Queue:"<<endl;
    queue_s<double> h;
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
    h.release();
    for (int i = 0; i < h.getSize(); i++) {
        cout << h.getElement(i) << endl;
    }
    cout <<"------------------------"<<endl;
    h.join(7.98);
    h.join(5.78);


    for (int i = 0; i < h.getSize(); i++) {
        cout << h.getElement(i) << endl;
    }
    cout <<"------------------------"<<endl;
    cout <<"Heap:"<<endl;
    heap<double>::max hm;
    hm.insert(5.3);
    hm.insert(4.6);
    hm.insert(10.1);
    hm.insert(1.58);
    hm.insert(47.7);
    hm.insert(58.89);
    hm.insert(5.7);

    for (int i = 0; i < hm.getSize(); i++) {
        cout << hm.getElement(i) << endl;
    }
    cout <<"------------------------"<<endl;
    cout << hm.getElement(0) << endl;
    cout <<"------------------------"<<endl;
    hm.remove(0);
    for (int i = 0; i < hm.getSize(); i++) {
        cout << hm.getElement(i) << endl;
    }
    return 0;
}
