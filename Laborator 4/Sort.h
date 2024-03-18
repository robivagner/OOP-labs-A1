#pragma once
#include <initializer_list>
class Sort
{
    int* x, n;
public:
    Sort(int count, int minv, int maxv);
    Sort(std::initializer_list<int> list);
    Sort(int count, int v[]);
    Sort(int count, ...);
    Sort(const char* s);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};