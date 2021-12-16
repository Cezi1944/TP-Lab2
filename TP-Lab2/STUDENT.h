#pragma once
#include <string>
class STUDENT
{
	std::string Fio;
	int Ap[5];
public:
	STUDENT();
	~STUDENT();
	STUDENT(STUDENT* original);
	std::string getFio();
	void setFio(std::string NewFio);
	int getAp(int n);
	void setAp(int n, int NewNum);
};

