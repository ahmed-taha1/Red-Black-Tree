#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(){
    this->root = nullptr;
    this->nodesNum = 0;
}

int RedBlackTree::size() const{
    return this->nodesNum;
}

void RedBlackTree::insert(const int& val){
    if(isExist(val))
        return;
    Node* curr = BSTinsert(val);
    while (curr != root && curr->parent->color == 'R'){
        if(curr->parent->parent->right == curr->parent){
            if(curr->parent->parent->left != nullptr && curr->parent->parent->left->color == 'R'){  // #case 1
                curr->parent->color = 'B';  // parent = black
                curr->parent->parent->left->color = 'B';    // uncle = black
                curr->parent->parent->color = 'R';  // grand parent = red
                curr = curr->parent->parent;
            }
            else { 
                if (curr->parent->left == curr){   // #case 2
                    curr = curr->parent;
                    rightRotate(curr);
                }
                curr->parent->color = 'B';
                curr->parent->parent->color = 'R';
                leftRotate(curr->parent->parent);
            }
        } else { // parent is left child
            if(curr->parent->parent->right != nullptr && curr->parent->parent->right->color == 'R'){  // #case 1
                curr->parent->color = 'B';  // parent = black
                curr->parent->parent->right->color = 'B';   // uncle = black
                curr->parent->parent->color = 'R';  // grand parent = red 
                curr = curr->parent->parent;
            } else {
                if(curr->parent->right == curr){    // #case 2
                    curr = curr->parent;
                    leftRotate(curr);
                }
                curr->parent->color = 'B';  // #case 3
                curr->parent->parent->color = 'R';
                rightRotate(curr->parent->parent);
            }
        }
    }
    
    this->nodesNum++;
    root->color = 'B';
}

Node* RedBlackTree::BSTinsert(const int& val){
    Node* temp = new Node();
    temp->val = val;
    if(root == nullptr) {
        root = temp;
    } else {
        Node* curr = root;
        Node* parent = root;
        while (true){
            if(curr->right != nullptr && val > curr->val){
                curr = curr->right;
            }
            else if(curr->left != nullptr && val < curr->val){
                curr = curr->left;
            }
            else{
                break;
            }
            parent = curr;
        }

        if(val > curr->val){
            curr->right = temp;
        } else {
            curr->left = temp;
        }
        temp->parent = parent;

        return temp;
    }
    return root;
}

bool RedBlackTree::isExist(const int& val) const{
    if(getNode(val) == nullptr)
        return false;
    return true;
}

Node* RedBlackTree::getNode(const int& val) const{
    if(root == nullptr)
        return root;
    
    Node* curr = root;
    while (true){
        if(curr->val == val)
            return curr;

        if(curr->right != nullptr && val > curr->val){
            curr = curr->right;
        }
        else if(curr->left != nullptr && val < curr->val){
            curr = curr->left;
        }
        else{
            break;
        }
    }

    return nullptr;
}

char RedBlackTree::getNodeColor(const int& val) const{
    Node* node = getNode(val);
    if(node == nullptr)
        return '0';
    return node->color;
}

void RedBlackTree::rightRotate(Node* x){
    Node* xp = x->parent;
    Node* b = x->left;

    if(b->right != nullptr)
        b->right->parent = x;
    x->left = b->right;
    x->parent = b;
    b->parent = xp;
    b->right = x;

    // update parent down link
    if(xp != nullptr)
        if(xp->right == x)
            xp->right = b;
        else
            xp->left = b;
    if(x == root)
        root = b;
}

void RedBlackTree::leftRotate(Node* x){
    Node* xp = x->parent;
    Node* b = x->right;

    if(b->left != nullptr)
        b->left->parent = x;

    x->right = b->left;
    x->parent = b;
    b->parent = xp;
    b->left = x;

    // update parent down link
    if(xp != nullptr)
        if(xp->right == x)
            xp->right = b;
        else
            xp->left = b;
    if(x == root)
        root = b;
}

int RedBlackTree::getMax(){
    if(root == nullptr)
        return -1;

    Node* node = root;
    while (node->right != nullptr){
        node = node->right;
    }

    return node->val;
}

int RedBlackTree::getMin(){
    if(root == nullptr)
        return -1;

    Node* node = root;
    while (node->left != nullptr){
        node = node->left;
    }

    return node->val;
}