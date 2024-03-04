#pragma once
class student {
	char name[10];
	float gradeM, gradeH, gradeE;
public:
	void setName(const char s[]);
	void getName(char s[]);
	void setGradeM(float value);
	float getGradeM();
	void setGradeE(float value);
	float getGradeE();
	void setGradeH(float value);
	float getGradeH();
	float average();
};