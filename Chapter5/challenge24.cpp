#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Mở tệp
    ifstream inputFile("Random.txt");

    // Kiểm tra xem tệp có mở thành công không
    if (!inputFile) {
        cerr << "Lỗi khi mở tệp." << endl;
        return 1; // Thoát với mã lỗi
    }

    // Biến để lưu trữ dữ liệu
    int number;
    int count = 0;
    int sum = 0;

    // Đọc các số từ tệp
    while (inputFile >> number) {
        count++;
        sum += number;
    }

    // Đóng tệp
    inputFile.close();

    // Tính trung bình
    double average = (count > 0) ? static_cast<double>(sum) / count : 0.0;

    // Hiển thị kết quả
    cout << "A) Số lượng số trong tệp: " << count << endl;
    cout << "B) Tổng của tất cả các số trong tệp: " << sum << endl;
    cout << "C) Trung bình của tất cả các số trong tệp: " << average << endl;

    return 0;
}
