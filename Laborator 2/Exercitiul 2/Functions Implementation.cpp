#include "Student.h"
#include "Functions.h"
#include <cstring>
int compareName(student* p, student* q)
{
	char nume1[10], nume2[10];
	p->getName(nume1);
	q->getName(nume2);
	for (int i = 0; i < strlen(nume1) && i < strlen(nume2); i++)
		if (nume1[i] < nume2[i]) return -1;
		else if (nume1[i] > nume2[i]) return 1;
	return 0;
}
int compareGradeM(student* p, student* q)
{
	float a, b;
	a = p->getGradeM();
	b = q->getGradeM();
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}
int compareGradeH(student* p, student* q)
{
	float a, b;
	a = p->getGradeH();
	b = q->getGradeH();
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}
int compareGradeE(student* p, student* q)
{
	float a, b;
	a = p->getGradeE();
	b = q->getGradeE();
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}
int compareAverage(student* p, student* q)
{
	float a, b;
	a = p->average();
	b = q->average();
	if (a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}