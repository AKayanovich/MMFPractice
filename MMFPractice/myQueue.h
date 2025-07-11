#pragma once

#include "myStack.h"

#include "myStack.h"

template <typename T>
class QueueTwoStacks {
private:
    myStack<T> input_stack;
    myStack<T> output_stack;
    mutable int operation_count;

    void transfer_elements() {
        while (!input_stack.is_empty()) {
            output_stack.push(input_stack.pop());
            operation_count += 2;
        }
    }

public:
    QueueTwoStacks() : operation_count(0) {}

    void enqueue(const T& value) {
        input_stack.push(value);
        operation_count++;
    }

    T dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Очередь пуста");
        }

        if (output_stack.is_empty()) {
            transfer_elements();
        }

        operation_count++;
        return output_stack.pop();
    }

    T front() const {
        if (is_empty()) {
            throw std::runtime_error("Очередь пуста");
        }

        if (output_stack.is_empty()) {
            QueueTwoStacks<T>* non_const_this = const_cast<QueueTwoStacks<T>*>(this);
            non_const_this->transfer_elements();
        }

        operation_count++;
        return output_stack.top();
    }

    bool is_empty() const {
        return input_stack.is_empty() && output_stack.is_empty();
    }

    int size() const {
        return input_stack.size() + output_stack.size();
    }

    int get_operation_count() const {
        return operation_count;
    }

    void reset_operation_count() {
        operation_count = 0;
    }
};

template <typename T>
class QueueOneStack {
private:
    myStack<T> main_stack;
    int operation_count;

    T dequeue_recursive() {
        if (main_stack.size() == 1) {
            operation_count++;
            return main_stack.pop();
        }

        T temp = main_stack.pop();
        operation_count++;
        T result = dequeue_recursive();
        main_stack.push(temp);
        operation_count++;
        return result;
    }

public:
    QueueOneStack() : operation_count(0) {}

    void enqueue(const T& value) {
        main_stack.push(value);
        operation_count++;
    }

    T dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Очередь пуста");
        }

        return dequeue_recursive();
    }

    T front() {
        if (is_empty()) {
            throw std::runtime_error("Очередь пуста");
        }

        T result = dequeue();

        myStack<T> temp_stack;
        while (!main_stack.is_empty()) {
            temp_stack.push(main_stack.pop());
            operation_count += 2;
        }

        main_stack.push(result);
        operation_count++;
        while (!temp_stack.is_empty()) {
            main_stack.push(temp_stack.pop());
            operation_count += 2;
        }

        return result;
    }

    bool is_empty() const {
        return main_stack.is_empty();
    }

    int size() const {
        return main_stack.size();
    }

    int get_operation_count() const {
        return operation_count;
    }

    void reset_operation_count() {
        operation_count = 0;
    }
};