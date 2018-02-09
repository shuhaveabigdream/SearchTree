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
	SearchTree();
	void Ergodic();
	void Ergodic(Node*ptr);//遍历整个树
	bool Insert_Key(int key);
	bool Search_Key(int key, Node**current);//简化需要的参数更安全
	bool Remove_Key(int key);//去除一个键值
private:
    Node*Root;
	bool Find_Key(int key, Node**ptr, Node**parent, Node**current);//内部使用 用于查询节点
};

SearchTree::SearchTree()
{
	
}

SearchTree::SearchTree(int *s, int lenth)
{
	for (int i = 0; i < lenth; i++)
		Insert_Key(s[i]);
}

bool SearchTree::Find_Key(int key, Node**ptr=NULL, Node**parent=NULL, Node**current=NULL)
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

bool SearchTree::Search_Key(int key, Node**current)
{
	return Find_Key(key, &Root, NULL, current);
}

bool SearchTree::Remove_Key(int key)
{
	return true;
}

void SearchTree::Ergodic()
{
	Ergodic(Root);
}

void SearchTree::Ergodic(Node*ptr)
{
	if (ptr == NULL)
	{
		cout << "# ";
	}
	else
	{
		cout << ptr->date << " ";
		Ergodic(ptr->lchild);
		Ergodic(ptr->rchild);
	}
}

int main()
{
	int s[10] = { 4, 2, 1, 5, 6, 3, 0, 7, 9, 8 };
	SearchTree x = SearchTree(s, 10);
	x.Ergodic();

	_getch();
}