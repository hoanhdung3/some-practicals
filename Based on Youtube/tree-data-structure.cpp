// https://www.youtube.com/watch?v=UHxtjVsOTHc
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

int main()
{
    // Level 1 
    Node* root = createNode(1);
    
    // Level 2 
    root->left = createNode(2);
    root->right = createNode(3);
    
    // Level 3 
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // level 4
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(10);
    return 0;
}
