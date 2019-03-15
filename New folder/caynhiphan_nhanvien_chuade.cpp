#include<iostream>
#include<string>
#include<conio.h>
#define Info Nhanvien
using namespace std;

typedef struct Nhanvien{
	int manv;
	string ht,dc;
	int sdt,ngaycong,bacluong;
};
typedef struct NODE{
	Info Data;
	NODE *pLeft,*pRight;
};
typedef struct Tree{
	NODE *Root;
};
typedef struct NODE *pNode;
typedef struct Tree *pTree;

void Nhapnv(Nhanvien &a)
{
	cout<<"\nNhap ma nv : ";cin>>a.manv;
	cout<<"\nNhap ho ten : ";fflush(stdin);getline(cin,a.ht);
	cout<<"\nNhap dia chi : ";fflush(stdin);getline(cin,a.dc);
	cout<<"\nNhap So dien thoai : ";cin>>a.sdt;
	cout<<"\nNhap Ngay cong  : ";cin>>a.ngaycong;
	cout<<"\nNhap Bac luong : ";cin>>a.bacluong;
}
void Xuatnv(Nhanvien a)
{
	cout<<"\nma nv :"<<a.manv<<" ho ten: "<<a.ht<<" dia chi : "<<a.dc<<" sdt: "<<a.sdt<<" ngay cong: "<<a.ngaycong<<" bac luong: "<<a.bacluong;
}
void Init(pTree t)
{
	t->Root=NULL;
}
NODE* GetNode(Info x)
{
	pNode p=new NODE;
	if(p==NULL)
	{
		cout<<"\nBo nho day !";
	}
	else {
		p->Data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		return p;
	}
}
bool InsertTree(pNode &t,pNode p)
{
	if(p==NULL) return false;
	else{
		if(t==NULL) t=p;
		else {
			if(t->Data.manv == p->Data.manv) return false;
			if(t->Data.manv > p->Data.manv && t->pLeft==NULL)
			{
				t->pLeft=p;
				return true;
			}
			if(t->Data.manv < p->Data.manv && t->pRight==NULL)
			{
				t->pRight=p;
				return true;
			}
			if(t->Data.manv > p->Data.manv && t->pLeft!=NULL)
			{
				return InsertTree(t->pLeft,p);
			}
			if(t->Data.manv < p->Data.manv && t->pRight != NULL)
			{
				return InsertTree(t->pRight,p);
			}
		}
	}
}

NODE* Search(pNode t,int key)
{
	if(t!=NULL)
	{
		if(t->Data.manv == key)
		{
			pNode p=t;
			return p;
		}
		if(t->Data.manv < key)
		{
			return Search(t->pRight,key);
		} 
		if(t->Data.manv > key) 
		{
			return Search(t->pLeft,key);
		}
	}
	return t;
}
void LNR(pNode t)
{
	if(t==NULL) return;
	else {
		LNR(t->pLeft);
		Xuatnv(t->Data);
		LNR(t->pRight);
	}
}
void ChenCay(pTree t,int n)
{
	for(int i=0;i<n;i++)
	{
		Info x;
		Nhapnv(x);
		pNode p =GetNode(x);
		InsertTree(t->Root,p);
	}
}
int main(){
	
	Tree t;
	Init(&t);
	int n;
	cout<<"\nNhap n : ";
	cin>>n;
	ChenCay(&t,n);
	LNR(t.Root);
	int key;
	cout<<"\nNhap key : ";
	cin>>key;
	pNode q;
	q=Search(t.Root,key);
	if(q==NULL)
	{
		cout<<"\n khong Tim thay";
	}
	else {
		cout<<" tim thay!";
	}
	getch();
	return 0;
}
