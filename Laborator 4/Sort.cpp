#include "Sort.h"
#include <time.h>
#include <iostream>
#include <cstdarg>
#include <cstring>
Sort::Sort(int count, int minv, int maxv)
{
	this->x = new int[count];
	this->n = count;
	srand(time(0));
	for (int i = 0; i < count; i++)
		this->x[i] = minv + rand() % (maxv - minv + 1);
}
Sort::Sort(std::initializer_list<int> list)
{
	this->n = list.size();
	this->x = new int[this->n];
	int i = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
		this->x[i++] = *it;
}
Sort::Sort(int count, int v[])
{
	this->x = new int[count];
	this->n = count;
	for (int i = 0; i < count; i++)
		this->x[i] = v[i];
}
Sort::Sort(int count, ...)
{
	va_list list;
	va_start(list, count);

	this->x = new int[count];
	this->n = count;
	for (int i = 0; i < count; i++)
		this->x[i] = va_arg(list, int);

	va_end(list);
}
Sort::Sort(const char* s)
{
	int index = 0;
	char* num;

	int k = 0;
	while (s[k] != ',') k++;
	num = new char[k + 1];
	int length = 0;

	int count = 1;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ',') count++;
	this->x = new int[count];
	this->n = count;

	int i = 0;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] != ',') num[length++] = s[i];
		else {
			num[length] = '\0';
			int nr = 0;
			for (int j = 0; j < length; j++)
				nr = nr * 10 + (num[j] - '0');
			this->x[index++] = nr;
			length = 0;
			k = i + 1;
			while (s[k] != ',' && s[k] != '\0') k++;
			delete[] num;
			num = new char[k - i];
		}
	}
	num[length] = '\0';
	int nr = 0;
	for (int j = 0; j < length; j++)
		nr = nr * 10 + (num[j] - '0');
	delete[] num;
	this->x[index] = nr;
}
Sort::~Sort()
{
	delete[] this->x;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < GetElementsCount(); i++)
	{
		int key = this->x[i];
		int j = i - 1;

		while (j >= 0 && ((ascendent && this->x[j] > key) || (!ascendent && this->x[j] < key)))
		{
			this->x[j + 1] = this->x[j];
			j = j - 1;
		}
		this->x[j + 1] = key;
	}
}
int partition(int* a, int low, int high, bool ascendent)
{
	int pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high; j++)
	{
		if ((ascendent && a[j] < pivot) || (!ascendent && a[j] > pivot))
		{
			i++;
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}
	int aux = a[i + 1];
	a[i + 1] = a[high];
	a[high] = aux;
	return (i + 1);
}
void quickSort(int* a, int low, int high, bool ascendent)
{
	if (low < high)
	{

		int p = partition(a, low, high, ascendent);

		quickSort(a, low, p - 1, ascendent);
		quickSort(a, p + 1, high, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(this->x, 0, this->n - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < GetElementsCount(); i++)
		for (int j = i + 1; j < GetElementsCount(); j++)
			if ((ascendent && this->x[i] > this->x[j]) || (!ascendent && this->x[i] < this->x[j]))
			{
				int aux = this->x[i];
				this->x[i] = this->x[j];
				this->x[j] = aux;
			}
}
void Sort::Print()
{
	for (int i = 0; i < GetElementsCount(); i++)
		printf("%d ", this->x[i]);
	printf("\n");
}
int Sort::GetElementsCount()
{
	return this->n;
}
int Sort::GetElementFromIndex(int index)
{
	return this->x[index];
}