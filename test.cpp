#include <iostream>
using namespace std;
class Hang;
class Date
{
private:
    int d, m, y;

public:
    void xuat()
    {
        cout << d << "/" << m << "/" << y << endl;
    }
    friend class Hang;
    friend void inMatHangNam2017(Hang *listMH, int n);
};

class Hang
{
private:
    int maHang;
    string tenHang;
    Date ngaySX;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenHang);
        cout << "Nhap ngay san xuat:\n";
        int day, month, year;
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    }
    void xuat()
    {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Ngay san xuat: ";
        ngaySX.xuat();
    }
    friend void inMatHangNam2017(Hang *listMH, int n);
};

void inMatHangNam2017(Hang *listMH, int n)
{
    cout << "Danh sach cac mat hang san xuat nam 2017:\n";
    for (int i = 0; i < n; i++)
    {
        if (listMH[i].ngaySX.y == 2017)
        {
            listMH[i].xuat();
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    Hang *listMH = new Hang[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin mat hang thu " << i + 1 << ":\n";
        listMH[i].nhap();
    }
    inMatHangNam2017(listMH, n);
    delete[] listMH;
    return 0;
}
