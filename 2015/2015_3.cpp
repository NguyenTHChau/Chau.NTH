#include <iostream>
#include <vector>
using namespace std;

class Sap 
{
protected:
    int stt;
    float dientich;
    long doanhthu;

public:
    static long DON_GIA_THUE;

    virtual long tinhTienthue() {
        return DON_GIA_THUE * dientich; 
    } 

    virtual long tinhThueDoanhthu() = 0;

    virtual long tinhTongTien() = 0;

    virtual void nhapThongtin() {
        cout << "Nhap so thu tu: ";
        cin >> stt;
        cout << "Nhap dien tich: ";
        cin >> dientich;
        cout << "Nhap doanh thu: ";
        cin >> doanhthu;
    }

    virtual ~Sap() { // Dùng hàm hủy ảo để giải phóng dữ liệu 1 cách an toàn
        stt = 0;
        dientich = 0;
        doanhthu = 0;
    }
};

long Sap::DON_GIA_THUE = 40000000;

class SapThucPham : public Sap 
{
private:
    long phidonglanh;
public:
    static float PHAN_TRAM_THUE_SAP_THUC_PHAM;

    long tinhThueDoanhthu()  {
        return (float)(PHAN_TRAM_THUE_SAP_THUC_PHAM * doanhthu);
    }

    long tinhTongTien() override {
        return tinhThueDoanhthu() + tinhTienthue();
    }

    void nhapThongtin() override {
        Sap::nhapThongtin();
        cout << "Nhap phi dong lanh: ";
        cin >> phidonglanh;
    }
};

float SapThucPham::PHAN_TRAM_THUE_SAP_THUC_PHAM = 0.05;

class SapQuanAo : public Sap 
{
public:
    static float PHAN_TRAM_THUE_SAP_QUAN_AO;

    long tinhThueDoanhthu()  {
        return (float)PHAN_TRAM_THUE_SAP_QUAN_AO * doanhthu;
    }

    long tinhTongTien() override {
        return tinhThueDoanhthu() + tinhTienthue();
    }

    void nhapThongtin() override {
        Sap::nhapThongtin();
    }
};

float SapQuanAo::PHAN_TRAM_THUE_SAP_QUAN_AO = 0.1;

class SapTrangSuc : public Sap 
{
public:

    static long GIOI_HAN;
    static float CAO_HON_DOANH_THU;
    static float THAP_HON_DOANH_THU;

    long tinhThueDoanhthu() override {
        if (doanhthu < GIOI_HAN) {
            return THAP_HON_DOANH_THU * doanhthu;
        } else {
            return CAO_HON_DOANH_THU * doanhthu;
        }
    }

    long tinhTongTien() override {
        return tinhThueDoanhthu() + tinhTienthue();
    }
};

long SapTrangSuc::GIOI_HAN = 100000000;
float SapTrangSuc::THAP_HON_DOANH_THU = 0.2;
float SapTrangSuc::CAO_HON_DOANH_THU = 0.3;

class QuanLyDanhSach 
{
private:
    vector<Sap*> ds;
public:

    void nhapThongTin() {
        cout << "Nhap so luong sap duoc thue: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int choice;
            cout << "1-Sap Thuc Pham, 2-Sap Quan Ao, 3-Sap Trang Suc: ";
            cin >> choice;
            Sap* p = nullptr;
            switch (choice)
            {
            case 1:
                p = new SapThucPham();
                break;
            case 2:
                p = new SapQuanAo();
                break;
            case 3:
                p = new SapTrangSuc();
                break;
            default:
                cout << "Chon lai\n";
                break;
            }
            ds.push_back(p);
            ds[i]->nhapThongtin();
        }
    }

    long tinhTongTien() {
        long sum = 0;
        for (int i = 0; i < ds.size(); i++) {
            sum += ds[i]->tinhTongTien();
        }
        return sum;
    }

    ~QuanLyDanhSach() { // dùng hàm hủy để giải phóng dữ liệu 
        for (Sap* p : ds) {
            delete p;
        }
        ds.clear();
    }
};

int main() 
{
    QuanLyDanhSach ql1;
    ql1.nhapThongTin();
    cout << "Tong tien la " << ql1.tinhTongTien();
    return 0;
}