//#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node
{
	int Data;
	struct Node *pLeft;
	struct Node *pRight;
};
typedef Node *Tree;


Node* CreateNode(int x)
{
	Node *p = new Node;
	if (p != NULL)
	{
		p->Data = x; p->pLeft = NULL; p->pRight = NULL;
	}
	return p;
}
void InIt(Tree &root)
{
	root = NULL;
}


Tree AddVDTree()
{
	Tree root;
	InIt(root);
	Node *a, *b, *c, *d, *e, *f, *g, *h;
	a = CreateNode(8);
	b = CreateNode(10);
	c = CreateNode(7);
	d = CreateNode(1);
	e = CreateNode(2);
	f = CreateNode(5);
	g = CreateNode(9);
	h = CreateNode(6);
	if (a && b && c && d && e && f && g && h)
	{
		a->pLeft = b;		a->pRight = c;
		//Cay trai		
		b->pLeft = d;		b->pRight = e;		e->pRight = f;
		//Cay Phai;		
		c->pLeft = g;		g->pRight = h;
	}
	return root = a ;
}
void NLR(Tree root)
{
	if (root)
	{
		cout << root->Data << "\t";
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}


Tree CreateTree(int *pre, int *in, int m, int n, int k, int l) {
	int i;
	Tree root;
	if (l < k) return NULL;
	root = new Node;
	if (root != NULL) {
		root->Data = pre[m];
		for (i = k; i <= l; i++)
			if (in[i] == pre[m]) break;
		root->pLeft = CreateTree(pre, in, m + 1, n, k, i - 1);
		root->pRight = CreateTree(pre, in, m + i - k + 1, n, i + 1, l);
	} return root;
}
//------------------------------------------------------------
int main()
{
	int arr[] = { 8, 5, 2, 6, 1,7 ,10,12,13,15,18,21,17 };
	int  arr1[] = { 2,5,1,6,7,8,12,10,18,15,21,13,17 };

	Tree root;
	root = CreateTree(arr, arr1, 0, 12, 0, 12);
	NLR(root);
	system("pause");
	return 0;
}
