#include<iostream>
#include<conio.h>
#include<string>
#define Info MatHang

using  namespace std;
typedef struct MatHang{
	string mahang, tenhang,nhomhang;
	int gia;
};
void NhapMH(MatHang &a)
{
	cout<<"\nNhap ma hang : ";fflush(stdin);getline(cin,a.mahang);
	cout<<"\nNhap ten hang : ";fflush(stdin);getline(cin,a.tenhang);
	cout<<"\nNhap nhom hang : ";;fflush(stdin);getline(cin,a.nhomhang);
	cout<<"\nNhap gia : ";cin>>a.gia;
	
}
void XuatMH(MatHang a)
{
	cout<<"\nMa hang : "<<a.mahang<<" Ten hang : "<<a.tenhang<<" Nhom hang : "<<a.nhomhang<<" Gia: "<<a.gia;
	
}


typedef struct NODE{
	Info Data;
	NODE *Next;
};
typedef struct List{
	NODE *pHead,*pTail;
};
typedef struct NODE *pNode;
typedef struct List *pList;

void Init(pList L)
{
	L->pHead=L->pTail=NULL;
}
NODE* GetNode(Info a)
{
	pNode p=new NODE;
	if(p==NULL)
	{
		cout<<"\nDay bo nho !";
		
	}
	else
	{
		p->Data=a;//gan du lieu
		p->Next=NULL;//Gan lien ket
		return p;
	}
}
bool Isempty(List L)
{
	return L.pHead==NULL;
}
bool InsertHead(pList L,pNode p)
{
	if(Isempty(*L))
	{
		L->pHead=L->pTail=p;
		return false;
	}
	else{
		p->Next=L->pHead;
		L->pHead=p;
		return true;
	}
}
bool InsertTail(pList L,pNode p)
{
	if(Isempty(*L))
	{
		L->pHead=L->pTail=p;
		return false;
	}
	else{
		L->pTail->Next=p;
		L->pTail=p;
		return true;
	}
}
void InputList(pList L,int n)
{
	for(int i=0;i<n;i++)
	{
		Info a;
		cout<<"\nNhap MH thu : "<<i+1<<endl;
		NhapMH(a);
		pNode p=GetNode(a);
		InsertHead(L,p);
		
	}
}
void Duyet(List L)
{
	for(pNode p=L.pHead;p!=NULL;p=p->Next)
	{
		XuatMH(p->Data);
	}
}
int main(){
	
	int n;
	cout<<"\nNhap n : ";
	cin>>n;
	List L;
	Init(&L);
	InputList(&L,n);
	Duyet(L);
	
	
	getch();
	return 0;
}
