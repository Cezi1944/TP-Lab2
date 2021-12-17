#include "STUDENT.h"
STUDENT::STUDENT() {
	Fio = "None";
	for (int i=0; i < 5;i++)
		Ap[i] = 0;
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
int STUDENT::getAp(int n) {
	return Ap[n];
}
void STUDENT::setAp(int n, int NewNum) {
	Ap[n] = NewNum;
}