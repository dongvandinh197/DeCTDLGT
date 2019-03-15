#include<iostream>
#include<conio.h>
#define Info Duan
#include<string>
using namespace std;

typedef struct Duan{
	string mada,tenda,kieuda;
	int kinhphi;
};
typedef struct NODE{
	Info Data;
	NODE *Next;
};
typedef struct List{
	NODE *pHead,*pTail;
};
typedef struct NODE *pNode;
typedef struct List *pList;
void Nhapda (Duan &a)
{
	cout<<"\nNhap ma du an : ";fflush(stdin);getline(cin,a.mada);
	cout<<"\nNhap ten du an : ";fflush(stdin);getline(cin,a.tenda);
	cout<<"\nNhap kieu du an : ";fflush(stdin);getline(cin,a.kieuda);
	cout<<"\nNhap kinh phi: ";cin>>a.kinhphi;
}
void Xuatda(Duan a)
{
	cout<<"\nMa du an: "<<a.mada<<" Ten du an: "<<a.tenda<<" Kieu du an :"<<a.kieuda<<" Kinh phi : "<<a.kinhphi;
}

NODE* Getnode(Info a)
{
	pNode p =new NODE;
	if(p==NULL)
	{
		cout<<"\nBo nho day!";
	}
	else{
		p->Data=a;
		p->Next=NULL;
		return p;
	}
}
void Init(pList l)
{
	l->pHead=l->pTail=NULL;
}
bool Isempty(List l)
{
	return l.pHead==NULL;
}
bool AddTail(pList l,pNode p)
{
	if(Isempty(*l))
	{
		l->pHead=l->pTail=p;
	}
	else{
		l->pTail->Next=p;
		l->pTail=p;
		return true;
	}
}
void InputList(pList l,int n)
{
	for(int i=0;i<n;i++)
	{
		Info x;
		Nhapda(x);
		pNode p =Getnode(x);
		AddTail(l,p);	
	}
}
void Duyet(List l)
{
	for(pNode p=l.pHead;p!=NULL;p=p->Next){
		Xuatda(p->Data);
	}
}
void Swap(Info &a,Info &b)
{
	Info c;
	c=a;
	a=b;
	b=c;
}
void Q_Sort(List l)
{
	for(pNode p=l.pHead;p!=l.pTail;p=p->Next)
	{
		for(pNode q=p->Next;q!=NULL;q=q->Next)
		{
			if(p->Data.kinhphi > q->Data.kinhphi)
			{
				Swap(p->Data,q->Data);
			}
		}
	}
}
int main()
{
	List l;
	Init(&l);
	int n;
	cout<<"\nNhap n: ";
	cin>>n;
	InputList(&l,n);
	for(int i=0;i<n;i++)
	{
		Duyet(l);
	}
	Q_Sort(l);
	for(int i=0;i<n;i++)
	{
		Duyet(l);
	}
	getch();
	return 0;
	
}
