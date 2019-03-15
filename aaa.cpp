#include<iostream>
#include<conio.h>
#define Info int
#define MAX_SIZE 100
using namespace std;
typedef struct Queue{
	Info Data[MAX_SIZE];
	int Front,Rear;
};
typedef struct Queue *pQueue;

void Init(pQueue q)
{
	q->Front=0;
	q->Rear=MAX_SIZE -1;
}
bool Isempty(Queue q)
{
	return q.Front==(q.Rear+1) % MAX_SIZE;
}
bool Isfull(Queue q)
{
	return q.Front==(q.Rear +2) % MAX_SIZE;
}

bool Enqueue(pQueue q, Info a)
{
	if(Isfull(*q))
	{
		cout<<"\nHang doi day !";
		return false;
	}
	else{
		q->Rear=(q->Rear+1) %MAX_SIZE;
		q->Data[q->Rear]=a;
		return true;
	}
}
bool Dequeue(pQueue q,Info *p)
{
	if(Isempty(*q))
	{
		cout<<"\nNgan xep rong !";
		return false;
	}
	else {
		*p=q->Data[q->Front];
		q->Front=(q->Front +1 )% MAX_SIZE;
		return true;
	}
}
int main()
{
	Queue q;
	Init(&q);
	int n;
	cout<<"\nNhap n : ";
	cin>>n;
	int t,s=0;
	t=n;
	while(t>0)
	{
		Enqueue(&q,t%10);
		t=t/10;
	}
	while(Isempty(q)==false)
	{
		Info x;
		Dequeue(&q,&x);
		s+=x;
	}
	cout<<s;

	
}
