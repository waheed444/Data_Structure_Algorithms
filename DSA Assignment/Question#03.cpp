#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node* findMin(Node* root) {
 while (root->left != nullptr) {
     root = root->left;
 }
 return root;
}
Node* deleteNode(Node* root, int key) {
 if (root == nullptr) return root;
 if (key < root->data) {
     root->left = deleteNode(root->left, key);
 } else if (key > root->data) {
     root->right = deleteNode(root->right, key);
 } else {
     // Node with only one child or no child
     if (root->left == nullptr) {
         Node* temp = root->right;
         delete root;
         return temp;
     } else if (root->right == nullptr) {
         Node* temp = root->left;
         delete root;
         return temp;
     }
     // Node with two children: Get the inorder successor (smallest in the right subtree)
     Node* temp = findMin(root->right);
     // Copy the inorder successor's content to this node
     root->data = temp->data;
     // Delete the inorder successor
     root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
void inorderTraversal(Node* root) {
 if (root != nullptr) {
     inorderTraversal(root->left);
     cout << root->data << " ";
     inorderTraversal(root->right);
 }
}
int main() {
 // Constructing the BST
 Node* root = new Node(7);
 root->left = new Node(5);
 root->right = new Node(12);
 root->left->left = new Node(3);
 root->left->right = new Node(6);
 root->left->left->left = new Node(1);
 root->left->left->right = new Node(4);
 root->left->left->right->right = new Node(8);
 root->right->left = new Node(9);
 root->right->right = new Node(15);
 root->right->left->left = new Node(8);
 root->right->left->right = new Node(10);
 root->right->right->left = new Node(13);
 root->right->right->right = new Node(17);
 cout << "Inorder traversal of the original tree: ";
 inorderTraversal(root);
 cout << endl;
 // Deleting node 9
 root = deleteNode(root, 9);
 cout << "Inorder traversal after deleting 9: ";
 inorderTraversal(root);
 cout << endl;
 // Deleting node 12
 root = deleteNode(root, 12);
 cout << "Inorder traversal after deleting 12: ";
 inorderTraversal(root);
 cout << endl;
 return 0;
}