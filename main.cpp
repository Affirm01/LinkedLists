/*  Main file made to test the interatction between the LinkedLists and Nodes
    Author: Ethan Smith
    CPSC 1070 - Spring 2024
    Lab 06 Phase C
*/
#include "List.h"

int main() { 
    List list;
    int data;

    cout << "Empty? " << list.empty() << endl;
    cout << "size: " << list.size() << endl;

    for(int i = 0; i < 100; i++) {
        list.insertStart(i);
    }

    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    list.removeStart(&data);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    list.insertEnd(44);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    list.insertAt(3221, 4);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;
    
    list.removeEnd(&data);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    list.removeAt(&data, 4);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    list.swapThisAndNext(4);
    cout << "printed list: ";
    list.printList();
    cout << "size: " << list.size() << endl;

    cout << "first: " << list.getFirst(&data) << endl;
    cout << "last: " << list.getLast(&data) << endl;
    cout << "head: " << list.getHead()->getData() << endl;
    cout << "Finding num pos: " << list.find(43) << endl;
    cout << "Getting num: " << list.getAt(55) << endl;
    cout << "Empty? " << list.empty() << endl;

}