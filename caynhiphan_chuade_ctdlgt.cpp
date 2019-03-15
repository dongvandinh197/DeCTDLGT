#include<iostream>
#include<conio.h>
#define Info int
using namespace std;

typedef struct NODE{
	Info Data;
	NODE *pLeft,*pRight;
};
typedef struct Tree{
	NODE *Root;
};
typedef struct NODE *pNode;
typedef struct Tree *pTree;
void Init(pTree t)
{
	t->Root=NULL;
}
NODE * GetNode(Info a)
{
	pNode p =new NODE;
	if(p==NULL)
	{
		cout<<"\nBo nho day !";
	}
	else{
		p->Data=a;
		p->pLeft=NULL;
		p->pRight=NULL;
		return p;
	}
}
bool InsertTree(pNode &t,pNode p)
{
	if(p==NULL)return false;
	else {
		if(t==NULL)
		{
			t=p;
		}
		else {
			if(t->Data == p->Data ) return false;
			if(t->Data > p->Data && t->pLeft==NULL)
			{
				t->pLeft=p;
				return true;
			}
			if(t->Data < p->Data && t->pRight ==NULL)
			{
				t->pRight=p;
				return true;
			}
			if(t->Data > p->Data && t->pLeft!= NULL)
			{
				return InsertTree(t->pLeft,p);
			}
			if(t->Data < p->Data && t->pRight!= NULL)
			{
				return InsertTree(t->pRight,p);
			}
		}
	}
}
void LNR(pNode t)
{
	if(t==NULL) return;
	else{
		LNR(t->pLeft);
		cout<<t->Data <<"  ";
		LNR(t->pRight);
	}
}
int DemChieuCao(pNode t)
{
	if(t==NULL) return 0;
	else{
		int left=DemChieuCao(t->pLeft);
		int right=DemChieuCao(t->pRight);
	}
	return (left > right ?left:right) + 1;
}
void Nhap (pTree t,int n)
{
	for(int i=0;i<n;i++)
	{
		Info x;
		cout<<"\nNhap vao gia tri: ";
		cin>>x;
		pNode p =GetNode(x);
		InsertTree(t->Root,p);
	}
}
NODE*  TimKiem(pNode t,Info x)
{
	if(t!=NULL)
	{
		if(t->Data == x)
		{
			pNode p = t;
			return p;
		}
		if(t->Data >x) return TimKiem(t->pLeft,x);
		if(t->Data < x) return TimKiem(t->pRight,x);
	}
	return NULL;
}
void XoaNode(pNode t,Info x)
{
	// trc tien xoa cac node co 1 con va cac node la.
	if(t==NULL)
	{
		return;
	}
	if(t->data >x) XoaNode(t->left,x);
	else if(t->data <x)XoaNode(t->right,x);
	else {//t->data=x;
		NODE *q=t;
		if(t->pLeft ==NULL)
		{
			t=t->pRight;
		}
		else if(t->pRight==NULL)
		{
			t=t->pLeft;
		}
		delete q;
	}
}
int main(){
	Tree t;
	Init(&t);
	int n;
	cout<<"\nNhap n : ";
	cin>>n;
	Nhap(&t,n);
	LNR(t.Root);
	getch();
	return 0;
}
