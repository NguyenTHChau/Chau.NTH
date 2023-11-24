#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Mở tệp để ghi
    ofstream outputFile("SavingsReport.txt");

    // Kiểm tra xem tệp có mở thành công không
    if (!outputFile) {
        cerr << "Lỗi khi mở tệp." << endl;
        return 1; // Thoát với mã lỗi
    }

    // Biến để lưu trữ dữ liệu
    double annualInterestRate;
    double initialBalance;
    int numMonths;

    // Nhập thông tin từ người dùng
    cout << "Nhập lãi suất hàng năm: ";
    cin >> annualInterestRate;

    cout << "Nhập số dư ban đầu: ";
    cin >> initialBalance;

    cout << "Nhập số tháng: ";
    cin >> numMonths;

    // In ra tiêu đề báo cáo vào tệp
    outputFile << "BÁO CÁO SỐ DƯ TÀI KHOẢN TIẾT KIỆM\n\n";
    outputFile << "Lãi suất hàng năm: " << annualInterestRate << "%\n";
    outputFile << "Số dư ban đầu: $" << initialBalance << "\n";
    outputFile << "Số tháng: " << numMonths << "\n\n";

    // Tính số dư cuối cùng và ghi vào tệp
    double monthlyInterestRate = annualInterestRate / 12 / 100;
    for (int month = 1; month <= numMonths; ++month) {
        initialBalance += (initialBalance * monthlyInterestRate);
        outputFile << "Tháng " << month << ": $" << initialBalance << "\n";
    }

    // Đóng tệp
    outputFile.close();

    cout << "Báo cáo đã được ghi vào tệp SavingsReport.txt." << endl;

    return 0;
}
