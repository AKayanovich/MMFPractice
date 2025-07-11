#include "Queue.h"

void Queue::push(Position pos, int dist) 
{
    QueueNode* newNode = new QueueNode(pos, dist);
    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

QueueNode Queue::pop() 
{
    if (front == nullptr) {
        return QueueNode(Position(-1, -1), -1);
    }
    QueueNode result = *front;
    QueueNode* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return result;
}

bool Queue::empty() 
{
    return front == nullptr;
}

Queue::~Queue() 
{
    while (!empty()) {
        pop();
    }
}