#ifndef TREES_AND_HEAPS_REDBLACKTREE_H
#define TREES_AND_HEAPS_REDBLACKTREE_H

#include <iostream>
#include "Node.h"
using namespace std;
class RedBlackTree {
    Node* root, *null;
    unsigned long long size;
    Node* newNode(Node*, int);
    Node* minimumNode(Node*);
    void rotateLeft(Node*);
    void rotateRight(Node*);
    void insertHelper(Node*, int);
    void insertFix(Node*);
    void rbTransplant(Node* , Node*);
    void deleteFix(Node*);
public:
    RedBlackTree() : size(0), null(new Node{0, true, nullptr, nullptr}) {
        root = null;
    }
    void insert(int);
    void deleteNode(Node*);
    [[nodiscard]] bool isEmpty() const;
    int minimumValue();
};


#endif //TREES_AND_HEAPS_REDBLACKTREE_H
