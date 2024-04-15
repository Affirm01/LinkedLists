/*  Implementation of the Link class, which represents a linked list of data to form a coherent data structure. Defines various member functions
    that allow for manipulation and transversal of the linked list.
    Author: Ethan Smith
    CPSC 1070 - Spring 2024
    Lab 06 Phase C
*/

#include "List.h"

void List::insertStart(int data) {
    Node* newNode = new Node(data); // Creates new node
    newNode->setNextNode(head); // Sets the next node of the new node to the current head
    head = newNode; // Updates
}

void List::insertEnd(int data) {
    Node* newNode = new Node(data);

    // If list is empty, set new node as head and return
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse the list to find the last node
    Node* current = head;
    while (current->getNextNode() != nullptr) {
        current = current->getNextNode();
    }

    // Return the last node
    current->setNextNode(newNode);
}

void List::insertAt(int data, int addr) {
    Node* newNode = new Node(data);

    // If address = 0, insert new node at the start of the list
    if (addr == 0) {
        newNode->setNextNode(head);
        head = newNode;
        return;
    }

    // Traverse the list to find the node at the specified point
    Node* current = head;
    for (int i = 0; i < addr - 1 && current != nullptr; i++) { 
        current = current->getNextNode();
    }

    // If out of range, return error message
    if (current == nullptr) {
        cerr << "Error: Address out of range\n";
        delete newNode;
        return;
    }

    // Insert new node after the node at the specified point
    newNode->setNextNode(current->getNextNode());
    current->setNextNode(newNode);
}

void List::removeEnd(int* data) {
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: List is empty\n";
        return;
    }

    // If only one node in list
    if (head->getNextNode() == nullptr) {
        *data = head->getData(); // Set data to the value of head node
        delete head; // Delete head node
        head = nullptr;
        return;
    }

    // Traverse the list to find second-to-last node
    Node* current = head;
    while (current->getNextNode()->getNextNode() != nullptr) {
        current = current->getNextNode();
    }

    // Sets data to the value of the last node, deletes the last node, and sets the next pointer of second-to-last node to nullptr
    *data = current->getNextNode()->getData();
    delete current->getNextNode();
    current->setNextNode(nullptr);
}

void List::removeStart(int* data) {
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: The list is empty\n";
        return;
    }

    *data = head->getData(); // Gets the data from the head node
    Node* temp = head; // Stores the address of the head node in a temporary pointer
    head = head->getNextNode(); // Updates the head pointer to point to the next node
    delete temp; // Deletes the original head node

    // If the list becomes empty, output
    if (head == nullptr) {
        cerr << "The list is now empty\n";
    }
}

void List::removeAt(int* data, int addr) {
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: The list is empty\n";
        return;
    }

    // If specified point is 0, remove first node
    if (addr == 0) {
        *data = head->getData();
        Node* temp = head;
        head = head->getNextNode();
        delete temp;
        return;
    }

    // Traverse list to find specified node point
    Node* current = head;
    for (int i = 0; i < addr - 1 && current != nullptr; i++) {
        current = current->getNextNode();
    }

    // If specified point given is out of range, return error
    if (current == nullptr || current->getNextNode() == nullptr) {
        cerr << "Error: Address out of range\n";
        return;
    }

    // Remove the node at point
    Node* temp = current->getNextNode();

    *data = temp->getData(); // Gets data from the node to be removed
    current->setNextNode(temp->getNextNode()); // Updates the next pointer of the previous node
    delete temp;
}

void List::swapThisAndNext(int addr) {
    // Traverse list to find specified node point
    Node* current = head;
    for (int i = 0; i < addr && current != nullptr; i++) {
        current = current->getNextNode();
    }

    // If at the end, do nothing
    if (current == nullptr || current->getNextNode() == nullptr) {
        return;
    }

    // Swap the data of current node to the next node according to pointers
    Node* nextNode = current->getNextNode();
    int temp = current->getData();
    current->setData(nextNode->getData());
    nextNode->setData(temp);
}

int List::getFirst(int * data) {
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: List is empty\n";
        return -1;
    }

    // Return head data
    *data = head->getData();
    return *data;
}

int List::getLast(int * data) { 
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: List is empty\n";
        return -1;
    }

    // Traverse to the end of the list
    Node* current = head;
    while (current->getNextNode() != nullptr) {
        current = current->getNextNode();
    }

    // Get data of last node and return
    *data = current->getData();
    return *data;
}

int List::getAt(int position) {
    // If list is empty, return error
    if (head == nullptr) {
        cerr << "Error: List is empty\n";
        return -1;
    }

    // Traverse list to specified point
    Node* current = head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition < position) {
        current = current->getNextNode();
        currentPosition++; // Update position until reaching specified pos
    }

    // If position mathces the desired location, return data. Else, position is out of range, return error
    if (currentPosition == position && current != nullptr) {
        return current->getData();
    } else {
        cerr << "Error: Position out of range\n";
        return -1;
    }
}

int List::find(int value) {
    Node* current = head;
    int position = 0;

    // Traverse the list
    while (current != nullptr) {
        if (current->getData() == value) { // If current node matches desired value, return position in list
            return position;
        }
        // If not, continue iterating through the list while incrementing position each time
        current = current->getNextNode();
        position++;
    }

    return -1; // Return if not found in list
}

int List::size() {
    int count = 0;

    Node* current = head; // Sets current to head node

    // Counts through the list and sets count
    while (current != nullptr) {
        count++;
        current = current->getNextNode();
    }

    return count;
}

bool List::empty() {
    return head == nullptr; // Checks if head is null; Empty list
}

void List::printList() { // Added function
    Node* current = head; // Starts at the head node

    // Traverses list and outputs data from each position followed by a space until reaching the end.
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNextNode();
    }
    cout << endl; // Newline
}