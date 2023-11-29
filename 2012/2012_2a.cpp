#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "This is an animal speaking." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Meow! Meow!" << endl;
    }
};

class Duck : public Animal {
public:
    void speak() {
        cout << "Quack! Quack!" << endl;
    }
};

// Sử dụng đa hình
void animal_sound(Animal* animal) {
    animal->speak();
}

int main() {
    Dog dog;
    Cat cat;
    Duck duck;

   // In animal_sound(&dog);  ra "Woof! Woof!"
    animal_sound(&cat);  // In ra "Meow! Meow!"
    animal_sound(&duck); // In ra "Quack! Quack!"

    return 0;
}
