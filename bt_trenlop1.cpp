#include <bits/stdc++.h>

using namespace std;

class Electronic
{
protected:
    float congsuat;
    float dienap;

public:
    Electronic(float cs, float da)
    {
        congsuat = cs;
        dienap = da;
    }
};

class Maygiat : public Electronic
{
private:
    float dungtich;
    string loai;

public:
    Maygiat(float cs, float da, float dt, string type) : Electronic(cs, da)
    {
        dungtich = dt;
        loai=type;
    }
    void xuat()
    {
        cout << "Dung tich: " << dungtich << endl;
        cout << "Cong suat: " << congsuat << endl;
        cout << "Dien ap: " << dienap << endl;
        cout << "Loai: " << loai << endl;
    }
};

class Tulanh : public Electronic
{
private:
    float dungtich;
    int songan;

public:
    Tulanh(float cs, float da, float dt, int sn) : Electronic(cs, da)
    {
        dungtich = dt;
        songan = sn;
    }
    void xuat()
    {
        cout << "Dung tich: " << dungtich << endl;
        cout << "Cong suat: " << congsuat << endl;
        cout << "Dien ap: " << dienap << endl;
        cout << "So ngan: " << songan << endl;
    }
};

int main(int argc, char const *argv[])
{
    Maygiat mg(2, 200, 220, "Toshiba");
    Tulanh tl(1.5, 100, 220, 4);
    mg.xuat();
    tl.xuat();
}
