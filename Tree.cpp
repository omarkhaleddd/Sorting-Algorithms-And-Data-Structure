//
// Created by Omar on 8/2/2024.
//
#include <iostream>

using namespace std;

// Definition of the TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Class definition for the binary tree
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(NULL) {}

    // Insert a value into the binary tree
    void insert(int val) {
        root = insertRec(root, val);
    }
    // Delete a node from the binary tree
    void deleteNode(int val) {
        root = deleteRec(root, val);
    }
    // Search for a value in the binary tree
    bool search(int val) {
        return searchRec(root, val);
    }

    // Inorder traversal of the binary tree
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Preorder traversal of the binary tree
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Postorder traversal of the binary tree
    void postorder() {
        postorderRec(root);
        cout << endl;
    }
private:
    // Helper function for insertion
    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insertRec(node->left, val);
        } else if (val > node->val) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    // Helper function for deletion
    TreeNode* deleteRec(TreeNode* root, int key) {
        if (root == nullptr) return root;

        // Traverse the tree
        if (key < root->val) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->val) {
            root->right = deleteRec(root->right, key);
        } else {
            // Node to be deleted found

            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the in-order successor (smallest in the right subtree or largest in the left subtree)
            TreeNode* temp = minValueNode(root->right);

            // Copy the in-order successor's content to this node
            root->val = temp->val;

            // Delete the in-order successor with the same value in the right subtree ( duplicated )
            root->right = deleteRec(root->right, temp->val);
        }
        return root;
    }

    // Helper function to find the node with the minimum value (in-order successor)
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Helper function for search
    bool searchRec(TreeNode* node, int val) {
        if (node == NULL) {
            return false;
        }
        if (node->val == val) {
            return true;
        }
        if (val < node->val) {
            return searchRec(node->left, val);
        } else {
            return searchRec(node->right, val);
        }
    }

    // Helper function for inorder traversal
    void inorderRec(TreeNode* node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->val << " ";
            inorderRec(node->right);
        }
    }
    // Helper function for preorder traversal
    void preorderRec(TreeNode* node) {
        if (node != NULL) {
            cout << node->val << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
    // Helper function for postorder traversal
    void postorderRec(TreeNode* node) {
        if (node != NULL) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->val << " ";
        }
    }
};
// Main function to demonstrate the functionality of the binary tree
int main() {
    BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    // Display the tree traversals
    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();



    // Search for elements in the binary tree
    cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    cout << "Node 50 Deleted \n";
    tree.deleteNode(50);
    cout << "Search 50: " << (tree.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}