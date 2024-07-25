#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
private:
    ListNode *head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
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

    // Delete a node
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

    // Search for a node
    bool search(int key) {
        ListNode *temp = head;
        while (temp != nullptr) {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
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

    // Display the linked list
    void display() {
        ListNode *temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.display();

    list.deleteNode(20);
    list.display();

    std::cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 40: " << (list.search(40) ? "Found" : "Not Found") << std::endl;

    list.reverse();
    list.display();

    return 0;
}
