#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>

#include <iterator>
#include <sstream>

using namespace std;

ifstream f("input.txt");



// ===== NhanVien =====
class NhanVien {
    string maSo, hoTen;
    int heSoLuong;
    string chucVu;
    int heSoCV;
    string thang, nam;
    static int luongCoBan;
public:
    void nhap();
    void xuat();
    int tinhLuong();
    friend class DSNV;
};

int NhanVien::luongCoBan = 1100;




void NhanVien::nhap() {
    string s;
    string line;

    stringstream ss;

    getline(f, line);
    ss.str(line);


    getline(ss, s, ';'); maSo = s;
    getline(ss, s, ';'); hoTen = s;
    getline(ss, s, ';'); heSoLuong = atoi(s.c_str());
    getline(ss, s, ';'); chucVu = s;
    getline(ss, s, ';'); heSoCV = atoi(s.c_str());
    getline(ss, s, ';'); thang = s;
    getline(ss, s, ';'); nam = s;
}

void NhanVien::xuat() {
    cout << setw(10) << left << maSo;
    cout << setw(20) << left << hoTen ;
    cout << setw(15) << left << heSoLuong;
    cout << setw(10) << left << chucVu;
    cout << setw(10) << left << heSoCV;
    cout << setw(15) << left << tinhLuong();
    cout << setw(6) << left << thang;
    cout << setw(6) << left << nam;
    cout << endl;

}

int NhanVien::tinhLuong() {
    return luongCoBan* (heSoLuong + heSoCV);
}

// ===== DSNV =====

class DSNV {
    int n;
    vector <NhanVien> ds;
public:
    void nhapDs();
    void xuatDs();
    void inLuongTangDan();
    NhanVien timKiem(string ms);
    void xoaNhanVien(string ms);
};

void DSNV::nhapDs() {
    if (f.fail()) {
        cout << "Faild to open this file !" << endl;
    } else {
        string s;
        getline(f, s); n = atoi(s.c_str());
        ds.resize(n);
        for (int i = 0; i < ds.size(); i++) {
            ds[i].nhap();
        }
    }

    f.close();
}
void DSNV::xuatDs() {
    cout << "DANH SACH NHAN VIEN" << endl;
    cout << setw(10) << left << "Ma so";
    cout << setw(20) << left << "Ho ten" ;
    cout << setw(15) << left << "He so luong";
    cout << setw(10) << left << "Chuc vu";
    cout << setw(10) << left << "He so CV";
    cout << setw(15) << left << "Luong";
    cout << setw(6) << left << "Thang";
    cout << setw(6) << left << "Nam";
    cout << endl;
    for (int i = 0; i < ds.size(); i++) {
        ds[i].xuat();
    }
}


void DSNV::inLuongTangDan() {
    int arr[ds.size()]; // mang chua thu tu cua nhan vien
    for (int i = 0; i < ds.size(); i++) {
        arr[i] = i;
    }

    for (int i = 0; i < ds.size()-1; i++)
        for (int j = 0; j < ds.size()-i-1; j++) {
            if (ds[arr[j]].tinhLuong() < ds[arr[j+1]].tinhLuong())
                swap(arr[j], arr[j+1]);
        }

    cout << "Sap Xep Theo Luong: " << endl;
    cout << setw(10) << left << "Ma so";
    cout << setw(20) << left << "Ho ten" ;
    cout << setw(15) << left << "He so luong";
    cout << setw(10) << left << "Chuc vu";
    cout << setw(10) << left << "He so CV";
    cout << setw(15) << left << "Luong";
    cout << setw(6) << left << "Thang";
    cout << setw(6) << left << "Nam";
    cout << endl;

    for (int i = 0; i < ds.size(); i++) {
        cout << setw(10) << left << ds[arr[i]].maSo;
        cout << setw(20) << left << ds[arr[i]].hoTen ;
        cout << setw(15) << left << ds[arr[i]].heSoLuong;
        cout << setw(10) << left << ds[arr[i]].chucVu;
        cout << setw(10) << left << ds[arr[i]].heSoCV;
        cout << setw(15) << left << ds[arr[i]].tinhLuong();
        cout << setw(6) << left << ds[arr[i]].thang;
        cout << setw(6) << left << ds[arr[i]].nam;
        cout << endl;
/*
        cout << "Ma so: " << ds[arr[i]].maSo << endl;
        cout << "Ho ten: " << ds[arr[i]].hoTen << endl;
        cout << "Luong: " << ds[arr[i]].tinhLuong() << endl;
        cout << "=====" << endl;
*/
    }

}


NhanVien DSNV::timKiem(string ms) {
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].maSo == ms)
            return ds[i];
    }
    cout << "Khong tim thay nhan vien" << endl;
}

void DSNV::xoaNhanVien(string ms) {
    for (int i = 0 ; i < ds.size() ; i++) {
        if (ds[i].maSo == ms) {
            ds.erase(ds.begin() + i);
        }
    }

};


int main() {
    DSNV ds;
    ds.nhapDs();
    ds.xuatDs();
    ds.inLuongTangDan();
    cout << "Tim kiem Nhan vien: " << endl;
    ds.timKiem("13").xuat();
    cout << "Da xoa nhan vien. " << endl;
    ds.xoaNhanVien("13");
    ds.xuatDs();
    ds.timKiem("13").xuat();

}
