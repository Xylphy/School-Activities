#include "LinkedList.h"

void LinkedList::insertNum(int num) {
    Node* curr = head->next, *prev = head;
    while(curr && curr->value < num)
        curr = curr->next;
    prev->next = new Node{num, curr};
    size++;
}


int LinkedList::removeHead() {
    int removedElement = head->next->value;
    Node* node = head->next;
    head->next = head->next->next;
    size--;
    delete node;
    return removedElement;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}