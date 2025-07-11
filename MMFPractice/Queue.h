#pragma once
#include "Position.h"

struct QueueNode {
    Position pos;
    int distance;
    QueueNode* next;

    QueueNode(Position p, int d) : pos(p), distance(d), next(nullptr) {}
};


class Queue { // более простая очередь без шаблонов
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void push(Position pos, int dist);
    QueueNode pop();
    bool empty();

    ~Queue();
};
