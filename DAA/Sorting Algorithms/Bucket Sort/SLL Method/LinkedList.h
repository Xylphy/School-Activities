#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "Node.h"
class LinkedList {
    Node* head;
    int size;
public:
    LinkedList(): size(0), head(new Node{0, nullptr}) {}
    [[nodiscard]] bool isEmpty() const;
    void insertNum(int);
    int removeHead();
};


#endif //ALGORITHMS_LINKEDLIST_H