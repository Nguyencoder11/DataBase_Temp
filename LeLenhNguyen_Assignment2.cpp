#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
	if (x > y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
}

class NGUOI
{
	// Di chuyen thuoc tinh vao lop con SINHVIEN
protected: 
	char hoTen[30];
	char ngaySinh[10];
	char que[30];

public:
	// Phuong thuc nhap() cua lop NGUOI
	void nhap()
	{
		cout << "Nhap ho ten: ";
		fflush(stdin);
		gets(hoTen);
		cout << "Nhap ngay sinh: ";
		fflush(stdin);
		gets(ngaySinh);
		cout << "Nhap que quan: ";
		fflush(stdin);
		gets(que);
	}

	// Phuong thuc xuat() cua lop NGUOI
	void xuat()
	{
		cout << setw(30) << left << hoTen << "\t" << setw(10) << right << ngaySinh << "\t" << setw(30) << left << que;
	}
};

// lop SINHVIEN la lop con ke thua cac thuoc tinh cua lop cha NGUOI
class SINHVIEN : public NGUOI	
{
	char MaSV[10];
	char nganh[20];
	int khoaHoc;
	
	// khai bao lop LOPHOC la lop ban voi lop SINHVIEN 
	friend class LOPHOC; 

public:
	// Phuong thuc nhap() cua lop SINHVIEN
	void nhap()
	{
		cout << "Nhap Ma SV: ";
		fflush(stdin);
		gets(MaSV);
		NGUOI::nhap(); // ke thua phuong thuc nhap() cua lop cha(NGUOI)
		cout << "Nhap chuyen nganh: ";
		fflush(stdin);
		gets(nganh);
		cout << "Nhap khoa hoc: ";
		cin >> khoaHoc;
	}

	// Phuong thuc xuat() cua lop SINHVIEN
	void xuat()
	{
		// Ke thua phuong thuc xuat() cua lop cha(NGUOI)
		NGUOI::xuat(); 
		cout << "\t" << setw(10) << MaSV << "\t" << setw(20) << left << nganh << "\t" << setw(10) << khoaHoc << endl;
	}
};

class LOPHOC
{
	int MaLH;
	char tenLH[20];
	char ngayMo[10];
	int n;
	SINHVIEN *x;
	char giaoVien[20];

public:
	// Phuong thuc nhap() cua lop LOPHOC
	void nhap()
	{
		cout << "Nhap ma lop: ";
		cin >> MaLH;
		cout << "Nhap ten lop: ";
		fflush(stdin);
		gets(tenLH);
		cout << "Nhap ngay mo lop: ";
		fflush(stdin);
		gets(ngayMo);
		cout << "Nhap giao vien: ";
		fflush(stdin);
		gets(giaoVien);
		cout << "Nhap so luong sinh vien: ";
		cin >> n;
		x = new SINHVIEN[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Sinh vien " << i + 1 << endl;
			x[i].nhap();
		}
	}

	// Phuong thuc xuat() cua lop LOPHOC
	void xuat()
	{
		cout << "----- Thong tin ve lop hoc -----" << endl;
		cout << "Ma lop: " << MaLH << endl;
		cout << "Ten lop: " << tenLH << endl;
		cout << "Ngay mo lop: " << ngayMo << endl;
		cout << "GVCN: " << giaoVien << endl;
		cout << "------ Thong tin sinh vien ------" << endl;
		cout << "So sinh vien: " << n << endl;
		cout << setw(30) << left << "Ho va ten" << "\t" << setw(10) << "Ngay sinh"
			 << "\t" << setw(30) << "Que quan"
			 << "\t" << setw(10) << "Ma SV"
			 << "\t" << setw(20) << "Chuyen nganh"
			 << "\t" << setw(10) << "Khoa hoc" << endl;
		for (int i = 0; i < n; i++)
		{
			x[i].xuat();
		}
	}

	// Phuong thuc hien thi so sinh vien khoa 11
	void showSV()
	{
		int dem = 0;
		for (int i = 0; i < n; i++)
		{
			if (x[i].khoaHoc == 11)
			{
				dem++;
			}
		}
		cout << dem << endl;
	}

	// Phuong thuc sap xep danh sach sinh vien
	// voi khoa hoc tang dan
	void sortAscKhoaHoc()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (x[i].khoaHoc > x[j].khoaHoc)
				{
					swap(x[i], x[j]);
				}
			}
		}
	}
};

int main()
{
	LOPHOC l1;
	l1.nhap();
	cout << "\n---> Thong tin vua nhap <---" << endl;
	l1.xuat();
	cout << "-----> So sinh vien khoa 11: ";
	l1.showSV();
	cout << endl;
	cout << "\n>--- Thong tin lop hoc sau khi duoc sap xep danh sach SV theo chieu tang khoa hoc ---<" << endl;
	l1.sortAscKhoaHoc();
	l1.xuat();
}
