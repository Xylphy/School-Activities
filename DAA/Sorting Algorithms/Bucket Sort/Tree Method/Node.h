#ifndef ALGORITHMS_NODE_H
#define ALGORITHMS_NODE_H

struct Node{
    int value;
    bool isBlack;
    Node *left, *right, *parent;
};

#endif //ALGORITHMS_NODE_H
