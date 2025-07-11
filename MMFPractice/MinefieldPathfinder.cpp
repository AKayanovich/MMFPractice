#include "MinefieldPathfinder.h"
#include <iostream>
#include <ctime>

using namespace std;

MinefieldPathfinder::MinefieldPathfinder(int r, int c) : rows(r), cols(c) {
    field = new char* [rows];
    for (int i = 0; i < rows; i++) {
        field[i] = new char[cols];
    }
}

MinefieldPathfinder::~MinefieldPathfinder() {
    for (int i = 0; i < rows; i++) {
        delete[] field[i];
    }
    delete[] field;
}

void MinefieldPathfinder::generateRandomField() {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            field[i][j] = '0';
        }
    }

    int totalCells = rows * cols;
    int mineCount = totalCells * 0.3 + rand() % (totalCells / 10 + 1);

    cout << "Генерируется поле с " << mineCount << " минами..." << endl;

    int placedMines = 0;
    while (placedMines < mineCount) {
        int x = rand() % rows;
        int y = rand() % cols;

        if (field[x][y] != '+') {
            field[x][y] = '+';
            placedMines++;
        }
    }
}

void MinefieldPathfinder::inputField() {
    cout << "Введите поле (" << rows << "x" << cols << "), где '+' - мина, '0' - не мина:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> field[i][j];
        }
    }
}

bool MinefieldPathfinder::isOnBorder(int x, int y) {
    return (x == 0 || x == rows - 1 || y == 0 || y == cols - 1);
}

bool MinefieldPathfinder::isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool MinefieldPathfinder::isSafe(int x, int y) {
    if (!isValid(x, y)) return false;

    return field[x][y] != '+';
}

bool MinefieldPathfinder::isSafeWithNeighbors(int x, int y) {
    if (!isValid(x, y)) return false;

    if (field[x][y] == '+') return false;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && field[nx][ny] == '+') {
            return false;
        }
    }

    return true;
}

Position MinefieldPathfinder::getRandomBorderPosition() {
    int side = rand() % 4;
    int x, y;

    switch (side) {
    case 0:
        x = 0;
        y = rand() % cols;
        break;
    case 1:
        x = rows - 1;
        y = rand() % cols;
        break;
    case 2:
        x = rand() % rows;
        y = 0;
        break;
    case 3:
        x = rand() % rows;
        y = cols - 1;
        break;
    }

    return Position(x, y);
}

Position MinefieldPathfinder::findSafeBorderPosition() {
    for (int attempts = 0; attempts < 100; attempts++) {
        Position pos = getRandomBorderPosition();
        if (isSafeWithNeighbors(pos.x, pos.y)) {
            return pos;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isOnBorder(i, j) && isSafeWithNeighbors(i, j)) {
                return Position(i, j);
            }
        }
    }

    return Position(-1, -1); 
}

int MinefieldPathfinder::findShortestPath(Position start, Position end) {
    if (!isOnBorder(start.x, start.y) || !isOnBorder(end.x, end.y)) {
        cout << "Ошибка: начальная и конечная точки должны быть на кайме поля!" << endl;
        return -1;
    }

    if (!isSafe(start.x, start.y)) {
        cout << "Ошибка: нельзя начинать с заминированной ячейки!" << endl;
        return -1;
    }

    if (!isSafe(end.x, end.y)) {
        cout << "Ошибка: конечная точка заминирована!" << endl;
        return -1;
    }

    Queue queue;
    BST visited;

    queue.push(start, 0);
    visited.insert(start);

    while (!queue.empty()) {
        QueueNode current = queue.pop();
        Position currentPos = current.pos;
        int currentDist = current.distance;

        if (currentPos.x == end.x && currentPos.y == end.y) {
            return currentDist;
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentPos.x + dx[i];
            int newY = currentPos.y + dy[i];
            Position newPos(newX, newY);

            if (isSafe(newX, newY) && !visited.contains(newPos)) {
                visited.insert(newPos);
                queue.push(newPos, currentDist + 1);
            }
        }
    }

    return -1; 
}

void MinefieldPathfinder::printField() {
    cout << "Текущее поле:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void MinefieldPathfinder::printFieldWithPath(Position start, Position end) {
    cout << "Поле с отмеченными начальной (S) и конечной (E) точками:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == start.x && j == start.y) {
                cout << "S ";
            }
            else if (i == end.x && j == end.y) {
                cout << "E ";
            }
            else {
                cout << field[i][j] << " ";
            }
        }
        cout << endl;
    }
}