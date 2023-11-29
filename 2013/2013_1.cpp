#include<iostream>
using namespace std;
class PhanSo {
private:
    int tu, mau;

public:
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(const int& tu, const int& mau) {
        this->tu = tu;
        this->mau = mau;
        if (this->mau == 0) {
            cout << "Mau khong duoc bang 0\n";
            this->tu = 0;
            this->mau = 0;
        }
    }

    PhanSo operator+(const PhanSo& ps) {
        PhanSo newPhanSo(tu * ps.mau + mau * ps.tu, mau * ps.mau);
        return newPhanSo;
    }

    PhanSo operator+=(const PhanSo& ps) {
       tu =tu * ps.mau +mau * ps.tu;
       mau *= ps.mau;
        return *this;
    }

    PhanSo operator+(const int& num) {
        PhanSo newPhanSo(this->tu + num *mau,mau);
        return newPhanSo;
    }

    PhanSo operator++() {
        tu += mau;
        return *this;
    }

    operator int() {
        return tu / mau;
    }

    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        out << ps.tu << "/" << ps.mau;
        return out;
    }

    ~PhanSo() {
        tu = 0;
        mau = 1;
    }
};
using namespace std;
int main ()
{
    PhanSo a(1,3),c;
    int b=8;
    c=a+b;
    cout << "c= "<< a<< "+ "<< b << " = "<< c << endl;
    cout <<"++c: ";
    cout << "c= "<< ++c << endl;
    cout << "a= "<< a << " + "<< c << endl;
    a+=c;
    cout << "a= "<< a << endl;
    b=a;
    cout << "b= "<< b<< endl;
    return 0;
}