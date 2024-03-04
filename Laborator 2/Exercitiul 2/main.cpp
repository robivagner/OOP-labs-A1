#include <iostream>
#include "Student.h"
#include "Functions.h"
int main()
{
	student p;
	student q;
	p.setName("Marius");
	p.setGradeM(7);
	p.setGradeE(10);
	p.setGradeH(8);
	q.setName("Alex");
	q.setGradeM(9);
	q.setGradeE(9);
	q.setGradeH(8);
	printf("Name: %d \n", compareName(&p, &q));
	printf("Mathematics: %d \n", compareGradeM(&p, &q));
	printf("English: %d \n", compareGradeE(&p, &q));
	printf("History: %d \n", compareGradeH(&p, &q));
	printf("Average: %d \n", compareAverage(&p, &q));
	return 0;
}