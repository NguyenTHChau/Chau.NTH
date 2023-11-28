#include<iostream>
using namespace std;
const double PI = 3.14;

class Shape{
public:
    virtual void draw() const =0;
    virtual double area() const =0;
};

class Circle:public Shape{
private:
    double radius;
public:
    Circle(double r): radius(r){}
    void draw() const override{
        cout << "Ve hinh tron" << endl;
    }
    double area() const override{
        return PI * radius * radius;
    }
};

int main()
{
    Circle circle(2);
    circle.draw(); //Output: Ve hinh tron
    cout << "Dien tich hinh tron = " << circle.area() << endl; //Output: Dien tich hinh tron = 12.56 
    return 0;
}