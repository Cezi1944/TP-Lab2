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
	int MaxSubN;
	int MaxStudN;
public:
	GROUP();
	~GROUP();
	GROUP(GROUP* original);
	float getAvScore();
	void setAvScore(float NewAvScore);
	std::string getSubjects(unsigned int n);
	void setSubjects(unsigned int n, std::string NewSubject);
	STUDENT* getStudent(unsigned int n);
	void delStudent(unsigned int n);
};

