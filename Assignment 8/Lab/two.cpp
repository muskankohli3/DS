#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* searchRecursive(Node* root, int key){
    if(root == nullptr || root->data == key){
        return root;
    }
    else if(key < root->data){
        return searchRecursive(root->left,key);
    }
    else{
        return searchRecursive(root->right,key);
    }
}

Node* searchIterative(Node* root, int key){
    while(root != nullptr && root->data != key){
        if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return root;
}

Node* maxElement(Node* root){
    if(root == nullptr) return nullptr;
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

Node* minElement(Node* root){
    if(root == nullptr) return nullptr;
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* node){
    if(node == nullptr) return nullptr;
    if(node->right != nullptr){
        return minElement(node->right);
    }
    Node* succ = nullptr;
    Node* p = root;
    while(p != nullptr){
        if(node->data < p->data){
            succ = p;
            p = p->left;
        }
        else if(node->data > p->data){
            p = p->right;
        }
        else{
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node){
    if(node == nullptr) return nullptr;
    if(node->left != nullptr){
        return maxElement(node->left);
    }
    Node* pred = nullptr;
    Node* p = root;
    while(p != nullptr){
        if(node->data > p->data){
            pred = p;
            p = p->right;
        }
        else if(node->data < p->data){
            p = p->left;
        }
        else{
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    
    int key = 15;
    
    cout<<"Recursive search for "<<key<<": "<< (searchRecursive(root,15) ? "Found":"Notfound")<<endl;
    
    cout<<"Iterative search for "<<key<<": "<< (searchIterative(root,15) ? "Found":"Not found")<<endl;
    
    cout<<"Maximum element: "<<(maxElement(root) ? maxElement(root)->data:-1)<<endl;
    
    cout<<"Minimum element: "<<(minElement(root) ? minElement(root)->data:-1)<<endl;
    
    cout<<"Inorder successor of "<< key << ": " << (inorderSuccessor(root,root->left->right) ? inorderSuccessor(root,root->left->right)->data:-1)<<endl;
    
    cout<<"Inorder predeccessor of "<< key<<": " << (inorderPredecessor(root,root->left->right) ? inorderPredecessor(root,root->left->right)->data:-1)<<endl;

    return 0;
}