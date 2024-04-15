/*  Cotains declaration of List and Node class, as well as prototypes for each function within a class accompanied with private variables and
    a constructor and deconstructor for the class.
    Author: Ethan Smith
    CPSC 1070 - Spring 2024
    Lab 06 Phase C
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

// Represents a single node in the linked list that would contain an integer data value and pointer to the next node in sequence
class Node {
    private:
        int data;
        Node* nextNode;

    public:
        Node() : data(0), nextNode(nullptr) {} // Default constructor
        Node(int data) : data(data), nextNode(nullptr) {} // Initializes data for Node constructor
        ~Node() { // Deconstructor
            nextNode = nullptr;
            delete nextNode;
        }

        int getData() const {
            return data;
        }
        Node* getNextNode() const {
            return nextNode;
        }
        void setData(int newData) {
            data = newData;
        }
        void setNextNode(Node* newNode) {
            nextNode = newNode;
        }
};

// Contains member functions to perform various operations on the linked list, inlcuding insertion, removal, traversal, and retrieval.
class List{ 
    private:
        Node* head;

    public:
        void insertStart(int data); // Inserts a new node with the provided data at the beginning of the list
        void insertEnd(int data); // Inserts a new node with the provided data at the end of the list
        void insertAt(int data, int addr); // Inserts a new node with the provided data at the specified position in the list
        void removeEnd(int* data); // Removes the last node from the list and stores its data in the provided pointer
        void removeStart(int* data); // Removes the first node from the list and stores its data in the provided pointer
        void removeAt(int* data, int addr); // Removes the node at the specified position in the list and stores its data in the provided pointer
        void swapThisAndNext(int addr); // Swaps the data of the node at the specified position with the data of its next node
        int getFirst(int * data); // Retrieves the data of the first node in the list and stores it in the provided pointer
        int getLast(int * data); // Retrieves the data of the last node in the list and stores it in the provided pointer
        int getAt(int position); // Retrieves the data of the node at the specified position in the list
        int find(int value); // Searches for the first occurrence of the provided value in the list and returns its position
        int size(); // Returns the number of nodes in the list
        bool empty(); // Checks if the list is empty
        void printList(); // Added for testing to compare list states easier.

        Node* getHead() const { return head; } // Default constructor initializing the head pointer to nullptr

        List() : head(nullptr) {} // Constructor
        ~List() { // Deconstructor
            while (head != nullptr) {
                Node* temp = head;
                head = head->getNextNode();
                delete temp;
            }
        }
};




#endif