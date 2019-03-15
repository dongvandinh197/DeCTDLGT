#include<iostream>
#include<conio.h>
#define Info int
#define MAX_SIZE 100
using namespace std;

typedef struct Queue{
	int Front,Rear;
	Info Data[MAX_SIZE];
};
typedef struct Queue *pQueue;
void Init(pQueue q)
{
	q->Front=0;
	q->Rear=MAX_SIZE -1 ;
}
bool Isempty(Queue q)
{
	return q.Front==(q.Rear+1)%MAX_SIZE;
}
bool Isfull(Queue q)
{
	 return q.Front==(q.Rear+2)%MAX_SIZE;
}
//them 1 phan tu vao queue;
bool Enqueue(pQueue q,Info x)
{
	if(Isfull(*q))
	{
		cout<<"\nHang doi day!";
		return false;
	}
	else{
		q->Rear=(q->Rear+1) % MAX_SIZE;
		q->Data[q->Rear]=x;
		return true;
	}
}
bool Dequeue(pQueue q,Info *p)
{
	if(Isempty(*q))
	{
		return false;
	}
	else{
		*p=q->Data[q->Front];
		q->Front=(q->Front+1) % MAX_SIZE;
		return true;
	}
}

// Ham lay 1 phan tu ra khoi hang doi
 

int main(){
	Queue q;
	Init(&q);
	int n;
	cout<<"\nNhap n :";
	cin>>n;
	int t=n;
	while(t>0)
	{
		Enqueue(&q,t%10);
		t=t/10;
	}
	int s=0;
	for(Info i=q.Front;i<=q.Rear;i++)
	{
		s+=q.Data[i];
	}
	cout<<s;
	
	
	
}
