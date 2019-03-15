#include<iostream>
#include<conio.h>
#define Info SinhVien
using namespace std;

typedef struct SinhVien{ //Dinh nghia doi tuong
	int MaSV;
	char HoTen[25];
	char GioiTinh[10];
	int Tuoi;	
};

typedef struct Node{ //Dinh nghia 1 Node trong DSLK
	Info Data;
	Node *Next;
}Node;

typedef struct List{ // Dinh nghia 1 DSLK
	Node *Head;
	Node *Last;
};

typedef struct Node *pNode; //Dinh nghia con tro Node
typedef struct List *pList; //Dinh nghia con tro List

void Init(pList l) //khoi tao DSLK rong
{
	l->Head = NULL;
	l->Last = NULL;
}

Info InputData()
{
	Info a;
	cin >> a.MaSV;
	cin >> a.HoTen;
	cin >> a.GioiTinh;
	cin >> a.Tuoi;
	return a;
}

void OutputData(Info a)
{
	cout << a.MaSV << " " << a.HoTen << " " << a.GioiTinh << " " << a.Tuoi;
}

pNode getNode(Info a){ //Ham tao 1 Node tu thanh phan Info a
	pNode p = new Node();
	if(p==NULL){
		cout << "Bo nho day!";
		return NULL;
	}
	else{
		p->Data = a;
		p->Next = NULL;
		return p;
	}
}

bool isEmpty(List l)
{
	return l.Head == NULL;
}

bool InsertHead(pList l, pNode p)// Ham chen dau
{
	if(p == NULL){ // Bo nho day
		return false;
	}
	else
	{
		if(isEmpty(*l)) // Neu DS Rong
		{
			l->Head = p;
		}
		else
		{
			p->Next = l->Head;
			l->Head = p;			
		}
		return true;
	}	
}


bool InsertLast(pList l, pNode p)// Ham chen cuoi
{
	if(p==NULL){ //Bo nho day
		return false;
	}
	else
	{
		if(isEmpty(*l))
		{
			l->Head = p;
			l->Last = p;
		}
		else
		{
			l->Last->Next = p;
			l->Last = p;
		}
		return true;		
	}
}

bool Push(pList l, pNode p) //Ham Push cua Stack
{
	return InsertHead(l, p);
}

bool EnQueue(pList l, pNode p) //Ham EnQueue cua Queue
{
	return InsertLast(l, p);
}

bool getHead(pList l, pNode *p) //Ham lay vi tri dau tien, va xoa no khoi List
{
	if(isEmpty(*l))
	{
		return false;
	}
	else
	{
		*p = l->Head;
		l->Head = l->Head->Next;
		return true;	
	}
}

bool Pop(pList l, pNode *p)
{
	return getHead(l, p);
}

bool DeQueue(pList l, pNode *p)
{
	return getHead(l, p);
}

int main(){
	List l;
	Init(&l);	
	
	EnQueue(&l, getNode(InputData()));
	EnQueue(&l, getNode(InputData()));
	EnQueue(&l, getNode(InputData()));
	
	pNode p;
	DeQueue(&l, &p);
	OutputData(p->Data);
	DeQueue(&l, &p);
	OutputData(p->Data);
	DeQueue(&l, &p);
	OutputData(p->Data);
	
	
	
	getch();
}
