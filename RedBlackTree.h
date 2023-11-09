#include <bits/stdc++.h>
#include "RedBlackTreeNode.cpp"
using namespace std;

class RedBlackTree{
    private:
        int nodesNum;
        Node* root;
        Node* getNode(const int& val) const;
        void leftRotate(Node* x);
        void rightRotate(Node* x);
public:
    RedBlackTree();
    int size() const;
    void insert(const int& val);
    Node* BSTinsert(const int& val);
    bool isExist(const int& val) const;
    char getNodeColor(const int& val) const;
    int getMin();
    int getMax();
    // void deleteNode(const int& val);
    // ~RedBlackTree();
};