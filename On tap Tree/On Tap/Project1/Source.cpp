#include <iostream>
using namespace std;

struct Node
{
	int Data; // Dữ liệu chứa trong Node.
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* Tree;

// Khởi tạo cây.
void Init(Tree &t)
{
	t = NULL;
}

// Thêm phần tử vào cây.
void InSert(Tree &t, int x)
{
	// Cây rỗng => x sẽ là Node gốc.
	if(t == NULL)
	{
		NODE *q = new NODE;
		q ->Data = x;
		q ->pLeft = q ->pRight = NULL;
		t = q;
	}
	else
	{
		if(t ->Data > x)
		{
			InSert(t ->pLeft, x);
		}
		else if(t ->Data < x)
		{
			InSert(t ->pRight, x);
		}
	}
}

// Tạo cây.
void CreateTree(Tree &t)
{
	Init(t); // Khởi tạo cây.

	int LuaChon;

	do{
		cout << "\n1. Nhap du lieu";
		cout << "\n0. Ket thuc";

		cout << "\nNhap vao lua chon cua ban: ";
		cin >> LuaChon;

		if(LuaChon == 1)
		{
			int x;
			cout << "\nNhap du lieu Node can them: ";
			cin >> x;

			InSert(t, x); // Thêm x vào cây.
		}
	}while(LuaChon != 0);
}

void NLR(Tree t)
{
	if(t != NULL)
	{
		cout << t ->Data << "   ";
		NLR(t ->pLeft);
		NLR(t ->pRight);
	}
}

void LNR(Tree t)
{
	if(t != NULL)
	{
		LNR(t ->pLeft);
		cout << t ->Data << "   ";
		LNR(t ->pRight);
	}
}

void LRN(Tree t)
{
	if(t != NULL)
	{
		LRN(t ->pLeft);
		LRN(t ->pRight);
		cout << t ->Data << "   ";
	}
}

void NRL(Tree t)
{
	if(t != NULL)
	{
		cout << t ->Data << "   ";
		NRL(t ->pRight);
		NRL(t ->pLeft);
	}
}

void RNL(Tree t)
{
	if(t != NULL)
	{
		RNL(t ->pRight);
		cout << t ->Data << "   ";
		RNL(t ->pLeft);
	}
}

void RLN(Tree t)
{
	if(t != NULL)
	{
		RLN(t ->pRight);
		RLN(t ->pLeft);
		cout << t ->Data << "   ";
	}
}

NODE* Search(Tree t, int x)
{
	if(t == NULL)
	{
		return NULL;
	}
	if(t ->Data > x)
	{
		Search(t ->pLeft, x);
	}
	else if(t ->Data < x)
	{
		Search(t ->pRight, x);
	}
	else
	{
		return t;
	}
}

// Phần tử p đang được thế mạng cho phần tử q.
void TimPhanTuTheMang(Tree &p, Tree &q)
{
	// Cách 1
	//if(q ->pLeft != NULL)
	//{
	//	TimPhanTuTheMang(p, q ->pLeft);
	//}
	//else // Đã tìm ra trái nhất.
	//{
	//	p ->Data = q ->Data;
	//	p = q;
	//	q = q ->pRight;
	//}

	// Cách 2.
	if(q ->pRight != NULL)
	{
		TimPhanTuTheMang(p, q ->pRight);
	}
	else // Đã tìm ra phải nhất.
	{
		p ->Data = q ->Data;
		p = q;
		q = q ->pLeft;
	}
}

void XoaNode(Tree &t, int x)
{
	// Trước tiên ta sẽ đi xóa các Node có 1 con và các Node lá
	if(t == NULL)
	{
		return;
	}
	if(t ->Data > x)
	{
		XoaNode(t ->pLeft, x);
	}
	else if(t ->Data < x)
	{
		XoaNode(t ->pRight, x);
	}
	else // t ->Data == x
	{
		NODE *p = t;
		
		/* ===== XÓA Node có 1 con và không có con ==== */
		if(t ->pLeft == NULL)
		{
			t = t ->pRight;
		}
		else if(t ->pRight == NULL)
		{
			t = t ->pLeft;
		}
		/* ============================================ */

		/* Xóa Node có 2 con */
		else
		{
			// Cách 1: Trái nhất của cây con phải.
			//TimPhanTuTheMang(p, t ->pRight);

			// Cách 2: Phải nhất của cây con trái.
			TimPhanTuTheMang(p, t ->pLeft);
		}
		delete p;
	}
}

int main()
{
	Tree t; // Khai báo cây.

	CreateTree(t);

	cout << "\nNLR\n";
	NLR(t);

	/*cout << "\nLNR\n";
	LNR(t);

	cout << "\nLRN\n";
	LRN(t);

	cout << "\nNRL\n";
	NRL(t);

	cout << "\nRNL\n";
	RNL(t);

	cout << "\nRLN\n";
	RLN(t);

	int x;
	cout << "\nNhap vao Node x can tim kiem: ";
	cin >> x;

	NODE *q = Search(t, x);
	if(q == NULL)
	{
		cout << "\nKhong tim thay phan tu x !";
	}
	else
	{
		cout << "\nPhan tu x co ton tai trong cay !";
	}*/

	int y;
	cout << "\nNhap vao Node can xoa: ";
	cin >> y;

	XoaNode(t, y);

	cout << "\nCay sau khi xoa: \n";
	cout << "\nNLR\n";
	NLR(t);
	
	system("pause");
	return 0;
}