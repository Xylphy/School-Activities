#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#include "Node.h"
#include <iostream>
class LinkedList {
    Node* head, *tail;
    int size;
    static void addBetween(Node*, Node*, int);
    static void removeBetween(Node*);
public:
    LinkedList(): size(0), head(new Node{0, nullptr, nullptr}) {
        tail = new Node{0, head, nullptr};
        head->next = tail;
    }
    [[nodiscard]] bool isEmpty() const;
    void insertNum(int);
    int removeHead();
};


#endif //ALGORITHMS_LINKEDLIST_H
