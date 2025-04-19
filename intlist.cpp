// intlist.cpp
// Implements class IntList
// Jared Maeda, 18 April 2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    this->head = nullptr;
    this->tail = nullptr;

    Node* curr = source.head;
    while(curr){
        (*this).push_back(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while(head){
        Node* temp = head->next; // temporarily stores next node
        delete head;             // deletes the head node
        head = temp;             // sets head to the next node
    }
    head = nullptr;
}

// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;

    while(curr){
        total += curr->info;
        curr = curr->next;
    }

    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    bool containsValue;
    Node* curr = head;

    while(curr){
        if(curr->info == value){
            return true;
        }
        curr = curr->next;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head) return 0;
    
    Node* temp = head;
    int max = temp->info;
    while(temp){
        if(temp->info > max){
            max = temp->info;
        }
        temp = temp->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head) return 0.0;

    double total = 0.0;
    int count = 0;
    Node* curr = head;

    while(curr){
        total += curr->info;
        count++;
        curr = curr->next;
    }

    double average = total / count;

    return average;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    
    if(!head){
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }
    else{
        Node* temp = head;
        head = newNode;
        head->next = temp;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    if(!tail){
        tail = newNode;
        head = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node* curr = head;

    while(curr){
        count++;
        curr = curr->next;
    }

    return count;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this != &source){
        Node* sourceNode = source.head;
        Node* thisNode = this->head;
    
        while(sourceNode){
            if(thisNode){
                thisNode->info = sourceNode->info;
            }
            else{
                (*this).push_back(sourceNode->info);
            }
            thisNode = thisNode->next;
            sourceNode = sourceNode->next;
        }
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList() : head(nullptr), tail(nullptr) {}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

