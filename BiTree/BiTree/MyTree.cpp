#include<iostream>
#include<conio.h>

using namespace::std;

class Node
{
public:
	int date = 0;
	Node*lchild;
	Node*rchild;
};

class SearchTree
{
public:
	SearchTree(int*s,int lenth);
	bool Insert_Key(int key);
	bool Find_Key(int key, Node**ptr, Node**parent, Node**current);
private:
	Node*Root;
};

SearchTree::SearchTree(int *s, int lenth)
{
	for (int i = 0; i < lenth; i++)
		Insert_Key(s[i]);
	cout << "compelet!" << endl;
}

bool SearchTree::Find_Key(int key, Node**ptr, Node**parent, Node**current)
{
	if (*ptr == NULL)
	{
		if (parent==NULL)
		current = parent;//返回该节点的父节点
		else
		{
			*current = new Node();
			*current = *parent;
		}
		return false;
	}
	else if (key==(*ptr)->date)
	{
		*current = *ptr;
		return true;
	}
	else if (key < (*ptr)->date)
	{
		Find_Key(key, &(*ptr)->lchild, ptr, current);//左节点小于右节点
	}
	else
	{
		Find_Key(key, &(*ptr)->rchild, ptr, current);
	}
}

bool SearchTree::Insert_Key(int key)
{
	Node *current=NULL;
	bool status=Find_Key(key, &Root, NULL, &current);
	if (status)
	{
		return false;//已经有该键值了
	}
	else
	{
		if (current == NULL)
		{
			Root = new Node();
			Root->date = key;
			Root->lchild = NULL;
			Root->rchild = NULL;
		}
		else if (key<current->date)
		{
			current->lchild = new Node();
			current->lchild->date = key;
			current->lchild->lchild = NULL;
			current->lchild->rchild = NULL;
		}
		else
		{
			current->rchild = new Node();
			current->rchild->date = key;
			current->rchild->rchild = NULL;
			current->rchild->lchild = NULL;
		}
	}
}

int main()
{
	int s[10] = { 4, 2, 1, 5, 6, 3, 0, 7, 9, 8 };
	SearchTree x = SearchTree(s, 10);
	_getch();
}