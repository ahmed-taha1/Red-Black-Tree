#include "RedBlackTree.cpp"

int main(){
    RedBlackTree RBT;
    RBT.insert(5);
    RBT.insert(7);
    RBT.insert(10);
    RBT.insert(8);
    RBT.insert(9);
    cout << RBT.getMin() << '\n';
    cout << RBT.size();
}