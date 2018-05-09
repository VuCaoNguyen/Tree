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
}Tree AddVDTree(){	Tree root;	InIt(root);	NODE *a, *b, *c, *d, *e, *f, *g, *h;	a = CreateNode(8);	b = CreateNode(10);	c = CreateNode(7);	d = CreateNode(1);	e = CreateNode(2);	f = CreateNode(5);	g = CreateNode(9);	h = CreateNode(6);	if (a && b && c && d && e && f && g && h)	{		//NODE Goc		a->pLeft = b;		a->pRight = c;		//Cay trai		b->pLeft = d;		b->pRight = e;		e->pRight = f;		//Cay Phai;		c->pLeft = g;		g->pRight = h;	}	return root;}void AddTree(Tree &List, int date){}void NLR(Tree root){	if (root)	{		cout << root->Data <<"\t";		NLR(root->pLeft);		NLR(root->pRight);	}}//------------------------------------------------------------int main(){	Tree root;	root = AddVDTree();	NLR(root);	system("pause");	return 0;}