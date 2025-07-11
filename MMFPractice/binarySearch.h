#pragma once

#include <iostream>
#include <ctime>
using namespace std;

namespace binarySearch
{
    void quickSort(int arr[], int left, int right);
    int partition(int arr[], int left, int right);
    void swap(int& a, int& b);
    int findLowerBound(int arr[], int size, int target);
    int findUpperBound(int arr[], int size, int target);
    int countElementsInRange(int sortedArray[], int size, int left, int right);
    bool checkInterval(int sortedArray[], int size, int E, int Y, int X);
    int removeDuplicates(int arr[], int size);
    bool needsImprovement(int numbers[], int N, int X, int Y);
};