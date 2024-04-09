#include <iostream>

float operator"" _Fahrenheit(unsigned long long int value)
{
    float res;
    res = (value - 32) / 1.8;
    return res;
}
float operator"" _Kelvin(unsigned long long int value)
{
    float res;
    res = value - 273.15;
    return res;
}
int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("Din Kelvin: %f\nDin Fahrenheit: %f", a, b);
    return 0;
}