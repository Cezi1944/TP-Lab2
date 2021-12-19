#pragma once
#include <string>
#include "STUDENT.h"
class GROUP
{
	int GroupNum;
	float AvScore;
	std::string** Subjects;
	STUDENT** Students;
	unsigned int SubN;
	unsigned int StudN;
	unsigned int MaxSubN;
	unsigned int MaxStudN;
public:
	GROUP();
	GROUP(int NewGroupNum,float NewAvScore,unsigned int NewMaxSubN,unsigned int NewMaxStudN);
	~GROUP();
	GROUP(GROUP* original);
	void setGroupNum(int NewNum);
	int getGroupNum();
	float getAvScore();
	void setAvScore(float NewAvScore);
	std::string getSubjects(unsigned int n);
	void setSubjects(unsigned int n, std::string NewSubject);
	STUDENT* getStudent(unsigned int n);
	void delStudent(unsigned int n);
	void delSubject(unsigned int n);
	void AddStudent(STUDENT* NewStudent, unsigned int n);
	void resize();
	void AddSubject(std::string NewSubject, unsigned int n);
	unsigned int getSubN();
	unsigned int getStudN();
	void calculateAvScore();
};

