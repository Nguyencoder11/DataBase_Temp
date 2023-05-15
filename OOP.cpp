#include <bits/stdc++.h>
using namespace std;

class BanhKeo;
class NhaSX
{
private:
    char TenNSX[20], DCSX[30];

public:
    friend class HangHoa;
    char *getTen()
    {
        return TenNSX;
    }
};

class HangHoa
{
protected:
    char TenH[30];
    NhaSX NSX;
    int dongia;

public:
    void input()
    {
        cout << "Ten hang: ";
        fflush(stdin);
        gets(TenH);
        cout << "Ten NSX: ";
        fflush(stdin);
        gets(NSX.TenNSX);
        cout << "Dia chi: ";
        fflush(stdin);
        gets(NSX.DCSX);
        cout << "Don gia: ";
        cin >> dongia;
    }

    void output()
    {
        cout << setw(35) << TenH << setw(25) << NSX.TenNSX << setw(35) << NSX.DCSX << setw(12) << dongia;
    }
    friend void BanhKeo_HaiHa(BanhKeo *b, int n);
};

class Date
{
private:
    int d, m, y;

public:
    friend class BanhKeo;
    int getMonth()
    {
        return m;
    }
    int getYear()
    {
        return y;
    }
};

class BanhKeo : public HangHoa
{
private:
    int Kichthuoc;
    Date Ngaynhap;

public:
    void input()
    {
        HangHoa::input();
        cout << "Kich thuoc: ";
        cin >> Kichthuoc;
        cout << "Ngay nhap: ";
        cin >> Ngaynhap.d >> Ngaynhap.m >> Ngaynhap.y;
    }
    void output()
    {
        HangHoa::output();
        cout << setw(10) << Kichthuoc << setw(12) << Ngaynhap.d << "/" << Ngaynhap.m << "/" << Ngaynhap.y << endl;
    }
    friend void BanhKeo_HaiHa(BanhKeo *b, int n);
};

void BanhKeo_HaiHa(BanhKeo *b, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(b[i].NSX.getTen(), "Hai Ha") == 0 && b[i].Ngaynhap.getMonth() == 3 && b[i].Ngaynhap.getYear() == 2021)
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "Khong co banh keo cua nha san xuat Hai Ha nhap 3/2021\n";
    }
    else
    {
        cout << "Danh sach banh keo cua Nha san xuat Hai Ha:\n";
        cout << setw(35) << "Ten hang" << setw(25) << "Ten NSX" << setw(35) << "Dia chi SX" << setw(12) << "Don gia" << setw(15) << "Kich thuoc" << setw(15) << "Ngay nhap" << endl;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(b[i].NSX.getTen(), "Hai Ha") == 0 && b[i].Ngaynhap.getMonth() == 3 && b[i].Ngaynhap.getYear() == 2021)
            {
                b[i].output();
            }
        }
    }
}

int main()
{
    BanhKeo *b;
    int n;
    do
    {
        cout << "Nhap vao so luong banh keo: ";
        cin >> n;
    } while (n <= 0);
    b = new BanhKeo[n];
    cout << "-----> Nhap thong tin cac banh keo\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Banh keo thu " << i + 1 << endl;
        b[i].input();
    }

    cout << "------------------------------------------------------ THONG TIN CAC BANH KEO VUA NHAP ---------------------------------------------------------------\n";
    cout << setw(35) << "Ten hang" << setw(25) << "Ten NSX" << setw(35) << "Dia chi SX" << setw(12) << "Don gia" << setw(15) << "Kich thuoc" << setw(15) << "Ngay nhap" << endl;
    for (int i = 0; i < n; i++)
    {
        b[i].output();
    }
    BanhKeo_HaiHa(b, n);
}