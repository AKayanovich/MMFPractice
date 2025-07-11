#pragma once

#include <stdexcept>

template <typename T>
class myStack {
private:

    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* top_node;
    int stack_size;

public:
    myStack() : top_node(nullptr), stack_size(0) {}

    ~myStack() {
        while (!is_empty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = top_node;
        top_node = new_node;
        stack_size++;
    }

    T pop() {
        if (is_empty()) {
            throw std::runtime_error("Стек пуст");
        }

        Node* temp = top_node;
        T value = temp->data;
        top_node = top_node->next;
        delete temp;
        stack_size--;
        return value;
    }

    T top() const {
        if (is_empty()) {
            throw std::runtime_error("Стек пуст");
        }
        return top_node->data;
    }

    bool is_empty() const {
        return top_node == nullptr;
    }

    int size() const {
        return stack_size;
    }
};

