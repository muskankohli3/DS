#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int x): data(x),left(nullptr),right(nullptr) {}	
};

Node* insertInTree(){
	int x;
	cout<<"Enter Value: ";
	cin>>x;
	if(x == -1){
		return nullptr;
	}
	Node* root = new Node(x);
	cout<<"Enter left child of "<<x<<endl;
	root->left = insertInTree();
	cout<<"Enter right child of "<<x<<endl;
	root->right = insertInTree();
	return root;
}

void preorder(Node* root) {
	if(root == nullptr) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if(root == nullptr) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(Node* root){
	if(root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	Node* root = insertInTree();
	cout<<"Preorder of tree: ";
	preorder(root);
	cout<<"\nInorder of tree: ";
	inorder(root);
	cout<<"\nPostorder of tree: ";
	postorder(root);
}