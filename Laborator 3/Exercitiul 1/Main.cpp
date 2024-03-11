#include <iostream>
#include "Math.h"
int main()
{
    int a1, a2;
    a1 = Math::Add(12, 33);
    printf("Method 1: %d\n", a1);
    a2 = Math::Add(13, 2, 45);
    printf("Method 2: %d\n", a2);
    int b1, b2;
    b1 = Math::Add(2.3, 15.5);
    printf("Method 3: %f\n", b1);
    b2 = Math::Add(7.7, 23.1, 5.321);
    printf("Method 4: %f\n", b2);
    int c1, c2;
    c1 = Math::Mul(5, 13);
    printf("Method 5: %d\n", c1);
    c2 = Math::Mul(2, 13, 6);
    printf("Method 6: %d\n", c2);
    double d1, d2;
    d1 = Math::Mul(4.12, 5.2);
    printf("Method 7: %f\n", d1);
    d2 = Math::Mul(2.16, 5.2, 10.32);
    printf("Method 8: %f\n", d2);
    printf("Method 9: %d\n", Math::Add(4, 12, 5, 3, 24));
    char* str;
    str = Math::Add("132", "15");
    printf("Method 10: %s", str);
    return 0;
}