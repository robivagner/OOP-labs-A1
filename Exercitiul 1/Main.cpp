#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList p;
    p.Init();
    for (int i = 0; i < 10; i++)
        p.Add(10 - i);
    p.Sort();
    p.Print();
    return 0;
}
