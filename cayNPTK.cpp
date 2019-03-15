#include<iostream>
#define info int 
using namespace std;
typedef struct node {
	info data;
	node *left ,*right;
}node ;
typedef struct tree{
	node *root;
};
typedef struct node *pNode;
typedef struct tree *pTree;
void init (pTree t){
	t->root=NULL;
}
node *getNode(info a){
	pNode p=new node();
	if(p==NULL){
		cout<<"bo nho day";
		return NULL;
	}
	else{
		p->data=a;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
	
	
}
bool InsertTree(pNode &t,pNode p){
	if(p==NULL) return false;
	else{
		if(t==NULL){//cay rong 
			t=p;//p la goc cua cay
		}
		else{
			if(t->data==p->data) return false;
			if(t->data>p->data&&t->left==NULL){
				t->left=p;
				return true;
			}
			if(t->data<p->data&&t->right==NULL){
				t->right=p;
				return true;
			}
			if(t->data>p->data&&t->left!=NULL){
				return InsertTree(t->left,p);
				
			}
			if(t->data<p->data&&t->right!=NULL){
				return InsertTree(t->right,p);
				
			}
		}
	}
}
node * TimKiem(pNode t,info x)
{
	if(t!=NULL)
	{
		if(t->data == x)
		{
			pNode p = t;
			return p;
		}
		if(t->data >x) return TimKiem(t->left,x);
		if(t->data < x) return TimKiem(t->right,x);
	}
	return NULL;
}
void LNR(pNode t){
	if(t==NULL) return;
	LNR(t->left);
	cout<<t->data<<"  ";
	LNR(t->right);
}
void nhap(pTree t){
	int x;
	cin>>x;
	for(int i=0;i<x;i++){
		info a;
		cin>>a;
		pNode p=getNode(a);
		InsertTree(t->root,p);
	}
}
int DemLeaf(pNode t)
{
	while(t!=NULL)
	{
		if(t->left=NULL && t->right==NULL)
		return 1;
		else
		{
			return (DemLeaf(t->left) +DemLeaf(t->right));
		}
	}
}

int main(){
	tree t;
	init(&t);
	nhap(&t);
	LNR(t.root);
	cout<<DemLeaf(t.root);
}
