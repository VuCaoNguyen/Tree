#include <iostream>
using namespace std;

struct Node
{
	int Data;
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE *Tree;

void InIt(Tree &root)
{
	root = NULL;
		
}

Node* CreateNode(int x)
{
	NODE *p = new NODE;
	if (p != NULL)
	{
		p->Data = x; p->pLeft = NULL; p->pRight = NULL;
	}
	return p;
}