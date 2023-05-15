#include <bits/stdc++.h>
using namespace std;

class PS
{
private:
    int ts, ms;

public:
    // phuong thuc khoi tao
    // khoi tao khong doi
    PS()
    {
        ts = 3;
        ms = 4;
    }

    // khoi tao co doi
    PS(int a, int b)
    {
        ts = a;
        ms = b;
    }

    // void PS operator>>(int ts, int ms)
    // {
    // }

    // Phuong thuc toan tu tra ve tich 2 phan so
    PS operator*(PS value)
    {
        PS res;
        res.ts = this->ts * value.ts;
        res.ms = this->ms * value.ms;
        return res;
    }

    // phuong thuc toan tu tra ve gia tri cua phan so
    float getValue()
    {
        return (float)this->ts / this->ms;
    }

    // ham toan tu nhap mot phan so
    friend istream &
    operator>>(istream &in, PS value)
    {
    }
    
    // ham toan tu xuat phan so
    friend ostream &operator<<(ostream &out, PS value)
    {
    }

    void
    xuat()
    {
        cout << ts << "/" << ms << endl;
    }
};

int main()
{
    PS ps1;
    cout << "Phan so 1: ";
    ps1.xuat();

    PS ps2(5, 2);
    cout << "Phan so 2: ";
    ps2.xuat();
}