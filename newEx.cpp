#include <bits/stdc++.h>
using namespace std;
class Phieu;
class NhanVien
{
private:
    string tennv, chucvu, phong, truongphong;
    char maphong[10];

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Nhap ten nv: ";
        fflush(stdin);
        getline(cin, tennv);
        cout << "Nhap chuc vu: ";
        fflush(stdin);
        getline(cin, chucvu);
        cout << "Nhap ten phong: ";
        fflush(stdin);
        getline(cin, phong);
        cout << "Nhap ma phong: ";
        fflush(stdin);
        gets(maphong);
        cout << "Nhap truong phong: ";
        fflush(stdin);
        getline(cin, truongphong);
    }
    void xuat()
    {
        cout << "Ten nhan vien: " << tennv << endl;
        cout << "Chuc vu: " << chucvu << endl;
        cout << "Phong: " << phong << endl;
        cout << "Ma phong: " << maphong << endl;
        cout << "Truong phong: " << truongphong << endl;
    }
};

class TaiSan
{
private:
    string tents, tinhtrang;
    int soluong;

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Nhap ten tai san: ";
        fflush(stdin);
        getline(cin, tents);
        cout << "Nhap so luong: ";
        cin >> soluong;
        cout << "Nhap tinh trang: ";
        fflush(stdin);
        getline(cin, tinhtrang);
    }
    void xuat()
    {
        cout << setw(20) << tents << "\t" << setw(10) << soluong << "\t" << setw(20) << left << tinhtrang << endl;
    }
    friend void Sua(Phieu a[], int n);
    friend void sapxep_Sl(Phieu a[], int n);
};

class Phieu
{
private:
    int maphieu;
    char ngayKiemke[10];
    NhanVien nv;
    TaiSan *ts;
    int n;

public:
    void nhap()
    {
        cout << "Nhap ma phieu: ";
        cin >> maphieu;
        cout << "Nhap ngay kiem ke: ";
        fflush(stdin);
        gets(ngayKiemke);
        nv.nhap();
        cout << "Nhap so tai san: ";
        cin >> n;
        ts = new TaiSan[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin tai san " << i + 1 << endl;
            ts[i].nhap();
        }
    }
    void xuat()
    {
        cout << "Ma phieu: " << maphieu << endl;
        cout << "Ngay kiem ke: " << ngayKiemke << endl;
        nv.xuat();
        cout << "\nDanh sach cac hang hoa" << endl;
        cout << setw(20) << "Ten tai san"
             << "\t" << setw(10) << "So luong"
             << "\t" << setw(20) << left << "Tinh trang" << endl;
        for (int i = 0; i < n; i++)
        {
            ts[i].xuat();
        }
    }
};

void Sua(Phieu a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i], "May vi tinh") == 0)
        {
            a[i].ts.soluong = 20;
        }
    }
}

void sapxep_Sl(Phieu a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].ts.soluong > a[j].ts.soluong)
            {
                Phieu tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}

int main()
{
    Phieu P;
    P.nhap();
    cout << "---------- THONG TIN PHIEU ----------" << endl;
    P.xuat();
}
