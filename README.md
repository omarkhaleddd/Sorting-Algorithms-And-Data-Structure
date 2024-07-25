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

