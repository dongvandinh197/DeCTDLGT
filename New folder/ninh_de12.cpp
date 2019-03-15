#include<iostream>
using namespace std;
#define Info int
#define MAX_SIZE 100
struct Queue{
    Info Data[MAX_SIZE];
    int f, l;//first, last: dau va cuoi cua Queue
 
};
 
typedef struct Queue *pQueue; //Dinh nghia con tro Queue
 
void Init(pQueue q)
{
	// vi f = (l+1)%MAX_SIZE
	q->f = 0;
	q->l = MAX_SIZE -1;
}
 
bool isEmpty(Queue q)
{
	return q.f == (q.l+1) % MAX_SIZE;
}
 
bool isFull(Queue q)
{
	return q.f == (q.l + 2)%MAX_SIZE;
}
 
bool EnQueue(pQueue q, Info a)//dua vao hang doi
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
bool DeQueue(pQueue q, Info *p)
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
        int n;
        cout<<"\nNhap so nguyen duong:";cin>>n;
        int t=n;
        while(t>0)
        {
            EnQueue(&q,t%10);
            t=t/10;
        }
        int s=0;
        while(isEmpty(q)==false)
        {
            int x;
            DeQueue(&q,&x);
            s+=x;
        }
        cout<<"\Tong s="<<s;
        return 0;
}
 
