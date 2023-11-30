#include<iostream>
#include<string>
using namespace std;

class Bike{
private:
    char* brand;
public:
    Bike(){ // Tạo constructor Bike
        string s = "Bike";
        brand = new char[5];
        for(int i=0;i<5;i++){
            brand[i]=s[i];
        }
        brand[5] = '\0';
    }

    Bike(string s){ // Tạo constructor Bike ảo
        brand = new char[s.length()+1];
        for(int i=0;i<s.length();i++){
            brand[i] = s[i];
        }
        brand[s.length()] = '\0';
    }

    virtual void move(int t1){
        cout << brand <<": " << t1*12 << " ";
    }
    
    virtual ~Bike(){ // Hủy Bike để giải phóng dữ liệu
        if(brand){
            delete[] brand;
        }
    }
};

class EBike:public Bike{
public:
    void move(int t2) override{
        Bike::move(t2*2);
    }
};
void display(Bike& a,EBike& b){
    a.move(2);
    b.move(2);
}

int main()
{
    EBike b1,b2;
    display(b1,b2);
    return 0;
}