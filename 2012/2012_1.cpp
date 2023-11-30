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
        return newPhanSo; // Định nghĩa lại phép '+' giữa 2 phân số
    }

    PhanSo operator+=(const PhanSo& ps) {
       tu =tu * ps.mau +mau * ps.tu;
       mau *= ps.mau;
        return *this; // Định nghĩa lại phép '+='
    }

    PhanSo operator+(const int& num) {
        PhanSo newPhanSo(this->tu + num *mau,mau);
        return newPhanSo; // Định nghĩa lại phép công giữa phân số và 1 số bất kì
    }

    PhanSo operator++() {
        tu += mau;
        return *this; // Định nghĩa lại phép '++'
    }

    operator int() {
        return tu / mau; // Trình bày theo kiểu phân số
    }

    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        out << ps.tu << "/" << ps.mau;
        return out; // xuất phân số
    }

    ~PhanSo() { // Hủy phân số để giải phóng bộ nhớ
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