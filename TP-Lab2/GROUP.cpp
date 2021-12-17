#include "GROUP.h"
GROUP::GROUP() {
	AvScore = 0;
	SubN = 0;
	MaxSubN = 8;
	StudN = 0;
	MaxStudN = 8;
	Subjects = (std::string*) calloc(MaxSubN,sizeof(std::string));
	Students = (STUDENT**)calloc(MaxStudN, sizeof(STUDENT*));
}
GROUP::~GROUP() {
	for (int i;i < StudN;i++)
		delete Students[i];
	free(Students);
	free(Subjects);
}
GROUP::GROUP(GROUP* original) {
	AvScore = original->AvScore;
	SubN = original->SubN;
	MaxSubN = original->MaxSubN;
	StudN = original->StudN;
	MaxStudN = original->MaxStudN;
	Subjects = (std::string*)calloc(MaxSubN, sizeof(std::string));
	Students = (STUDENT**)calloc(MaxStudN, sizeof(STUDENT*));
	for (int i=0;i < SubN;i++)
		Subjects[i] = original->Subjects[i];
	for (int i=0;i < StudN;i++) {
		Students[i] = new STUDENT();
		Students[i]->setFio(original->Students[i]->getFio());
		for (int j=0; j < 5;j++)
			Students[i]->setAp(j, Students[i]->getAp(j));
	}
	for (int i = 0;i < SubN;i++)
		Subjects[i] = original->Subjects[i];
}
float GROUP::getAvScore() {
	return AvScore;
}
void GROUP::setAvScore(float NewAvScore) {
	AvScore = NewAvScore;
}
std::string GROUP::getSubjects(unsigned int n){
	if (n < SubN)
		return Subjects[n];
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
		for (int i = n + 1;i < StudN;i++)
			Students[i - 1] = Students[i];
		Students[StudN - 1] = NULL;
		StudN--;
	}
}
