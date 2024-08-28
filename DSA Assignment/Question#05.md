
## AVL Tree and Closest Value in BST

### 1) Rotations to Make the Tree an AVL Tree

#### Given Tree:
```
         14
       /    \
      4      15
     / \       \
    3   9      18
       /       /  \
      7       16   20
     /           \
    5            17
```

#### Step-by-Step Rotations:

1. **Identify Balance Factors:**
   - Balance factor is calculated as `Height of left subtree - Height of right subtree`.

   Calculate the balance factor for each node starting from the leaf nodes:
   - Node 3: Height = 1, Balance Factor = 0
   - Node 5: Height = 1, Balance Factor = 0
   - Node 7: Height = 2, Balance Factor = 1 (Height of left child 5 - 0)
   - Node 9: Height = 3, Balance Factor = 2 (Left subtree with height 2, no right subtree)
   - Node 16: Height = 2, Balance Factor = -1 (No left child, right child has height 1)
   - Node 18: Height = 3, Balance Factor = 1 (Left subtree height 2 - Right subtree height 1)
   - Node 15: Height = 4, Balance Factor = -2 (Right subtree height 3, no left subtree)
   - Node 4: Height = 4, Balance Factor = -1
   - Node 14: Height = 5, Balance Factor = 1

   **Nodes that need rebalancing:**
   - Node 9 has a balance factor of 2 (left-heavy) → Right Rotation required at 9.
   - Node 15 has a balance factor of -2 (right-heavy) → Left Rotation required at 15.
   
   **Perform Rotations:**

   - **Right Rotation on Node 9:**
     - Node 7 becomes the new parent of Node 9, and Node 7's right child becomes the left child of Node 9.

   ```
         14
       /    \
      4      15
     / \       \
    3   7      18
       / \     /  \
      5   9   16   20
               \
               17
   ```

   - **Left Rotation on Node 15:**
     - Node 18 becomes the new parent of Node 15, and Node 18’s left child becomes the right child of Node 15.

   ```
         14
       /    \
      4      18
     / \    /  \
    3   7  15   20
       / \  /
      5   9 16
             \
             17
   ```

The tree is now balanced, and no further rotations are required.

### 2) Complexity of `heapify()` Method in Max Heap

The `heapify()` method in a max heap rearranges the elements to maintain the heap property where the parent node is always greater than or equal to its children.

#### Time Complexity Analysis:
- The complexity is derived based on the levels of the tree:
  - The height of the heap is `log n`.
  - At each level of the heap, `heapify()` may need to propagate the node down the tree, which can happen at most `log n` times.
  - The time complexity of `heapify()` is O(log n).

### 3) C++ Program to Find the Closest Value in a BST

Here’s a C++ program to find the closest value to a given target in a Binary Search Tree (BST):

```cpp
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    
    while (root) {
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }
        root = target < root->val ? root->left : root->right;
    }
    
    return closest;
}

// Helper function to insert nodes in the BST
TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) return new TreeNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    // Example BST
    TreeNode* root = nullptr;
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 18);
    root = insert(root, 7);
    root = insert(root, 16);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 17);

    double target = 12.0;
    cout << "Closest value to " << target << " is " << closestValue(root, target) << endl;

    return 0;
}
```

**Explanation:**
- The program traverses the BST in a manner similar to binary search.
- It keeps track of the closest value found so far and updates it as necessary while moving down the tree.
- The final closest value is returned.

