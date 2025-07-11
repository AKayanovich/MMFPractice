#pragma once
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* down;

    Node(int val) : value(val), next(nullptr), down(nullptr) {}
};

class forward_list
{
private:
    Node* head;

    void bubleSort(int* array, int size);
    int countAllElements() const;
    void collectAllElements(int* array);
    Node* createSortedList(int* array, int size);

public:
    forward_list() : head(nullptr) {};

    void createSample();
    Node* flat();
    void printList(Node* listHead) const;
    void printSample() const;
    void clearList(Node* listHead);

    ~forward_list();
};

