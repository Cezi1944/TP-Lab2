#include <iostream>
#include "GROUP.h"
#include <fstream>
using namespace std;
int deleteGroup(GROUP** mass, int n, int NumOfGroups);
unsigned int resize(GROUP** mass, unsigned int N, unsigned int MaxN);
void sorting(GROUP** mass, int n);
void changeStudent(STUDENT* student);
void ChangeGroup(GROUP* group);
void task2();
int main()
{
	unsigned int N = 0;
	unsigned int maxN = 8;
	GROUP** mass = (GROUP**)calloc(maxN, sizeof(GROUP*));
	STUDENT* NewStudent = NULL;
	STUDENT* StudCopy = NULL;
	GROUP* NewGroup = NULL;
	int choise = -1;
	unsigned int j=0;
	unsigned int l=0;
	unsigned int StudN=0;
	unsigned int marks[5] = { 0 };
	unsigned int i=0;
	string name;
	do {
		system("cls");

		cout << "1. Show list;" << endl;
		cout << "2. Delete object;" << endl;
		cout << "3. Add object;" << endl;
		cout << "4. Copy student;" << endl;
		cout << "5. Paste student;" << endl;
		cout << "6. Show subjects;" << endl;
		cout << "7. Show students with average academic performance more then 4.0;" << endl;
		cout << "8. Change info;" << endl;
		cout << "0. Exit." << endl;
		cout << "Do your choise:" << endl;
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
		}
		switch (choise)
		{
		case 0:
			break;
		case 1:
			if (N > 0) {
				system("cls");
				for (i = 0; i < N;i++) {
					StudN = mass[i]->getStudN();
					mass[i]->calculateAvScore();
					cout << mass[i]->getGroupNum() << " " << mass[i]->getAvScore() << endl;
					for (j = 0;j < StudN;j++)
					{
						cout << "\t" << mass[i]->getStudent(j)->getFio() << " " << mass[i]->getStudent(j)->AvScore()<<endl;
					}
				}
			}else
				cout << "There are no objects!" << endl;
			system("pause");
			break;
		case 2:
			if (N > 0) {
				do {
					system("cls");
					for (i = 0; i < N;i++) {
						cout << i + 1 << ". " << mass[i]->getGroupNum() << ";" << endl;
					}
					cout << "0. Exit." << endl;
					cout << "Select a group:" << endl;
					while (!(cin >> choise) || (cin.peek() != '\n'))
					{
						cin.clear();
						while (cin.get() != '\n');
						cout << "Invalid input!" << endl;
					}
					if (choise == 0)
						break;
					else if (choise > 0 && choise <= (int)N) {
						N = deleteGroup(mass, choise-1, N);
						StudCopy = NULL;
					}
					else {
						cout << "Invalid input!" << endl;
						system("pause");
					}
				} while (choise != 0);
			}
			else {
				cout << "There are no groups!" << endl;
				system("pause");
			}
			choise = -1;
			break;
		case 3:
			do {
				system("cls");
				cout << "1. Add new group;" << endl;
				cout << "2. Add new student;" << endl;
				cout << "0. Exit." << endl;
				cout << "Select an action." << endl;
				while (!(cin >> choise) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				switch (choise)
				{
				case 0:
					break;
				case 1:
					maxN = resize(mass, N, maxN);
					cout << "Enter position: ";
					while (!(cin >> j) || (cin.peek() != '\n'))
					{
						cin.clear();
						while (cin.get() != '\n');
						cout << "Invalid input!" << endl;
					}
					cout << "Enter group number: ";
					while (!(cin >> i) || (cin.peek() != '\n'))
					{
						cin.clear();
						while (cin.get() != '\n');
						cout << "Invalid input!" << endl;
					}
					NewGroup = new GROUP(i, 0.0, 8, 8);
					if (j < N) {
						for (unsigned int i = N;i > j;i--) {
							mass[i] = mass[i - 1];
						}
						mass[j] = NewGroup;
					}
					else if (j >= N) {
						mass[N] = NewGroup;
					}
					N++;
					sorting(mass, N);
					break;
				case 2:
					if (N > 0) {
						system("cls");
						for (i = 0; i < N;i++) {
							cout << i << ". " << mass[i]->getGroupNum() << ";" << endl;
						}
						cout << "Enter group number: ";
						while (!(cin >> j) || (cin.peek() != '\n') || (j>=N))
						{
							cin.clear();
							while (cin.get() != '\n');
							cout << "Invalid input!" << endl;
						}
						cout << "Enter position: ";
						while (!(cin >> l) || (cin.peek() != '\n'))
						{
							cin.clear();
							while (cin.get() != '\n');
							cout << "Invalid input!" << endl;
						}
						for (i = 0;i < 5;i++) {
							cout << "Enter "<< i+1 << " mark: ";
							while (!(cin >> marks[i]) || (cin.peek() != '\n'))
							{
								cin.clear();
								while (cin.get() != '\n');
								cout << "Invalid input!" << endl;
							}
							if (marks[i] > 5) {
								marks[i] = 5;
							}
						}

						cout << "Enter name of student: ";
						while (!(cin >>name) || (cin.peek() != '\n'))
						{
							cin.clear();
							while (cin.get() != '\n');
							cout << "Invalid input!" << endl;
						}
						NewStudent = new STUDENT(name, marks);
						mass[j]->AddStudent(NewStudent, l);
					}
					else {
						cout << "There are no objects!" << endl;
						system("pause");
					}
					break;
				default:
					break;
				}
			} while (choise != 0);
			choise = -1;
			break;
		case 4:
			if (N > 0) {
				system("cls");
				for (i = 0; i < N;i++) {
					cout << i << ". " << mass[i]->getGroupNum() << ";" << endl;
				}
				cout << "Enter group number: ";
				while (!(cin >> j) || (cin.peek() != '\n') || (j >= N))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				StudN = mass[j]->getStudN();
				if (StudN > 0) {
					for (i = 0;i < StudN;i++)
					{
						cout << "\t" << i << ". " << mass[j]->getStudent(i)->getFio() << " " << mass[j]->getStudent(i)->AvScore() << endl;
					}
					cout << "Select student: ";
					while (!(cin >> l) || (cin.peek() != '\n') || (l >= mass[j]->getStudN()))
					{
						cin.clear();
						while (cin.get() != '\n');
						cout << "Invalid input!" << endl;
					}
					StudCopy = mass[j]->getStudent(l);
				}
				else {
					cout << "There are no students!" << endl;
					system("pause");
				}
			}else {
				cout << "There are no groups!" << endl;
				system("pause");
			}

			break;
		case 5:
			if (StudCopy != NULL) {
				system("cls");
				for (i = 0; i < N;i++) {
					cout << i  << ". " << mass[i]->getGroupNum() << ";" << endl;
				}
				cout << "Enter group number: ";
				while (!(cin >> j) || (cin.peek() != '\n') || (j >= N))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				StudN = mass[j]->getStudN();
				for (i = 0;i < StudN;i++)
				{
					cout << "\t" << i << ". " << mass[j]->getStudent(i)->getFio() << " " << mass[j]->getStudent(i)->AvScore() << endl;
				}
				cout << "Enter position: ";
				while (!(cin >> l) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				mass[j]->AddStudent(new STUDENT(StudCopy), l);
			}
			else {
				cout << "The copy buffer is empty!" << endl;
				system("pause");
			}
			break;
		case 6:
			if (N > 0) {
				system("cls");
				for (i = 0; i < N;i++) {
					StudN = mass[i]->getSubN();
					cout << mass[i]->getGroupNum() << " " << mass[i]->getAvScore() << endl;
					for (j = 0;j < StudN;j++)
					{
						cout << "\t" << mass[i]->getSubjects(j) << endl;
					}
				}
			}else
				cout << "There are no objects!" << endl;
			system("pause");
			break;
		case 7:
			if (N > 0) {
				l = 0;
				for (i = 0; i < N;i++) {
					StudN = mass[i]->getStudN();

					for (j = 0;j < StudN;j++)
					{
						if (mass[i]->getStudent(j)->AvScore() > 4.0) {
							cout << "\t" << mass[i]->getStudent(j)->getFio() << " " << mass[i]->getStudent(j)->AvScore() << endl;
							l++;
						}
					}
				}
				if (l == 0) {
					cout << "There are no students with average academic performance more then 4.0!" << endl;
					system("pause");
				}
			}else
				cout << "There are no objects!" << endl;
			system("pause");
			break;
		case 8:
			system("cls");
			for (i = 0; i < N;i++) {
				cout << i << ". " << mass[i]->getGroupNum() << ";" << endl;
			}
			cout << "Enter group number: ";
			while (!(cin >> j) || (cin.peek() != '\n') || (j >= N))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			ChangeGroup(mass[j]);
			break;
		default:
			cout << "Wrong choise!" << endl;
			break;
		}
	} while (choise != 0);
	for (i = 0;i < N;i++)
		delete mass[i];
	free(mass);
	task2();
}
void sorting(GROUP** mass,int n) {
	n -= 1;
	int l = 1;
	int k = 0;
	int r = n;
	int j = 0;
	GROUP* buf;
	if (n > 1) {
		do
		{
			for (j = r;j >= l;j--)
				if (mass[j - 1]->getGroupNum() > mass[j]->getGroupNum())
				{
					buf = mass[j - 1];
					mass[j - 1] = mass[j];
					mass[j] = buf;
					k = j;
				}
			l++;
			for (j = l;j <= r;j++)
				if (mass[j - 1]->getGroupNum() > mass[j]->getGroupNum())
				{
					buf = mass[j - 1];
					mass[j - 1] = mass[j];
					mass[j] = buf;
					k = j;
				}
			r--;
		} while (l < r);
	}else if (n==1)
		if (mass[n]->getGroupNum() < mass[n - 1]->getGroupNum()) {
			buf = mass[n];
			mass[n] = mass[n - 1];
			mass[n - 1] = buf;
		}
}
unsigned int resize(GROUP** mass, unsigned int N, unsigned int MaxN) {
	if (N == MaxN) {
		MaxN *= 2;
		GROUP** buf = (GROUP**)realloc(mass, MaxN * sizeof(GROUP*));
		free(mass);
		mass = buf;
	}
	return MaxN;
}
int deleteGroup(GROUP** mass, int n,int NumOfGroups) {
	int choise;
	unsigned int i;
	do {
		system("cls");
		cout << mass[n]->getGroupNum() << endl;
		for (i = 0; i < mass[n]->getStudN();i++) {
			cout << i + 1 << ". " << mass[n]->getStudent(i)->getFio() << ";" << endl;
		}
		i++;
		cout << i << ". Delete group;" << endl;
		cout << "0. Exit." << endl;
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
		}
		if (choise == 0)
			break;
		else if (choise > 0 && choise <= (int)mass[n]->getStudN()) {
			mass[n]->delStudent(choise-1);
		}
		else if (choise == mass[n]->getStudN()+1) {
			if (n < NumOfGroups) {
				delete mass[n];
				for ( i = n + 1;(int)i < NumOfGroups;i++)
					mass[i - 1] = mass[i];
				mass[NumOfGroups - 1] = NULL;
				NumOfGroups--;
				break;
			}
		}
		else
			cout << "Wrong choise!" << endl;
	} while (choise != 0);
	return NumOfGroups;
}
void ChangeGroup(GROUP* group) {
	int choise = -1;
	unsigned int n = 0;
	unsigned int position = 0;
	string name = "";
	int in = 0;
	int i = 0;
	do {
		system("cls");
		cout << "1. Change group number;" << endl;
		cout << "2. Add subject;" << endl;
		cout << "3. Delete subject;" << endl;
		cout << "4. Change student info;" << endl;
		cout << "0. Exit;" << endl;
		cout << "Select an action:" << endl;
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
		}
		switch (choise)
		{
		case 0:
			break;
		case 1:
			cout << "Enter the group number:";
			while (!(cin >> in) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			group->setGroupNum(in);
			cout << "Group number changed!" << endl;
			system("pause");
			choise = -1;
			break;
		case 2:
			cout << "Enter position:";
			while (!(cin >> position) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			cout << "Enter the name of subject:";
			while (!(cin >> name) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			group->AddSubject(name, position);
			cout << "Subject added!" << endl;
			system("pause");
			choise = -1;
			break;
		case 3:
			n = group->getSubN();
			for (i = 0; i <(int) n;i++) {
				cout << i << ". " << group->getSubjects(i) << endl;
			}
			cout << "Select subject number:";
			while (!(cin >> position) || (cin.peek() != '\n') || (position >= n))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			group->delSubject(position);
			choise = -1;
			break;
		case 4:
			n = group->getStudN();
			if (n > 0) {
				for (i = 0; i <(int) n;i++) {
					cout << i << ". " << group->getStudent(i)->getFio() << endl;
				}
				cout << "Select student number:";
				while (!(cin >> position) || (cin.peek() != '\n') || (position>=n))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				if (position < n) {
					changeStudent(group->getStudent(position));
				}
			}
			else {
				cout << "There are no students!" << endl;
				system("pause");
			}

			choise = -1;
			break;
		default:
			break;
		}
	} while (choise != 0);
}
void changeStudent(STUDENT* student) {
	int choise = -1;
	unsigned int n = 0;
	unsigned int marks[5] = { 0 };
	int i = 0;
	string name = "";
	do {
		system("cls");
		cout << "1. Change student name;" << endl;
		cout << "2. Change marks;" << endl;
		cout << "0. Exit;" << endl;
		cout << "Select an action:" << endl;
		while (!(cin >> choise) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
		}
		switch (choise)
		{
		case 0:
			break;
		case 1:
			cout << "Current full name: " << student->getFio() << endl;
			cout << "Enter a new full name: ";
			while (!(cin >> name) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Invalid input!" << endl;
			}
			student->setFio(name);
			cout << "Student full name changed!" << endl;
			choise = -1;
			system("pause");
			break;
		case 2:
			cout << "Current marks: ";
			for (i = 0;i < 5;i++)
				cout << " " << student->getAp(i);
			cout << endl;
			cout << "Enter a new marks. "<< endl;
			for (i = 0;i < 5;i++) {
				cout << "Enter " << i + 1 << " mark: ";
				while (!(cin >> marks[i]) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Invalid input!" << endl;
				}
				if (marks[i] > 5) {
					marks[i] = 5;
				}
			}
			for(i = 0;i<5;i++)
				student->setAp(i,marks[i]);
			cout << "Student marks changed!" << endl;
			system("pause");
			choise = -1;
			break;
		default:
			break;
		}
	} while (choise != 0);
}
void task2() {
	ifstream in;
	string s1="";
	string s2="";
	in.open("D:\\учёба\\Третий курс\\TP\\TP-Lab2\\test.txt");
	int i = 1;
	if (in.is_open()) {
		while (!in.eof()) {
			if ((i % 2) == 1)
				in >> s1;
			else {
				in >> s2;
				cout << " " << s2 << " " << s1;;
				s1 = "";
			}
			i++;
		}
		if (s1 != "") {
			cout << " " << s1 << endl;
		}
	}else {
		cout << "File is not opened!" << endl;
	}
	in.close();
}