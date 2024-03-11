#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstring>
#include <cstdarg>
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	va_list list;
	va_start(list, count);

	int sum = 0;

	for (int i = 0; i < count; i++)
		sum += va_arg(list, int);

	va_end(list);

	return sum;
}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	int a1, b1, na, nb;
	a1 = b1 = na = nb = 0;
	int i = 0;
	while (a[i])
	{
		na++;
		i++;
	}
	for (int i = 0; i < na; i++)
		a1 = a1 * 10 + (a[i] - '0');
	i = 0;
	while (b[i])
	{
		nb++;
		i++;
	}
	for (int i = 0; i < nb; i++)
		b1 = b1 * 10 + (b[i] - '0');
	a1 = a1 + b1;
	int nstr = 0;
	b1 = a1;
	while (b1)
	{
		nstr++;
		b1 /= 10;
	}
	char* str = new char[nstr];
	for (int i = nstr - 1; i >= 0; i--)
	{
		str[i] = (char)(a1 % 10 + '0');
		a1 /= 10;
	}
	str[nstr] = '\0';
	return str;
}