#include "allTasks.h"
#include "forward_list.h"
#include "myQueue.h"
#include "binarySearch.h"
#include "MinefieldPathfinder.h"

using namespace std;

void practice::forwardList12()
{
    forward_list list;

    list.createSample();

    list.printSample();

    std::cout << std::endl;

    Node* flatList = list.flat();

    std::cout << "��������� �����������: ";
    list.printList(flatList);

    list.clearList(flatList);
}



void practice::queue11 () {
    const int N = 10;

    std::cout << "=== ������������ � " << N << " ���������� ===" << std::endl;

    QueueTwoStacks<int> queue_two;
    QueueOneStack<int> queue_one;

    std::cout << "\n��������� " << N << " ��������� � ��� �������:" << std::endl;
    for (int i = 1; i <= N; i++) {
        queue_two.enqueue(i);
        queue_one.enqueue(i);
    }

    std::cout << "������� �� ���� ������ - �������� �� ����������: " << queue_two.get_operation_count() << std::endl;
    std::cout << "������� �� ����� ����� - �������� �� ����������: " << queue_one.get_operation_count() << std::endl;

    queue_two.reset_operation_count();
    queue_one.reset_operation_count();

    std::cout << "\n��������� ��� ��������:" << std::endl;
    while (!queue_two.is_empty()) {
        queue_two.dequeue();
    }

    while (!queue_one.is_empty()) {
        queue_one.dequeue();
    }

    std::cout << "������� �� ���� ������ - �������� �� ����������: " << queue_two.get_operation_count() << std::endl;
    std::cout << "������� �� ����� ����� - �������� �� ����������: " << queue_one.get_operation_count() << std::endl;

    std::cout << "\n=== ������������ �������� front ===" << std::endl;

    QueueTwoStacks<int> queue_two_front;
    QueueOneStack<int> queue_one_front;

    for (int i = 1; i <= 5; i++) {
        queue_two_front.enqueue(i);
        queue_one_front.enqueue(i);
    }

    queue_two_front.reset_operation_count();
    queue_one_front.reset_operation_count();

    queue_two_front.front();
    queue_one_front.front();

    std::cout << "������� �� ���� ������ - �������� �� front: " << queue_two_front.get_operation_count() << std::endl;
    std::cout << "������� �� ����� ����� - �������� �� front: " << queue_one_front.get_operation_count() << std::endl;
}

void practice::binarySearch9()
{
    int N, X, Y;

    cout << "������� ���������� ����� N: ";
    cin >> N;

    cout << "������� �������� X � Y: ";
    cin >> X >> Y;

    srand(time(NULL));

    int numbers[1000];

    cout << "��������������� �����: ";
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 10000 + 1;
        cout << numbers[i] << " ";
    }
    cout << "\n";

    
    if (binarySearch::needsImprovement(numbers, N, X, Y)) {
        cout << "��������� ��������� � ���������\n";
    }
    else {
        cout << "��������� �������� ���������\n";
    }
}

int practice::mines12()
{
    int rows, cols;
    cout << "������� ������� ���� (������ �������): ";
    cin >> rows >> cols;
    if (rows < 3 || cols < 3) {
        cout << "������: ���� ������ ���� ������� 3x3!" << endl;
        return 1;
    }

    MinefieldPathfinder pathfinder(rows, cols);

    char choice;
    cout << "������������� ���� ��������? (y/n): ";
    cin >> choice;

    Position start, end;

    if (choice == 'y' || choice == 'Y') {
        pathfinder.generateRandomField();

        start = pathfinder.findSafeBorderPosition();
        if (start.x == -1) {
            cout << "������: �� ������� ����� ���������� ��������� �������!" << endl;
            return 1;
        }

        end = pathfinder.findSafeBorderPosition();
        if (end.x == -1) {
            cout << "������: �� ������� ����� ���������� �������� �������!" << endl;
            return 1;
        }

        int attempts = 0;
        while ((start.x == end.x && start.y == end.y) && attempts < 50) {
            end = pathfinder.findSafeBorderPosition();
            attempts++;
        }
    }
    else {
        pathfinder.inputField();

        int startX, startY, endX, endY;
        cout << "������� ��������� ������� (������ �������): ";
        cin >> startX >> startY;
        cout << "������� �������� ������� (������ �������): ";
        cin >> endX >> endY;

        start = Position(startX, startY);
        end = Position(endX, endY);
    }

    pathfinder.printFieldWithPath(start, end);

    int result = pathfinder.findShortestPath(start, end);
    if (result != -1) {
        cout << "����� ����: " << result << endl;
    }
    else {
        cout << "���� �� ������!" << endl;
    }

    return 0;
}