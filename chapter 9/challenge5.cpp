#include <iostream>

using namespace std;

int doSomething(int* x, int* y) {
    int temp = *x;
    *x = (*y) * 10;
    *y = temp * 10;
    return *x + *y;
}

int main() {
    int a, b;

    // Nhập giá trị cho a và b từ người dùng
    cout << "Nhập giá trị cho a: ";
    cin >> a;
    cout << "Nhập giá trị cho b: ";
    cin >> b;

    // Gọi hàm đã sửa đổi với con trỏ
    int result = doSomething(&a, &b);

    // Hiển thị giá trị đã sửa đổi của a và b cùng với kết quả
    cout << "Giá trị đã sửa đổi của a: " << a << endl;
    cout << "Giá trị đã sửa đổi của b: " << b << endl;
    cout << "Kết quả: " << result << endl;

    return 0;
}
