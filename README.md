# Data Structure Documentation

## Linked List 
### Overview 
A linked list is a data structure consisting of a collection of nodes that together represent a sequence. Each node contains:
- Data
- A reference (or link) to the next node in the sequence

### Types of Linked Lists
1. Singly Linked List: Each node points to the next node in the sequence.
2. Doubly Linked List: Each node points to both its next and previous nodes.
3. Circular Linked List: The last node points to the first node, forming a circle.
### Basic Operations
1. Insertion: Add a node at the beginning, end, or a specific position.
2. Deletion: Remove a node from the beginning, end, or a specific position.
3. Traversal: Visit all the nodes in the linked list.
4. Search: Find a node with a specific value.
5. Reversal: Reverse the order of nodes in the linked list.

### Singly Linked List Implementation in C++
#### Node Structure
Each node in a singly linked list has two components: data and a pointer to the next node.

**Node Structure**
``` struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
#### Linked List Class
The linked list class contains a pointer to the head node and methods to perform various operations.
**Linked List**

``` 
class LinkedList {
private:
    ListNode *head;

public:
    LinkedList() : head(nullptr) {}
```
**Insert At The Beginning**

```
 void insertAtBeginning(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }
```
**Insert At The End**
```
    void insertAtEnd(int val) {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
```
**Delete Node**
```
    void deleteNode(int key) {
        ListNode *temp = head;
        ListNode *prev = nullptr;

        if (temp != nullptr && temp->val == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->val != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }
```
**Searching For Node**
```
    bool search(int key) {
        ListNode *temp = head;
        while (temp != nullptr) {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }
```
**Reverse The Linked List**
```
    void reverse() {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
```
**Displaying The Linked List**
```
void display() {
        ListNode *temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
```

### Complexity Analysis
#### Time Complexity
##### Best Case For Insertion: 𝑂(1)
When we insert at the beginning.

##### Average & Worst Case: 𝑂(𝑛)
When we insert at the end of the linked list.

#### Space Complexity
##### Auxiliary Space: 𝑂(1)
The space used is constant because you only need a few pointers to keep track of the previous, current, and next nodes.

---
## Stack

### Overview
A stack is a data structure that follows the Last In, First Out (LIFO) principle. Elements are added to and removed from the same end, known as the top of the stack. This implementation uses a `std::vector` to manage the stack elements and is templated to support various data types.

#### Basic Operations
1. **Push**: Adds an element to the top of the stack.
2. **Pop**: Removes the top element from the stack.
3. **Top**: Returns the top element of the stack without removing it.
4. **Is Empty**: Checks whether the stack is empty.
5. **Size**: Returns the number of elements in the stack.

### Stack Implementation in C++

#### Stack Class
The stack class is implemented using a template to allow for generic data types. It utilizes `std::vector` to store the elements.

##### Stack Class Definition
```
template <typename T>
class Stack {
private:
    std::vector<T> elements; // Container to store stack elements

public:
```
##### Pushes an element onto the stack
```
    void push(T value) {
        elements.push_back(value);
    }
```
##### Removes the top element from the stack
```
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }
```
##### Returns the top element of the stack
```
    T top() {
        if (!elements.empty()) {
            return elements.back();
        } else {
            throw std::out_of_range("Stack is empty. No top element.");
        }
    }
```
##### Checks if the stack is empty
```
    bool isEmpty() {
        return elements.empty();
    }
```
##### Returns the size of the stack
```
    int size() {
        return elements.size();
    }
};
```
### Complexity Analysis
#### Time Complexity
- All Stack Operations: O(1)
Operations are done in constant time.

#### Space Complexity
- Auxiliary Space: O(n)
The space used by the stack is proportional to the number of elements in the stack due to the storage in the std::vector.

---
## Queue

### Overview
A queue is a data structure that follows the First In, First Out (FIFO) principle. Elements are added to the end (rear) and removed from the front of the queue. This implementation uses a linked list to manage the queue elements and is templated to support various data types.

### Basic Operations
1. **Enqueue**: Adds an element to the end of the queue.
2. **Dequeue**: Removes the element from the front of the queue.
3. **Peek**: Returns the front element of the queue without removing it.
4. **Is Empty**: Checks whether the queue is empty.
5. **Get Size**: Returns the number of elements in the queue.

## Queue Implementation in C++

### Queue Class
The queue class is implemented using a template to allow for generic data types. It uses a linked list to manage elements.

#### Queue Class Definition
```cpp
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
```
#### Adds an element to the end of the queue
```
    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++size;
    }
```
#### Removes the front element from the queue
```
    void dequeue() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty. Cannot dequeue.");
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr; // Mandatory: Update rear when queue becomes empty
            }
            delete temp;
            --size;
        }
    }
```
#### Returns the front element of the queue
```
    T peek() const {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty. No front element.");
        } else {
            return front->data;
        }
    }
```
#### Checks if the queue is empty
```
    bool isEmpty() const {
        return front == nullptr;
    }
```
#### Returns the size of the queue
```
    int getSize() const {
        return size;
    }
```
#### Destructor to deallocate memory used to prevent memory leaks
```
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
```
### Complexity Analysis
#### Time Complexity
- All Queue Operations: O(1)
The Operations are done in constant time.

#### Space Complexity
- Auxiliary Space: O(n)
The space used by the queue is proportional to the number of elements in the queue due to the storage in the linked list.

### Additional Notes
- Destructor: Ensures that all dynamically allocated nodes are deleted to prevent memory leaks.
- Front and Rear Pointers: The front pointer points to the first node, and the rear pointer points to the last node. When the queue is empty, both pointers are nullptr.

---

## Binary Search Tree
### Overview
A tree is a hierarchical data structure consisting of nodes connected by edges. Each node contains:
- Data
- References (or links) to its child nodes

### Types of Trees
1. Binary Tree: Each node has at most two children, referred to as the left child and the right child.
2. Binary Search Tree (BST): A binary tree in which each node's value is greater than the values in its left subtree and less than the values in its right subtree.
3. AVL Tree: A self-balancing binary search tree where the difference in heights between left and right subtrees cannot be more than one for all nodes.

### Basic Operations
1. Insertion: Add a node at the appropriate position maintaining the tree properties.
2. Deletion: Remove a node and restructure the tree to maintain its properties.
3. Traversal: Visit all the nodes in a specific order.
4. Search: Find a node with a specific value.
### Binary Tree Implementation in C++
#### Node Structure
Each node in a binary tree has three components: data, a pointer to the left child, and a pointer to the right child.
```
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```
#### Tree Class
The tree class contains a pointer to the root node and methods to perform various operations.
```
class BinaryTree {
private:
    TreeNode *root;
```
##### Insert Node
```
    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insertRec(node->left, val);
        } else if (val > node->val) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
```
##### Deleting a Node
```
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
```
##### Seach For Node
```
    bool searchRec(TreeNode* node, int val) {
        if (node == nullptr) {
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
```
##### Inorder Traversal
```
    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->val << " ";
            inorderRec(node->right);
        }
    }
```
##### Preorder Traversal
```
    void preorderRec(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->val << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
```
##### Postorder Traversal
```
    void postorderRec(TreeNode* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            std::cout << node->val << " ";
        }
    }

```
### Complexity Analysis
#### Time Complexity
##### Best Case for Insertion: 𝑂(log 𝑛) for Binary Search tree
##### Average & Worst Case: 𝑂(𝑛)
#### Space Complexity
##### Auxiliary Space: 𝑂(1)
The space used is constant because you only need a few pointers to keep track of the current node and its children.
