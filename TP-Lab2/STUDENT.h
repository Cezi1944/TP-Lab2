#pragma once
#include <string>
class STUDENT
{
	std::string Fio;
	int Ap[5];
public:
	STUDENT();
	STUDENT(std::string NewFio,int NewAp[5]);
	~STUDENT();
	STUDENT(STUDENT* original);
	std::string getFio();
	void setFio(std::string NewFio);
	int getAp(unsigned int n);
	void setAp(unsigned int n, int NewNum);
};

