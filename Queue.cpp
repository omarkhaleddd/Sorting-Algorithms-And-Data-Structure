#include <iostream>
#include <stdexcept>

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
    // Adds an element to the end of the queue
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
    // Removes the front element from the queue
    void dequeue() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty. Cannot dequeue.");
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr; //mantadory
            }
            delete temp;
            --size;
        }
    }
    // Returns the front element of the queue
    T peek() const {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty. No front element.");
        } else {
            return front->data;
        }
    }
    // Checks if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Returns the size of the queue
    int getSize() const {
        return size;
    }
    //destructor to dealocate the memory used to prevent memory leaks
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};
int main() {
    Queue<int> queue;
    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the front element
    std::cout << "Front element: " << queue.peek() << std::endl; // Output: 10

    // Dequeue an element
    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.peek() << std::endl; // Output: 20

    // Display the size of the queue
    std::cout << "Queue size: " << queue.getSize() << std::endl; // Output: 2

    // Check if the queue is empty
    if (queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl; // Output: Queue is not empty.
    }

    return 0;
}