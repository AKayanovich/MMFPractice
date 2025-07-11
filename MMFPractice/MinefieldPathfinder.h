#pragma once
#include "Position.h"
#include "Queue.h"
#include "BST.h"

class MinefieldPathfinder {
private:
    char** field;
    int rows, cols;

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    Position getRandomBorderPosition();

public:
    MinefieldPathfinder(int r, int c);
    ~MinefieldPathfinder();

    void generateRandomField();
    void inputField();

    bool isOnBorder(int x, int y);
    bool isValid(int x, int y);
    bool isSafe(int x, int y);
    bool isSafeWithNeighbors(int x, int y);

    Position findSafeBorderPosition();
    int findShortestPath(Position start, Position end);

    void printField();
    void printFieldWithPath(Position start, Position end);
};