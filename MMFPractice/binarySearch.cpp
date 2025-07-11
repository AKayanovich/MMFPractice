#include "binarySearch.h"

void binarySearch::quickSort(int arr[], int left, int right)
{
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int binarySearch::partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void binarySearch::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int binarySearch::findLowerBound(int arr[], int size, int target)
{
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int binarySearch::findUpperBound(int arr[], int size, int target)
{
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int binarySearch::countElementsInRange(int sortedArray[], int size, int left, int right)
{
    int leftIndex = findLowerBound(sortedArray, size, left);

    int rightIndex = findUpperBound(sortedArray, size, right);

    return rightIndex - leftIndex;
}

bool binarySearch::checkInterval(int sortedArray[], int size, int E, int Y, int X)
{
    int leftBound = E - Y;
    int rightBound = E + Y;

    int count = countElementsInRange(sortedArray, size, leftBound, rightBound);

    return count >= X;
}

int binarySearch::removeDuplicates(int arr[], int size)
{
    if (size == 0) return 0;

    int uniqueCount = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}

bool binarySearch::needsImprovement(int numbers[], int N, int X, int Y)
{
    quickSort(numbers, 0, N - 1);

    int criticalPoints[2000];
    int pointCount = 0;

    for (int i = 0; i < N; i++) {
        criticalPoints[pointCount++] = numbers[i] - Y;
        criticalPoints[pointCount++] = numbers[i] + Y;
    }

    quickSort(criticalPoints, 0, pointCount - 1);

    pointCount = removeDuplicates(criticalPoints, pointCount);

    for (int i = 0; i < pointCount; i++) {
        int E = criticalPoints[i];
        if (checkInterval(numbers, N, E, Y, X)) {
            return true;
        }
    }

    return false;
}
