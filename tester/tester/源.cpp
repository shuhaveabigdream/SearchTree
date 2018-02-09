#include<iostream>
#include<conio.h>

using namespace::std;

void change(int**s)
{
	int tmp = 11;
	**s = tmp;
}

int main()
{
	int *s;
	change(&s);
	_getch();
}