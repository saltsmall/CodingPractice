#include <iostream>
#include <string>
using namespace std;

class Node{
    string data;
    Node *left, *right;
public:
    Node() { data = ""; left = NULL; right = NULL; }
    void setData(char data) { this->data = data; }
    void setLeft(Node *left) { this->left = left; }
    void setRight(Node *right) { this->right = right; }
    //전위
    void static preorder(Node *root) {
        if (root) {
            cout << root->data;
            preorder(root->left);
            preorder(root->right);
        }
    }
    // 중위
    void static inorder(Node *root) { 
        if (root) {
            inorder(root->left);
            cout << root->data;
            inorder(root->right);
        }
    }
    //후위
    void static postorder(Node *root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data;
        }
    }
};


int main(void){
    int n;
    cin>>n;

    Node *node = new Node[n];
    for(int i=0; i<n; i++){
        char data,left,right;
        cin>>data>>left>>right;
        if(data!='.')
            node[(int)(data-'A')].setData(data);
        if(left!='.')
            node[(int)(data-'A')].setLeft(&node[(int)left-'A']);
        else
            node[(int)(data-'A')].setLeft(NULL);
        if(right!='.')
            node[(int)(data-'A')].setRight(&node[(int)right-'A']);
        else
            node[(int)(data-'A')].setRight(NULL);
    }
    Node *root = &node[0];
    Node::preorder(root);
    cout<<"\n";
    Node::inorder(root);
    cout<<"\n";
    Node::postorder(root);
    cout<<"\n";
}
