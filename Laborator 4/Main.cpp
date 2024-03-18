#include <iostream>
#include "Sort.h"
#include <initializer_list>
int main()
{
    Sort s1(6, 7, 23);
    s1.InsertSort(false);
    s1.Print();
    Sort s2 = {6, 12, 10, 62, 30, 42};
    s2.BubbleSort(true);
    s2.Print();
    int v[] = { 10, 1, 5, 6, 4, 9, 15 };
    Sort s3(7, v);
    s3.BubbleSort();
    s3.Print();
    Sort s4(9, 12, 15, 6, 7, 10, 20, 32, 3, 2);
    s4.QuickSort(false);
    s4.Print();
    Sort s5("15,12,23,3,5,1,70,21");
    s5.BubbleSort();
    s5.Print();
    return 0;
}