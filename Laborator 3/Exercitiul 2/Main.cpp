#include <iostream>
#include "Canvas.h"
int main()
{
    Canvas p(25, 25);
    p.DrawCircle(12, 12, 6, 'a');
    p.SetPoint(0, 0, 'c');
    printf("Inceput:\n");
    p.Print();
    printf("Final\n");
    p.Clear();
    p.FillCircle(12, 12, 6, 'a');
    printf("Inceput:\n");
    p.Print();
    printf("Final\n");
    p.Clear();
    p.DrawRect(1, 2, 4, 6, 'a');
    p.FillRect(1, 2, 4, 6, 'b');
    p.SetPoint(3, 4, 'c');
    printf("Inceput:\n");
    p.Print();
    printf("Final\n");
    p.Clear();
    p.DrawLine(0, 0, 6, 2, 'a');
    printf("Inceput:\n");
    p.Print();
    printf("Final\n");
}