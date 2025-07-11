#include <iostream>
#include <clocale>
#include "allTasks.h"
#include "tangent22.h"
#include "digit-word.h"

int main() {
    setlocale(LC_ALL, "RU");
    int choice{ 99 };
    while (choice != 0) {
        cout << endl << "Выберите задание:" << endl
            << "1. Рекурсия (интеграл от тангенса в степени) (22)" << endl
            << "2. Односвязный список (реализация аналога функции flat) (12)" << endl
            << "3. Очередь на одном и двух стеках (11)" << endl
            << "4. Бинарное дерево поиска (кратчайший путь) (12)" << endl
            << "5. Бинарный поиск (проверка рандомайзера) (9)" << endl
            << "6. Олимпиадная задача (цифровое слово) (1)" << endl
            << "0. Выход" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                tangent22(); break;
            }
            case 2: {
                practice::forwardList12(); break;
            }
            case 3: {
                practice::queue11(); break;
            }
            case 4: {
                practice::mines12(); break;
            }
            case 5: {
                practice::binarySearch9(); break;
            }
            case 6: {
                word(); break;
            }
          
            default:
                cout << "Выберите число от 0 до 6";
        }
    }
    
}
