#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
    }
};

class BST {
  Node* root;
public:

  BST() {
    root = nullptr;
  }

  Node* insertNode(Node* node, int val) {
    if (node == nullptr) {
      return new Node(val);
    }
    if (val < node->data) {
      node->left = insertNode(node->left, val);
    } 
    else if (val > node->data) {
      node->right = insertNode(node->right, val);
    }
    return node;
  }

  Node* findMin(Node* node) {
    while (node && node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* deleteNode(Node* node, int val) {
    if (node == nullptr) return node;
    if (val < node->data) {
      node->left = deleteNode(node->left, val);
    } 
    else if (val > node->data) {
      node->right = deleteNode(node->right, val);
    } 
    else {
      if (node->left == nullptr) {
        Node* temp = node->right;
        delete node;
        return temp;
    } 
    else if (node->right == nullptr) {
      Node* temp = node->left;
      delete node;
      return temp;
    }
    Node* temp = findMin(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
    return node;
  }

  int maxDepth(Node* node) {
    if (node == nullptr) return 0;
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    return max(leftDepth, rightDepth) + 1;
  }

  int minDepth(Node* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr) return minDepth(node->right) + 1;
    if (node->right == nullptr) return minDepth(node->left) + 1;
    return min(minDepth(node->left), minDepth(node->right)) + 1;
  }
  
  void insert(int val) {
    root = insertNode(root, val);
  }

  void remove(int val) {
    root = deleteNode(root, val);
  }

  int maximumDepth() {
    return maxDepth(root);
  }

  int minimumDepth() {
    return minDepth(root);
  }

  void inorder(Node* node) {
    if (node != nullptr) {
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }
  }

  void printInorder() {
    inorder(root);
    cout << endl;
  }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.printInorder();

    tree.remove(20);
    cout << "After deleting 20, inorder: ";
    tree.printInorder();

    cout << "Maximum depth: " << tree.maximumDepth() << endl;
    cout << "Minimum depth: " << tree.minimumDepth() << endl;

    return 0;
}
