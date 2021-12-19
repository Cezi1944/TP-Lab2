#include "GROUP.h"
#include <string>
GROUP::GROUP() {
	GroupNum = 0;
	AvScore = 0;
	SubN = 0;
	MaxSubN = 8;
	StudN = 0;
	MaxStudN = 8;
	Subjects = (std::string**) calloc(MaxSubN,sizeof(std::string*));
	Students = (STUDENT**)calloc(MaxStudN, sizeof(STUDENT*));
}
GROUP::GROUP(int NewGroupNum, float NewAvScore, unsigned int NewMaxSubN, unsigned int NewMaxStudN) {
	GroupNum = NewGroupNum;
	AvScore = NewAvScore;
	SubN = 0;
	MaxSubN = NewMaxSubN;
	StudN = 0;
	MaxStudN = NewMaxStudN;
	Subjects = (std::string**)calloc(MaxSubN, sizeof(std::string*));
	Students = (STUDENT**)calloc(MaxStudN, sizeof(STUDENT*));
}
GROUP::~GROUP() {
	for (unsigned int i = 0;i < StudN;i++)
		delete Students[i];
	for (unsigned int i = 0;i < SubN;i++)
		delete Subjects[i];
	free(Students);
	free(Subjects);
}
GROUP::GROUP(GROUP* original) {
	GroupNum = original->GroupNum;
	AvScore = original->AvScore;
	SubN = original->SubN;
	MaxSubN = original->MaxSubN;
	StudN = original->StudN;
	MaxStudN = original->MaxStudN;
	Subjects = (std::string**)calloc(MaxSubN, sizeof(std::string*));
	Students = (STUDENT**)calloc(MaxStudN, sizeof(STUDENT*));
	if (Subjects)
		for (unsigned int i=0;i < SubN;i++)
			Subjects[i] = original->Subjects[i];
	for (unsigned int i=0;i < StudN;i++) {
		if (Students) {
			Students[i] = new STUDENT();
			Students[i]->setFio(original->Students[i]->getFio());
			for (unsigned int j=0; j < 5;j++)
				Students[i]->setAp(j, Students[i]->getAp(j));
		}

	}

}
float GROUP::getAvScore() {
	return AvScore;
}
void GROUP::setAvScore(float NewAvScore) {
	AvScore = NewAvScore;
}
std::string GROUP::getSubjects(unsigned int n){
	if (n < SubN)
		return *Subjects[n];
	else
		return "";
}
void GROUP::setSubjects(unsigned int n, std::string NewSubject) {
	if (n < SubN)
		Subjects[n];
}
STUDENT* GROUP::getStudent(unsigned int n) {
	if (n < StudN)
		return Students[n];
	else
		return NULL;
}
void GROUP::delStudent(unsigned int n) {
	if (n < StudN) {
		delete Students[n];
		for (unsigned int i = n + 1;i < StudN;i++)
			Students[i - 1] = Students[i];
		Students[StudN - 1] = NULL;
		StudN--;
	}
}
void GROUP::AddStudent(STUDENT* NewStudent, unsigned int n) {
	this->resize();
	if (n < StudN) {
		for (unsigned int i = StudN;i > n;i--) {
			Students[i] = Students[i - 1];
		}
		Students[n] = NewStudent;
	}
	else if (n >= StudN) {
		Students[StudN] = NewStudent;
	}
	StudN++;
}
void GROUP::resize() {
	if (StudN == MaxStudN) {
		MaxStudN *= 2;
		STUDENT** buf = (STUDENT**)realloc(Students, MaxStudN*sizeof(STUDENT*));
		free(Students);
		Students = buf;
	}
	if (SubN == MaxSubN) {
		MaxSubN *= 2;
		std::string** buf = (std::string**)realloc(Subjects, MaxSubN * sizeof(std::string*));
		free(Subjects);
		Subjects = buf;
	}
}
void GROUP::setGroupNum(int NewNum) {
	GroupNum = NewNum;
}
int GROUP::getGroupNum() {
	return GroupNum;
}
void GROUP::AddSubject(std::string NewSubject, unsigned int n) {
	this->resize();
	if (n < SubN) {
		for (unsigned int i = SubN;i > n;i--) {
			Subjects[i] = Subjects[i - 1];
		}
		Subjects[n] = new std::string;
		*Subjects[n] = NewSubject;
	}
	else{
		Subjects[SubN] = new std::string;
		*Subjects[SubN] = NewSubject;
	}
	SubN++;
}
void GROUP::delSubject(unsigned int n) {
	if (n < SubN) {
		delete Subjects[n];
		for (unsigned int i = n+1;i < SubN;i++)
			Subjects[i-1] = Subjects[i];
		SubN--;
	}
}
unsigned int GROUP::getSubN() {
	return SubN;
}
unsigned int GROUP::getStudN() {
	return StudN;
}
void GROUP::calculateAvScore() {
	float NewAvScore = 0.0;
	for (int i = 0;i <(int) StudN;i++) {
		NewAvScore += Students[i]->AvScore();
	}
	if (StudN > 0)
		AvScore = NewAvScore / StudN;
	else
		AvScore = 0.0;
}