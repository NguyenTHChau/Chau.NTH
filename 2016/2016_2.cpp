#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class BenhNhan {
protected:
    int MSBN;
    string hoatdong;

public:
    virtual void nhap() {
        cout << "Nhap ma so benh nhan: ";
        cin >> MSBN;
        cout << "Nhap hoat dong cua benh nhan: ";
        cin >> hoatdong;
    }

    virtual bool TrangThai() {
        return true;
    }

    virtual long TinhTien() {
        return 0;
    }

    virtual void xuat(ostream& out) {
        out << "Ma so benh nhan: " << MSBN << endl;
        out << "Hoat dong: " << hoatdong << endl;
    }
};

class BenhNhanNgoaiTru : public BenhNhan {
private:
    long VienPhi;

public:
    void nhap() {
        BenhNhan::nhap();
        cout << "Nhap vien phi: ";
        cin >> VienPhi;
    }

    long TinhTien() override {
        return VienPhi;
    }

    void xuat(ostream& out) override {
        BenhNhan::xuat(out);
        out << "Vien phi: " << VienPhi << endl;
    }
};

class BenhNhanNoiTru : public BenhNhan {
private:
    char loaiphong;
    int soNgayNamVien;
    long chiphikhambenh;

public:
    static long A;
    static long B;
    static long C;

    void nhap() override {
        BenhNhan::nhap();
        cout << "Nhap loai phong (A/B/C): "<< endl;
        cin >> loaiphong;
        cout << "Nhap so ngay nam vien: "<< endl;
        cin >> soNgayNamVien;
        cout << "Nhap chi phi kham benh"<< endl;
        cin >> chiphikhambenh;
    }

    long TinhTien() override {
        switch (loaiphong)
        {
        case 'A':
            return soNgayNamVien * (chiphikhambenh + A);
            break;
        case 'B':
            return soNgayNamVien * (chiphikhambenh + B);
            break;
        case 'C':
            return soNgayNamVien * (chiphikhambenh + C);
            break;
        default:
            break;
        }
    }

    void xuat(ostream& out) override {
        BenhNhan::xuat(out);
        out << "Loai phong: " << loaiphong << endl;
        out << "So ngay nam vien: " << soNgayNamVien << endl;
        out << "Phi kham benh: " << chiphikhambenh << endl;
        out << "Tong chi phi kham benh: " << TinhTien() << endl;
    }
};

long BenhNhanNoiTru::A = 1400000;
long BenhNhanNoiTru::B = 900000;
long BenhNhanNoiTru::C = 600000;

class DanhSachBenhNhan {
    vector<BenhNhan*> ds;

private:
    int soluongBNNoiT = 0; // số lượng bệnh nhân Noi trú
    int soluongBNNgoaiT = 0; // số lượng bệnh nhân Ngoại trú

public:
    void nhapThongtin() {
        cout << "Nhap so luong benh nhan: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int choice;
            cout << "1-Benh Nhan Noi Tru, 2-Benh Nhan Ngoai Tru" << endl;
            cin >> choice;
            BenhNhan* p = nullptr;
            if (choice == 1) {
                p = new BenhNhanNoiTru();
                soluongBNNoiT += 1;
            }
            else if (choice == 2) {
                p = new BenhNhanNgoaiTru();
                soluongBNNgoaiT += 1;
            }
            else {
                cout << "Nhap lai";
                i--;
                continue;
            }
            ds.push_back(p);
            ds[i]->nhap();
        }
    }

    int NgoaiTru() {
        return soluongBNNgoaiT;
    }

    int NoiTru() {
        return soluongBNNoiT;
    }

    long tinhTongTien() {
        long sum = 0;
        for (int i = 0; i < ds.size(); i++) {
            sum += ds[i]->TinhTien();
        }
        return sum;
    }

    void xuatThongTin(ostream& out) {
        for (int i = 0; i < ds.size(); i++) {
            ds[i]->xuat(out);
            out << "--------------------" << endl;
        }
    }

    ~DanhSachBenhNhan() {
        for (BenhNhan* p : ds) {
            delete p;
        }
        ds.clear();
    }
};

int main() {
    DanhSachBenhNhan q1;
    ofstream fileOut("danhsach.txt"); // Tạo và mở tệp để ghi xuất
    if (fileOut.is_open()) {
        q1.nhapThongtin();
        cout << "So luong benh nhan noi tru la " << q1.NoiTru() << endl;
        cout << "So luong benh nhan ngoai tru la " << q1.NgoaiTru() << endl;
        cout << "Tong tien la " << q1.tinhTongTien() << endl;

        fileOut << "So luong benh nhan noi tru la " << q1.NoiTru() << endl;
        fileOut << "So luong benh nhan ngoai tru la " << q1.NgoaiTru() << endl;
        fileOut << "Tong tien la " << q1.tinhTongTien() << endl;

        q1.xuatThongTin(cout); // Xuất ra màn hình
        q1.xuatThongTin(fileOut); // Xuất vào tệp
        fileOut.close(); // Đóng tệp
    }
    else {
        cout << "Khong the mo file de ghi.";
    }

    return 0;
}