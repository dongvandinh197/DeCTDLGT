#include<iostream>
#include<conio.h>
#define Info int
#define MAX_SIZE 100
using namespace std;
typedef struct Stack{
	int top;
	Info Data[MAX_SIZE];
};
typedef struct Stack *pStack;
void Init(pStack s)
{
	s->top=0;
}
bool Isempty(Stack s)
{
	return s.top==0;
}
bool Isfull(Stack s)
{
	return s.top==MAX_SIZE;
}

bool Push(pStack s,Info x)
{
	if(Isfull(*s))
	{
		cout<<"\nNgan xep day !";
		return false;
	}
	else {
		s->top++;
		s->Data[s->top]=x;
		return true;
	}
}
bool Pop(pStack s,Info *a)
{
	if(Isempty(*s))
	{
		cout<<"\nNgan xep rong !";
		return false;
	}
	else{
		*a=s->Data[s->top];
		s->top--;
		return true;
	}
}
int main(){
	Stack s;
	Init(&s);
	int n,pd,pn;
	cout<<"\nNhap n: ";
	cin>>n;
	pn=n;
	cout<<"\nSo "<<n<<"chuyen sang he 2 la: ";	
	while(pn>0)
	{
		pd=pn%2;
		Push(&s,pd);
		pn=pn/2;
	}
	while(Isempty(s)==false)
	{
		Pop(&s,&pd);
		cout<<pd;
	}
	
	getch();
	return 0;
}
