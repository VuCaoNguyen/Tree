#include <iostream>
#include <string>
using namespace std;

// Khai báo cấu trúc thông tin của 1 tỉnh.
struct Tinh
{
	short MaTinh;
	string TenTinh;
	int DanSo;
	double DienTich;
};
typedef struct Tinh TINH;

istream& operator >>(istream &is, TINH &x)
{
	cout << "\nNhap vao ma tinh: ";
	is >> x.MaTinh;

	do{
		fflush(stdin);
		cout << "\nNhap vao ten tinh: ";
		getline(is, x.TenTinh);

		if(x.TenTinh.length() > 30)
		{
			cout << "\nTen tinh khong duoc phep vuot qua 30 ky tu. Xin kiem tra lai !";
		}
	}while(x.TenTinh.length() > 30);

	do{
		cout << "\nNhap vao so luong dan so cua tinh: ";
		is >> x.DanSo;

		if(x.DanSo < 0)
		{
			cout << "\nSo luong dan so khong hop le. Xin kiem tra lai !";
		}
	}while(x.DanSo < 0);

	do{
		cout << "\nNhap vao dien tich: ";
		cin >> x.DienTich;

		if(x.DienTich <= 0)
		{
			cout << "\nDien tich khong hop le. Xin kiem tra lai !";
		}
	}while(x.DienTich <= 0);
	return is;
}

ostream& operator <<(ostream &os, TINH x)
{
	os << "\nMa tinh: " << x.MaTinh;
	os << "\nTen tinh: " << x.TenTinh;
	os << "\nDan so: " << x.DanSo;
	os << "\nDien tich: " << (size_t)x.DienTich;
	return os;
}

// Khởi tạo cấu trúc Node.
struct Node
{
	TINH Data; // Dữ liệu chứa trong Node.
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

// Thêm 1 tỉnh vào cây.
void InSert(Tree &t, TINH x)
{
	if(t == NULL)
	{
		NODE *q = new NODE;
		q ->Data = x;
		q ->pLeft = q ->pRight = NULL;
		t = q;
	}
	else
	{
		if(x.MaTinh < t ->Data.MaTinh)
		{
			InSert(t ->pLeft, x);
		}
		else if(x.MaTinh > t ->Data.MaTinh)
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
		cout << "\n----------------- Menu -----------------\n";
		cout << "\n1. Nhap du lieu";
		cout << "\n0. Ket thuc";
		cout << "\n----------------------------------------\n";

		cout << "\nNhap vao lua chon cua ban: ";
		cin >> LuaChon;

		if(LuaChon != 0 && LuaChon != 1)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
		}
		else
		{
			if(LuaChon == 1)
			{
				TINH x; // Dữ liệu Node cần nhập.
				cout << "\nNhap vao du lieu can them: ";
				cin >> x;
				InSert(t, x); // Thêm x vào cây.
			}
		}
	}while(LuaChon != 0 || (LuaChon != 0 && LuaChon != 1));
}

// Duyệt trước.
void NLR(Tree t)
{
	if(t != NULL)
	{
		cout << t ->Data << endl;
		NLR(t ->pLeft);
		NLR(t ->pRight);
	}
}

// Duyệt giữa.
void LNR(Tree t)
{
	if(t != NULL)
	{
		LNR(t ->pLeft);
		cout << t ->Data << endl;
		LNR(t ->pRight);
	}
}

// Duyệt giữa.
void LRN(Tree t)
{
	if(t != NULL)
	{
		LRN(t ->pLeft);
		LRN(t ->pRight);
		cout << t ->Data << endl;
	}
}

int SoLuongMax = 0;
NODE* Max = NULL;
void TimNodeDanSoMax(Tree t)
{
	if(t != NULL)
	{
		// Xử lý
		if(t ->Data.DanSo > SoLuongMax)
		{
			SoLuongMax = t ->Data.DanSo;
			Max = t;
		}

		TimNodeDanSoMax(t ->pLeft);
		TimNodeDanSoMax(t ->pRight);
	}
}

bool Check = false; // Chưa tìm thấy.

// Yêu cầu xuất ra các tỉnh có diện tích lớn hơn 100000.
void LietKeCacTinhThoaYeuCau(Tree t)
{
	if(t != NULL)
	{
		// Xử lý.
		if(t ->Data.DienTich > 100000)
		{
			Check = true; // Đã tìm thấy.
			cout << t ->Data << endl;
		}

		LietKeCacTinhThoaYeuCau(t ->pLeft);
		LietKeCacTinhThoaYeuCau(t ->pRight);
	}
}

int dem = 0;

// Đếm số lượng các Node lá có diện tích nhỏ hơn 700 và dân số lớn hơn 1000000
void XuLyNodeLa(Tree t)
{
	if(t != NULL)
	{
		// Xử lý.
		if(t ->pLeft == NULL && t ->pRight == NULL) // t là Node lá.
		{
			if(t ->Data.DienTich < 700 && t ->Data.DanSo > 1000000)
			{
				dem++; // Tăng biến đếm lên.
			}
		}

		XuLyNodeLa(t ->pLeft);
		XuLyNodeLa(t ->pRight);
	}
}

int main()
{
	Tree t;
	CreateTree(t);

	cout << "\n\nNLR\n";
	NLR(t);

	cout << "\n\nLNR\n";
	LNR(t);

	cout << "\n\nLRN\n";
	LRN(t);

	TimNodeDanSoMax(t);
	cout << "\nDan so lon nhat la: " << SoLuongMax;
	cout << "\nTinh co dan so lon nhat la: ";
	cout << Max ->Data;

	cout << "\nCac tinh co dien tich lon hon 100000 la:\n";
	LietKeCacTinhThoaYeuCau(t);
	if(Check == false)
	{
		cout << "Khong co tinh nao thoa yeu cau !";
	}

	XuLyNodeLa(t);
	if(dem == 0)
	{
		cout << "\nKhong co Node la' nao thoa yeu cau !";
	}
	else
	{
		cout << "\nSo luong Node la' thoa yeu cau la: " << dem;
	}

	system("pause");
	return 0;
}