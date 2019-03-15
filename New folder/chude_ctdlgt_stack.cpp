#include<iostream>
#include<conio.h>
#define MAX_SIZE 100
#define Info int
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
		cout<<"\nNgan xep da day !";
	}
	else{
		s->top++;
		s->Data[s->top]=x;
		
		return true;
	}
}
bool Pop(pStack s,Info *a)
{
	if(Isempty(*s))
	{
		cout<<"\nNgan xep rong!";
	}
	else{
		*a=s->Data[s->top];
		s->top--;
		return true;
	}
}
int main(){
	
	int n;
	cout<<"\nNhap n :";
	cin>>n;
	Stack s;
	Init(&s);
	int pn,pd;
	pn=n;
	while(pn!=0)
	{
		pd=pn%2;
		Push(&s,pd);
		pn=pn/2;
	}
	cout<<"\nChuyen sang he 2 : ";
	while(!Isempty(s))
	{
		Pop(&s,&pn);
		cout<<pn;
	}
	getch();
	return 0;
	
}
