#include <iostream>
using namespace std;

class MayLyTam {
private:
    int luongxang;
    double congsuat;
    double Time;
public:
    void nhap() {
        cout << "Nhap thoi gian hoat dong: ";
        cin >> Time;
        cout << "Nhap Luong xang: ";
        cin >> luongxang;
        cout << "Nhap cong suat loc cua may: ";
        cin >> congsuat;
    }
    void setTgian(double t)
    {
        Time=t;
    }
    double getTime()
    {
        return Time;
    }
    
    static long long DON_GIA_THUE_MayLyTam;
    
    float tinhLuongNuoc() {
        return this->getTime() * congsuat;
    }

    long tinhChiPhiThueMoiMay() {
        return DON_GIA_THUE_MayLyTam * this->getTime();
    }

    long tinhChiPhi() {
        return tinhChiPhiThueMoiMay() + luongxang * 20000;
    }
};

class MayXucTac {
private:
    int luonghoachat;
    double congsuat;
    double Time;
public:
    void nhap() {
        double thoiGian = 0;
        cout << "Nhap thoi gian hoat dong: ";
        cin >> thoiGian;
        cout << "Nhap Luong hoa chat: ";
        cin >> luonghoachat;
        cout << "Nhap cong suat loc cua may: ";
        cin >> congsuat;
    }
    void setTgian(double t)
    {
        Time=t;
    }
    double getTime()
    {
        return Time;
    }
 
    float CongSuatThucTe() {
        if (this->getTime() >= 10) {
            return congsuat * (luonghoachat / 100) / (this->getTime() / 10);
        } else {
            return congsuat * (luonghoachat / 100);
        }
    }

    static long long DON_GIA_THUE_MayXucTac;
    long tinhChiPhiThueMoiMay() {
        return DON_GIA_THUE_MayXucTac* this->getTime();
    }

    float tinhLuongNuoc() {
        return this->getTime() * CongSuatThucTe();
    }

    long tinhChiPhi() {
        return tinhChiPhiThueMoiMay() + luonghoachat * 10000;
    }
};

long long MayLyTam::DON_GIA_THUE_MayLyTam = 50000;
long long MayXucTac::DON_GIA_THUE_MayXucTac = 80000;

int main() {
    int SoMayXucTac,SoMayLyTam;
    double nuoc; 
    cout << " Nhap vao luong nuoc trong ao ";
    cin >> nuoc;
    cout <<"Nhap so luong may xuc tac";
    cin >> SoMayXucTac;
    cout <<"Nhap so luong may ly tam";
    cin >> SoMayLyTam;
    long long chiphixuctac=0;
    long luong_nuoc_xuc_tac=0;
    long long chiphilytam=0;
    long luong_nuoc_ly_tam=0;
    for(int index=1;index<=SoMayXucTac;index++)
    {
        MayXucTac a;
        a.nhap();
        chiphixuctac += a.tinhChiPhi();
        luong_nuoc_xuc_tac += a.tinhLuongNuoc();
    }
    for (int index = 1; index <=SoMayXucTac; index++)
    {
        MayLyTam b;
        b. nhap();
        chiphilytam += b.tinhChiPhi();
        luong_nuoc_ly_tam += b.tinhLuongNuoc();
    }
    long long tongchiphi= chiphilytam + chiphixuctac;
    long long tongluongnuoc= luong_nuoc_ly_tam + luong_nuoc_xuc_tac;
    if (tongluongnuoc>=nuoc)
    {
        cout << " Ao duoc loc het "<< endl;
    }
    else 
    {
        cout << "Ao chua duoc loc het" << endl;
    }
    cout << " Tong chi phi la " << tongchiphi;
    return 0;
}
