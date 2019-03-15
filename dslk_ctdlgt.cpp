#include<stdio.h>
#include<conio.h>
#include<iostream>
#define Info int

typedef struct NODE{
	Info Data;
	NODE * Next;
};

typedef struct List{
	NODE *pHead;
	NODE *pTail;
};

typedef struct NODE* pNode;
typedef struct List* pList;

void Init(pList L)
{
	L->pHead=L->pTail=NULL;
}

NODE* GetNode(Info a)
{
	pNode p = new NODE;
	if( p == NULL)
	{
		printf("Khong the cap phat bo nho!");
	}
	else
	{
		p->Data = a ;// luu a vao data
		p->Next = NULL;//lien ket du lieu
		return p;
	}
}
bool isEmpty(List L)
{
	return L.pHead==NULL;
}
bool AddHead ( pList L, pNode p)
{
	if(isEmpty(*L))
	{
		L->pHead=L->pTail=p;
		return false;
	}
	else
	{
		p->Next=L->pHead;
		L->pHead=p;
		return true;
	}
}
bool AddTail(pList L,pNode p)
{
	if(isEmpty(*L))
	{
		L->pHead=L->pTail=p;
		return false;
	}
	else
	{
		L->pTail->Next=p;
		L->pTail=p;
		return true;
	}
}


void InputList(pList L,int n)
{
	
	for(int i=1;i<=n;i++)
	{
		Info x;
		printf("\nNhap data : ");
		scanf("%d",&x);
		pNode p=GetNode(x);
		AddTail(L,p);
	}
}
void DisPlay(List L)
{
	for(pNode p=L.pHead;p!=NULL;p=p->Next)
	{
		printf("%4d",p->Data);
	}
}
void HoanVi(Info &a,Info &b)
{
	Info temp;
	temp=a;
	a=b;
	b=temp;
}
void Sort(List L)
{
	for( pNode p=L.pHead;p!=L.pTail;p=p->Next)
	{
		for(pNode q=p->Next;q!=NULL;q=q->Next)
		{
			if(p->Data > q->Data)
			{
				HoanVi(p->Data,q->Data);
			}
		}
	}
}
int Sum(List L)
{
	Info sum=0;
	for(pNode p=L.pHead;p!=NULL;p=p->Next)
	{
		sum+=p->Data;
	}
	return sum;
}
void InsertAfter(pList L, pNode p, pNode q)//them not p vao sau not q
{
	for(pNode k=L->pHead;k!=NULL;k=k->Next)
	{
		if(k->Data ==q->Data)
		{
			pNode G=k->Next;
			k->Next=p;
			p->Next=G;
			return;// ket thuc
			
		}
	}
}
int Max(List L)
{
	Info max=L.pHead->Data;
	for(pNode p=L.pHead;p!=NULL;p=p->Next)
	{
		if(p->Data  > max)
		{
			max=p->Data;
		}
	}
	return max;
}
int main ( )
{
	int n;
	printf("\nNhap so phan tu : ");scanf("%d",&n);
	List A;
	Init(&A);
	InputList(&A,n);
	DisPlay(A);
	Sort(A);
	printf("\nDanh sach sau khi sap xep la: ");
	DisPlay(A);
	printf("\nTong cac phan tu cua danh sach la : %d",Sum(A));
	printf("\nPhan tu max trong mang la: %d",Max(A));
	Info p,q;
	printf("\nNhap q:");scanf("%d",&q);
	pNode Q=GetNode(q);
	printf("\nNhap p: ");scanf("%d",&p);
	pNode P=GetNode(p);
	InsertAfter(&A,P,Q);
	DisPlay(A);
	
}
