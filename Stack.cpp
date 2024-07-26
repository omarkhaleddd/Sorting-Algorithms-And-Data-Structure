#include <iostream>
#include <vector>

template <typename T> // generic tyoe
class Stack {
private:
    std::vector<T> elements; // Container to store stack elements
public:
    // Pushes an element onto the stack
    void push(T value) {
        elements.push_back(value);
    }
    // Removes the top element from the stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }
    // Returns the top element of the stack
    T top() {
        if (!elements.empty()) {
            return elements.back();
        } else {
            throw std::out_of_range("Stack is empty. No top element.");
        }
    }
    // Checks if the stack is empty
    bool isEmpty() {
        return elements.empty();
    }
    // Returns the size of the stack
    int size() {
        return elements.size();
    }
};
int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the top element
    std::cout << "Top element: " << stack.top() << std::endl; // Output: 30

    // Pop an element
    stack.pop();

    // Print the top element
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Output: 20

    // Print the size of the stack
    std::cout << "Stack size: " << stack.size() << std::endl; // Output: 2

    // Check if the stack is empty
    if (stack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl; // Output: Stack is not empty.
    }

    return 0;
}