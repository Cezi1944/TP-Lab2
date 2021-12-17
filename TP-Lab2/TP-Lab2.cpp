#include <iostream>
#include "GROUP.h"
int main()
{
    
}
void sorting(GROUP** mass,int n) {
	int l = 0;
	int k = 0;
	int r = n - 1;
	int j = 0;
	GROUP* buf;
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