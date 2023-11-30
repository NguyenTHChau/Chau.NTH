#include<iostream>
using namespace std;

class SoPhuc
{
private:
    int real; // Phan thuc
    int imag; // Phan ao
public:
    SoPhuc(int rl=0,int img=0):real(rl),imag(img){}
    
    int getReal() const{
        return real;
    }
    int getImag() const{
        return imag;
    }

    void nhap(){
        cout << "nhap phan thuc: ";
        cin >> real;
        cout << "nhap phan ao: ";
        cin >> imag;
    }
    void xuat(){
        cout << real;
        if(imag>0){
            cout << " + " << imag <<"sqrt(7)";
        }
        else{
            cout << " + " << -imag <<"sqrt(7)";
        }
        cout << endl;
    }

    SoPhuc operator+(const SoPhuc& num) const{
        return SoPhuc(real + num.real,imag + num.imag); // (a+b√7) + (c+d√7) = (a+c) + (b+d)√7
    }
    SoPhuc operator-(const SoPhuc& num) const{
        return SoPhuc(real - num.real,imag - num.imag); // (a+b√7) - (c+d√7) = (a-c) + (b-d)√7 
    } 
    SoPhuc operator-() const{
        return SoPhuc(-real,-imag); // a+b√7 = -a-b√7
    }
    SoPhuc operator*(const SoPhuc& num) const{
        int newReal = real * num.real + 7 * imag * num.imag; // (a+b√7) * (c+d√7) = (a*c + 7*b*d) + (a*d + b*c)* √7
        int newImag = real * num.imag + imag * num.real;
        return SoPhuc(newReal,newImag);
    }
};

int main()
{
    SoPhuc num1,num2,ketqua;
    cout << "Nhap so thu nhat:\n";
    num1.nhap();
    cout << "Nhap so thu hai:\n";
    num2.nhap();

    ketqua = num1 + num2;
    cout << "Tong= ";
    ketqua.xuat();

    ketqua = num1 - num2;
    cout << "Hieu= ";
    ketqua.xuat();

    ketqua = -num1;
    cout << "Phep doi dau so thu nhat= ";
    ketqua.xuat();

    ketqua = num1 * num2;
    cout << "Tich= ";
    ketqua.xuat();
    
    return 0;
}