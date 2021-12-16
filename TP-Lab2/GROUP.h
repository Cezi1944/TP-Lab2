#pragma once
#include <string>
#include "STUDENT.h"
class GROUP
{
	float AvScore;
	std::string* Subjects;
	STUDENT** Students;
	int SubN;
	int StudN;
public:
	GROUP();
	~GROUP();
	GROUP(GROUP* original);
	float getAvScore();
	void setAvScore(float NewAcScore);
	std::string getSubjects(int n);
	void setSubjects(int n, std::string NewSubject);
	STUDENT* getStudent(int n);
	void delStudent(int n);
};

