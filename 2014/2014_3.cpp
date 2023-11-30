#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CuocDt
{
private:
    float time;
public:
    static long CALL_FEE;
    long cuocGoi(){
        cout << "Nhap thoi gian goi: ";
        cin >> time;
        return CALL_FEE * time; // Cước điện thoại = thời gian gọi * đơn giá (1000/phút)
    }
};
long CuocDt::CALL_FEE = 1000;

class CuocInternet
{
private:
    long luuLuongTruyCap;
public:
    static long INTERNET_PRICE;
    
    long internetUse(){
        cout << "Nhap luu luong truy cap: ";
        cin >> luuLuongTruyCap;
        return INTERNET_PRICE * luuLuongTruyCap; // Cước internet = lưu lượng truy cập (MB) * đơn giá truy cập (200 đồng/MB)
    }
    void datLuongTruyCap(long _luuLuongTruyCap){
        luuLuongTruyCap = _luuLuongTruyCap;
    }
};
long  CuocInternet::INTERNET_PRICE = 200;

class Client
{
private:
    string hoTen;
    string chungMinh;
    string diaChi;
public:
    void dangKy(){
        cin.ignore();
        cout << "Nhap ho va ten: ";
        getline(cin,hoTen);
        cout << "Nhap chung minh nhan dan: ";
        cin >> chungMinh;
        cin.ignore();
        cout << "Nhap dia chi: ";
        cin.ignore();
        getline(cin,diaChi);
    }
    void xuat() const{
        cout << "Ho va ten: " << hoTen << endl;
        cout << "So chung minh nhan dan: " << chungMinh << endl;
        cout << "Dia chi: " << diaChi << endl;
    }
};

class Basic
{
private:
    CuocDt phoneFee;
    CuocInternet internetFee;
public:
    long cuocGoi(){
        return phoneFee.cuocGoi() +  internetFee.internetUse() + static_cast<long>(0.1*CuocDt::CALL_FEE);
    } // Cước tổng = cước điện thoại + cước internet + 10% VAT
};

class DataFree
{
private:
    CuocDt _phoneFee;
    long _luongtruycap;
public:
    static long NGUONG_MIEN_PHI;
    static long CUOC_THUE_BAO;

    long cuocGoi(){
        long phoneFee = _phoneFee.cuocGoi();
        long internetFee = 0;
        if(_luongtruycap > NGUONG_MIEN_PHI)
        {
            CuocInternet result;
            result.INTERNET_PRICE = CuocInternet::INTERNET_PRICE;
            result.datLuongTruyCap(_luongtruycap - NGUONG_MIEN_PHI);
            internetFee = CUOC_THUE_BAO + result.internetUse();
        }
        else
        {
            internetFee = CUOC_THUE_BAO;
        }
        return phoneFee + internetFee;
    }
};

long DataFree::NGUONG_MIEN_PHI = 1000;
long DataFree::CUOC_THUE_BAO = 50;

class DataFix
{
private: 
    CuocDt _PhoneFee;
public:
    static long MUC_CO_DINH;

    long cuocGoi(){
        return static_cast<long>(0.9*(_PhoneFee.cuocGoi())) + MUC_CO_DINH;
    } // Data fix = mức cố định + 10% gói basic
};
long DataFix::MUC_CO_DINH = 1000000;

class Contract
{
private:
    Client _client;
    long choice;
    Basic _basic;
    DataFree _dataFree;
    DataFix _dataFix;
public:
    void dangKy(){
        _client.dangKy();
        cout << "chon goi cuoc:\n" << "1/ Basic\n" << "2/ Data Free\n"
             << "3/ Data Fix\n";
        cin >> choice;
    }
    void xuat(){
        cout << "Khach hang:\n";
        _client.xuat();
        switch (choice)
        {
        case 1:
            cout << _basic.cuocGoi();
            cout << "la so tien cua goi cuoc";
            break;
        case 2:
            cout << _dataFree.cuocGoi();
            cout << "la so tien cua goi cuoc";
            break;
        case 3:
            cout << _dataFix.cuocGoi();
            cout << "la so tien cua goi cuoc";
            break;
        default:
            cout << "goi cuoc khong hop le!";
            break;
        }
    }
};

class Manage
{
    vector<Contract> _ds; // dùng vector để tạo danh sách hợp đồng
public:
    void dangKy(){
        int soLuong;
        cout << "Nhap luong hop dong: ";
        cin >> soLuong;
        for(int index=0;index < soLuong;index++){
            Contract l;
            l.dangKy();
            _ds.push_back(l);
        }
    }
    void thongBao(){
        for(int index=0;index<_ds.size();index++){
            _ds[index].xuat();
        }
    }
};

int main()
{
    Manage kh1;
    kh1.dangKy();
    kh1.thongBao();
    return 0;
}