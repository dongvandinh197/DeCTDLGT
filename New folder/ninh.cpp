#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct NhanVien{
    int MaNV, BacLuong, NgayCong;
    string HoTen,DiaChi,SoDT;
 
};
typedef struct NhanVien NV;
void NhapNV(NV &a)
{
    fflush(stdin);
    cout<<"\nNhap ma nv:";
    cin>>a.MaNV;
     fflush(stdin);
    cout<<"\nNhap ho ten:";
    getline(cin,a.HoTen);
    cout<<"\nNhap dia chi:";
    getline(cin,a.DiaChi);
    cout<<"\nNhap sdt:";
    getline(cin,a.SoDT);
    cout<<"\nNhap bac luong:";
    cin>>a.BacLuong;
    cout<<"\nNhap ngay cong:";
    cin>>a.NgayCong;
 
}
void XuatNV(NV a)
{
    cout<<"\nMaNV:"<<a.MaNV<<",HoTen:"<<a.HoTen<<", DiaChi:"<<a.DiaChi<<", SDT:"<<a.SoDT<<", BacLuong:"<<a.BacLuong<<", NgayCong:"<<a.NgayCong;
}
 
 
struct Node{
    NV Data;
    struct Node *pLeft;
	struct Node *pRight;
};
 
typedef struct Tree
{
	Node *Root;//goc
};
 
typedef struct Tree *pTree;
typedef struct Node	*pNode;
 
void Init(pTree t)
{
    t->Root=NULL;
 
}
Node* ThemData(NV x)
{
    pNode p=new Node;
	if(p==NULL)
        cout<<"Bo nho day!";
	p->Data=x;
	p->pLeft=p->pRight=NULL;
	return p;
}
bool Chen(pNode &t, pNode p)
{
    if(t==NULL)//cay ko co goc
    {
        t=p;
        return true;
    }
    else
    {
        if(t->Data.MaNV==p->Data.MaNV)return false;
        if(t->Data.MaNV > p->Data.MaNV && t->pLeft==NULL)
        {
            t->pLeft=p;
            return true;
        }else if(t->Data.MaNV < p->Data.MaNV && t->pRight==NULL)
        {
            t->pRight=p;
            return true;
        }else if(t->Data.MaNV > p->Data.MaNV && t->pLeft!=NULL)
        {
            return Chen(t->pLeft,p);
        }else if(t->Data.MaNV < p->Data.MaNV && t->pRight!=NULL)
        {
            return Chen(t->pRight,p);
        }
 
 
    }
}
 
Node* TimKiem(pNode t, int key)//tim node co maNv=key
{
    if(t!=NULL)
    {
        if(t->Data.MaNV==key)
        {
            Node *p=t;
            return t;
        }else if(t->Data.MaNV>key)
        {
            return TimKiem(t->pLeft,key);
        }else if(t->Data.MaNV<key)
        {
            return TimKiem(t->pRight,key);
        }
    }
    return NULL;
}
 
 
void NLR(pNode p)//duyet tien to
{
    if(p==NULL)return;
    XuatNV(p->Data);
    NLR(p->pLeft);
    NLR(p->pRight);
}
 
void LNR(pNode p)//duyet trung to
{
    if(p==NULL)return;
 
    LNR(p->pLeft);
    XuatNV(p->Data);
    LNR(p->pRight);
}
void LRN(pNode p)
{
     if(p==NULL)return;
 
    LRN(p->pLeft);
 
    LRN(p->pRight);
      XuatNV(p->Data);
}
 
 
void Nhap(pTree t)
{
	int n;
	cout<<"\nNhap so nhan vien n=";
	cin>>n;
    for(int i=0; i<n;i++)
	{
		NV x;
		cout<<"\nNhap thong tin nhan vien: ";
		NhapNV(x);
		pNode p=ThemData(x);
		Chen(t->Root,p);
	}
}
int main()
{
    Tree t;
	Init(&t);
	Nhap(&t);
	cout<<"\nDuyet tien to:";
	NLR(t.Root);
    cout<<"\nTim kiem:";
    int ma;
    cout<<"\nNhap ma nv muon tim:";cin>>ma;
    pNode p=TimKiem(t.Root,ma);
    if(p)
    {
        XuatNV(p->Data);
        cout<<endl;
    }else
        cout<<"\nKo tim thay\n";
 
}
/*
vd 3 4  1 5 0
      3
    1    4
  0        5
tien to: 3 1 0 4 5
*/
 
