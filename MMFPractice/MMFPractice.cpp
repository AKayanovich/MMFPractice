#include <iostream>
#include <clocale>
#include "allTasks.h"
#include "tangent22.h"
#include "digit-word.h"

int main() {
    setlocale(LC_ALL, "RU");
    int choice{ 99 };
    while (choice != 0) {
        cout << endl << "�������� �������:" << endl
            << "1. �������� (�������� �� �������� � �������) (22)" << endl
            << "2. ����������� ������ (���������� ������� ������� flat) (12)" << endl
            << "3. ������� �� ����� � ���� ������ (11)" << endl
            << "4. �������� ������ ������ (���������� ����) (12)" << endl
            << "5. �������� ����� (�������� ������������) (9)" << endl
            << "6. ����������� ������ (�������� �����) (1)" << endl
            << "0. �����" << endl;
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
                cout << "�������� ����� �� 0 �� 6";
        }
    }
    
}
