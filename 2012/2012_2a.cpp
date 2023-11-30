#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw() const =0;
};

class Square:public Shape{
public:
    void draw() const override{
        cout << "Ve hinh vuong" << endl;
    }
    ~Square(){}
};

class Circle:public Shape{
private:
    double radius;
public:
    void draw() const override{
        cout << "Ve hinh tron" << endl;
    }
    ~Circle(){}
};

int main()
{
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    shape1-> draw();//Output: Ve hinh tron
    shape2-> draw();//Output: Ve hinh vuong
    return 0;
}