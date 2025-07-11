#include "forward_list.h"

void forward_list::bubleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int forward_list::countAllElements() const
{
    int count = 0;
    Node* currentHead = head;

    while (currentHead != nullptr) {
        count++;
        Node* currentDown = currentHead->down;
        while (currentDown != nullptr) {
            count++;
            currentDown = currentDown->next;
        }
        currentHead = currentHead->next;
    }
    return count;
}

void forward_list::collectAllElements(int* array)
{
    int index = 0;
    Node* currentHead = head;

    while (currentHead != nullptr) {
        array[index++] = currentHead->value;
        
        Node* currentDown = currentHead->down;
        while (currentDown != nullptr) {
            array[index++] = currentDown->value;
            currentDown = currentDown->next;
        }
        currentHead = currentHead->next;
    }
}

Node* forward_list::createSortedList(int* array, int size)
{
    if (size == 0) return nullptr;

    Node* newHead = new Node(array[0]);
    Node* current = newHead;

    for (int i = 1; i < size; i++) {
        current->next = new Node(array[i]);
        current = current->next;
    }
    return newHead;
}

void forward_list::createSample()
{
    head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->down = new Node(7);
    head->down->next = new Node(8);
    head->down->next->next = new Node(30);

    head->next->down = new Node(20);
    head->next->down->next = new Node(50);

    head->next->next->down = new Node(22);
    head->next->next->down->next = new Node(40);

    head->next->next->next->down = new Node(35);
    head->next->next->next->down->next = new Node(45);
}

Node* forward_list::flat()
{
    int totalCount = countAllElements();

    int* array = new int[totalCount];

    collectAllElements(array);

    bubleSort(array, totalCount);

    Node* sortedList = createSortedList(array, totalCount);

    delete[] array;

    return sortedList;
}

void forward_list::printList(Node* listHead) const
{
    Node* current = listHead;
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void forward_list::printSample() const
{
    std::cout << "Структура списка:" << std::endl;
    Node* current = head;

    while (current != nullptr) {
        std::cout << "Основной: " << current->value;

        if (current->down != nullptr) {
            std::cout << " -> Дополнительный: ";
            Node* currentDown = current->down;
            while (currentDown != nullptr) {
                std::cout << currentDown->value;
                if (currentDown->next != nullptr) {
                    std::cout << " -> ";
                }
                currentDown = currentDown->next;
            }
        }

        std::cout << std::endl;
        current = current->next;
    }
}

void forward_list::clearList(Node* listHead)
{
    Node* current = listHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

forward_list::~forward_list()
{
    Node* current = head;
    while (current != nullptr) {
        Node* currentDown = current->down;
        while (currentDown != nullptr) {
            Node* temp = currentDown;
            currentDown = currentDown->next;
            delete temp;
        }

        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
