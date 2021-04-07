#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Queue.h"
#include "Node.h"
class BinarySearchTree
{   
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Node *newNode);
        void destroy_tree();
        void preOrder();
        void postOrder();
        void inOrder();
    private:
        void destroy_tree(Node *leaf);
        void preOrder(Node *leaf);
        void postOrder(Node *leaf);
        void inOrder(Node *leaf);
        void insert(Node *key, Node *leaf);
        Node *root;
};


#endif /* BINARYSEARCHTREE_H */
