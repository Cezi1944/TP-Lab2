#include "STUDENT.h"
STUDENT::STUDENT() {
	Fio = "None";
	for (int i=0; i < 5;i++)
		Ap[i] = 0;
}
STUDENT::STUDENT(std::string NewFio, unsigned int NewAp[5]) {
	Fio = NewFio;
	for (int i=0; i < 5;i++)
		Ap[i] = NewAp[i];
}
STUDENT::~STUDENT() {
}
STUDENT::STUDENT(STUDENT* original) {
	Fio = original->Fio;
	for (int i=0; i < 5;i++)
		Ap[i] = original->Ap[i];
}
std::string STUDENT::getFio() {
	return Fio;
}
void STUDENT::setFio(std::string NewFio) {
	Fio = NewFio;
}
int STUDENT::getAp(unsigned int n) {
	if (n < 5)
		return Ap[n];
	else
		return 0;
}
void STUDENT::setAp(unsigned int n, int NewNum) {
	if (n < 5)
		Ap[n] = NewNum;
}
float STUDENT::AvScore() {
	return ((float)(Ap[0] + Ap[1] + Ap[2] + Ap[3] + Ap[4]) / 5);
}