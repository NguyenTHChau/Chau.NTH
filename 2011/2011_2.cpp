#include <iostream>
using namespace std;

class MayLoc {
private:
    double m_tgian;
public:
    void setTgian(double t){
        m_tgian = t;
    };
    double getThoiGian(){
        return m_tgian;
    };
};

class MayXucTac : public MayLoc {
private:
    int luongHoaChat;
    float CongSuatLoc;
public:
    void nhap() {
        double thoiGian = 0;
        cout << "Nhap thoi gian hoat dong: ";
        cin >> thoiGian;
        setTgian(thoiGian);
        cout << "Nhap Luong hoa chat: ";
        cin >> luongHoaChat;
        cout << "Nhap cong suat loc cua may: ";
        cin >> CongSuatLoc;
    }

    float CongSuatThucTe() {
        if (getThoiGian() >= 10) {
            return CongSuatLoc * (luongHoaChat / 100) / (getThoiGian() / 10);
        } else {
            return CongSuatLoc * (luongHoaChat / 100);
        }
    }

    static long long DON_GIA_HOA_CHAT;
    static long long DON_GIA_THUE;

    long tinhChiPhiThueMoiMay() {
        return DON_GIA_THUE * getThoiGian();
    }

    long tinhChiPhi() {
        return tinhChiPhiThueMoiMay() + luongHoaChat * DON_GIA_HOA_CHAT;
    }

    double tinhLuongNuoc() {
        return getThoiGian() * CongSuatThucTe();
    }
};

long long MayXucTac::DON_GIA_HOA_CHAT = 10000;
long long MayXucTac::DON_GIA_THUE = 80000;

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;
    return 0;
}