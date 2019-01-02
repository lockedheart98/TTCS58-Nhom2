#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("input.txt");



// ===== NhanVien =====
class NhanVien {
    string maSo, hoTen;
    int heSoLuong;
    string chucVu;
    int heSoCV;
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
    getline(f, s); maSo = s;
    getline(f, s); hoTen = s;
    getline(f, s); heSoLuong = atoi(s.c_str());
    getline(f, s); chucVu = s;
    getline(f, s); heSoCV = atoi(s.c_str());
}

void NhanVien::xuat() {
    cout << "Ma so: " << maSo << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "He so luong: " << heSoLuong << endl;
    cout << "Chuc vu: " << chucVu << endl;
    cout << "He so chuc vu: " << heSoCV << endl;
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
    for (int i = 0; i < ds.size(); i++) {
        ds[i].xuat();
        cout << "=====" << endl;
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

    cout << "Bang Luong: " << endl;
    for (int i = 0; i < ds.size(); i++) {
        cout << "Ma so: " << ds[arr[i]].maSo << endl;
        cout << "Ho ten: " << ds[arr[i]].hoTen << endl;
        cout << "Luong: " << ds[arr[i]].tinhLuong() << endl;
        cout << "=====" << endl;
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
    cout << "Da xoa nhan vien: " << endl;
    ds.xoaNhanVien("14");
    ds.xuatDs();
}
