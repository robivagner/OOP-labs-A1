#include "Student.h"
#include <cstring>
void student::setName(const char s[])
{
	int final = 0;
	while (s[final])
	{
		final++;
	}
	for (int i = 0; i < final; i++)
		this->name[i] = s[i];
}
void student::getName(char s[])
{
	for (int i = 0; i < strlen(this->name); i++)
		s[i] = this->name[i];
}
void student::setGradeM(float value)
{
	this->gradeM = value;
}
float student::getGradeM()
{
	return this->gradeM;
}
void student::setGradeE(float value)
{
	this->gradeE = value;
}
float student::getGradeE()
{
	return this->gradeE;
}
void student::setGradeH(float value)
{
	this->gradeH = value;
}
float student::getGradeH()
{
	return this->gradeH;
}
float student::average()
{
	float g1, g2, g3;
	g1 = g2 = g3 = 0;
	g1 = getGradeM();
	g2 = getGradeH();
	g3 = getGradeE();
	float average = 0;
	average = (g1 + g2 + g3) / 3;
	return average;
}