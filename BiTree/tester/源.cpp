#include<iostream>
#include<conio.h>

using namespace::std;


class Node
{
public:
	int date;
	Node*next;
};

void ValuePtr(Node**tmp)
{
	Node *s=new Node();
	s->date = 20;
	s->next = NULL;
	*tmp = s;
}

int main()
{
	Node*ptr =new Node();
	ValuePtr(&ptr);
	_getch();
}