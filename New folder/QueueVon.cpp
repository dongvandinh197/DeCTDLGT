#include <conio.h>
#include <stdio.h>
#include <iostream>
#define Info SinhVien
#define MAX_SIZE 3
using namespace std;

typedef struct SinhVien //Dinh nghia doi tuong SV
{
	int MaSV;
	char HoTen[25];
	char GioiTinh[5];
	int Tuoi;
};

typedef struct Queue // Dinh nghia 1 Queue
{
	Info Data[MAX_SIZE];
	int f, l;
};

typedef struct Queue *pQueue; //Dinh nghia con tro Queue
typedef struct Info *pInfo; //Dinh nghia con tro Info

void Init(pQueue q)
{
	//f = (l+1)%MAX_SIZE
	q->f = 0;
	q->l = MAX_SIZE -1; 	
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

bool isEmpty(Queue q)
{
	return q.f == (q.l+1) % MAX_SIZE;
}

bool isFull(Queue q)
{
	return q.f == (q.l + 2)%MAX_SIZE;
}

bool EnQueue(pQueue q, Info a)
{
	if(isFull(*q)){
		return false;
	}
	else
	{
		q->l = (q->l + 1) % MAX_SIZE;
		q->Data[q->l] = a;
		return true;
	}
}

bool DeQueue(pQueue q, pInfo p)
{
	if(isEmpty(*q)){
		return false;
	}
	else
	{
		*p = q->Data[q->f];
		q->f = (q->f + 1)%MAX_SIZE;
		return true;
	}
}

int main()
{
	Queue q;
	Init(&q);
	if(EnQueue(&q, InputData()) == true) cout << "Them moi thanh cong";
	else cout << "Them moi that bai";
	if(EnQueue(&q, InputData()) == true) cout << "Them moi thanh cong";
	else cout << "Them moi that bai";
	Info p;
	DeQueue(&q, &p);
	OutputData(p);
	DeQueue(&q, &p);
	OutputData(p);
	
	if(EnQueue(&q, InputData()) == true) cout << "Them moi thanh cong";
	else cout << "Them moi that bai";
	if(EnQueue(&q, InputData()) == true) cout << "Them moi thanh cong";
	else cout << "Them moi that bai";
	getch();
	
}
