struct Node{
    Node* parent;
    Node* left;
    Node* right;
    int val;
    char color;
    Node(){
        parent = left = right = nullptr;
        val = 0;
        color = 'R';
    }
};