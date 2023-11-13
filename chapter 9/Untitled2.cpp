#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // M? t?p
    ifstream inputFile("Random.txt");

    // Ki?m tra xem t?p có m? thành công không
    if (!inputFile) {
        cerr << "L?i khi m? t?p." << endl;
        return 1; // Thoát v?i m? l?i
    }

    // Bi?n ð? lýu tr? d? li?u
    int number;
    int count = 0;
    int sum = 0;

    // Ð?c các s? t? t?p
    while (inputFile >> number) {
        count++;
        sum += number;
    }

    // Ðóng t?p
    inputFile.close();

    // Tính trung b?nh
    double average = (count > 0) ? static_cast<double>(sum) / count : 0.0;

    // Hi?n th? k?t qu?
    cout << "A) S? lý?ng s? trong t?p: " << count << endl;
    cout << "B) T?ng c?a t?t c? các s? trong t?p: " << sum << endl;
    cout << "C) Trung b?nh c?a t?t c? các s? trong t?p: " << average << endl;

    return 0;
}

