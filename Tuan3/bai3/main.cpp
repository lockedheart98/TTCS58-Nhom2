#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include <iterator>
#include <sstream>



#define customer "customer.txt"
#define transaction "trans.txt"



using namespace std;

class KhachHang {
    string id, hoTen;
    double soDu;
public:
    KhachHang() {} // default contructor
    KhachHang(string id, string hoTen, double soDu) {
        this->id = id;
        this->hoTen = hoTen;
        this->soDu = soDu;
    }
    friend class XuLy;
};

class GiaoDich {
    string id;
    bool loaiGD; // 1 = rut, 0 = gui
    double soLuong;
public:
    GiaoDich() {}
    GiaoDich(string id, bool loaiGD, double soLuong) {
        this->id = id;
        this->loaiGD = loaiGD;
        this->soLuong = soLuong;
    }
    friend class XuLy;
};

class XuLy {
    vector<KhachHang> dskh;
    vector<GiaoDich> dsgd;
public:
    void formInputKH(); // *
    void formInputGD(bool loaiGD); // *
    bool themKH(KhachHang kh); // * them 1 khach hang
    bool themGD(GiaoDich gd); // * them 1 giao dich
    void inKH(KhachHang kh); // * in thong tin 1 khach hang
    void inDSKH(); // * in danh sach khach hang
    void inSaoKe(string mskh); // *
    void docFileKH(); // *
    void docFileGD(); // *
    void ghiFileKH(); // *
    void ghiFileGD(); // *
};



int main() {
    XuLy xl;
    xl.docFileKH();
    xl.docFileGD();
    xl.inDSKH();

    int opt = 99;
    do {
        cout << "1. Dang ky tai khoan" << endl;
        cout << "2. Gui tien" << endl;
        cout << "3. Rut tien" << endl;
        cout << "4. In danh sach khach hang" << endl;
        cout << "5. In sao ke" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> opt;
        cin.ignore(1000,'\n');
        switch(opt) {
            case 1:
                xl.formInputKH();
                break;
            case 2:
                xl.formInputGD(0);
                break;
            case 3:
                xl.formInputGD(1);
                break;
            case 4:
                xl.inDSKH();
                break;
            case 5: {
                    string maSo;
                    cout << "nhap ma so" << endl;
                    getline(cin, maSo);
                    xl.inSaoKe(maSo);
                }
                break;
        }
    } while(opt != 0);

}

// ===== function =====


    // === XuLy ===
void XuLy::formInputKH() {
    string maSo, hoTen;

    cout << "nhap ma so: ";
    getline(cin, maSo); // check maso || tao random
    cout << "nhap ho ten: ";
    getline(cin, hoTen);

    KhachHang kh(maSo, hoTen, 0);

    if (themKH(kh)) {
        cout << "Them thanh cong" << endl;
    } else cout << "Khong thuc hien duoc" << endl;
}

void XuLy::formInputGD(bool loaiGD) {
    string maSo;
    double soLuong;

    cout << "Nhap ma so: ";
    getline(cin, maSo);
    cout << "nhap so luong: ";
    cin >> soLuong;

    GiaoDich gd(maSo, loaiGD, soLuong);

    if (themGD(gd)) {
        cout << "Them thanh cong" << endl;
    } else cout << "Khong thuc hien duoc" << endl;
}

bool XuLy::themKH(KhachHang kh) {
    dskh.push_back(kh);
    ghiFileKH();

    return 1;
}

bool XuLy::themGD(GiaoDich gd) {
    for (int i = 0; i < dskh.size(); i++) {
        if (dskh[i].id == gd.id) { // tim khach hang
            if (gd.loaiGD == 1) {   // loai gd = rut
                if (dskh[i].soDu >= gd.soLuong) // du so du
                    dskh[i].soDu -= gd.soLuong;
                else return 0;  // khong du so du
            } else {    // loai gd = gui
                dskh[i].soDu += gd.soLuong;
            }

            dsgd.push_back(gd);
            ghiFileGD();
            ghiFileKH();
            return 1;
        }
    }
    return 0;
}

void XuLy::inKH(KhachHang kh) {
    cout << setw(10) << left << kh.id;
    cout << setw(15) << left << kh.hoTen;
    cout << setw(15) << left << kh.soDu;
    cout << endl;
}

void XuLy::inDSKH() {
    cout << "DANH SACH KHACH HANG" << endl;
    cout << setw(10) << left << "Ma so";
    cout << setw(15) << left << "Ho ten" ;
    cout << setw(15) << left << "So du";
    cout << endl;

    for (int i = 0; i < dskh.size(); i++) {
        inKH(dskh[i]);
    }
}

void XuLy::inSaoKe(string mskh) {
    cout << "SAO KE" << endl;
    cout << setw(10) << left << "Ma so";
    cout << setw(10) << left << "Loai gd" ;
    cout << setw(15) << left << "So luong";
    cout << endl;

    for (int i = 0; i < dsgd.size(); i++) {
        if (dsgd[i].id == mskh) {
            cout << setw(10) << left << dsgd[i].id;
            if (dsgd[i].loaiGD == 1) {
                cout << setw(10) << left << "Rut" ;
            } else cout << setw(10) << left << "Gui" ;
            cout << setw(15) << left << dsgd[i].soLuong;
            cout << endl;
        }
    }
}

void XuLy::docFileKH() {

    ifstream infile;
    infile.open(customer);

    if (infile.fail()) {
        cout << "Faild to open this file !" << endl;
    } else {

        KhachHang tam;
        while(!infile.eof()) {
            string s;
            string line;
            stringstream ss;

            getline(infile, line);
            ss.str(line);

            getline(ss, s, ';'); tam.id = s;
            getline(ss, s, ';'); tam.hoTen = s;
            getline(ss, s, ';'); tam.soDu = atoi(s.c_str());
            dskh.push_back(tam);
        }
        dskh.erase(dskh.begin() + dskh.size()); // delete last empty element
    }

    infile.close();
}

void XuLy::docFileGD() {
    ifstream infile;
    infile.open(transaction);

    if (infile.fail()) {
        cout << "Faild to open this file !" << endl;
    } else {
        GiaoDich tam;;
        while(!infile.eof()) {
            string s;
            string line;
            stringstream ss;

            getline(infile, line);
            ss.str(line);

            getline(ss, s, ';'); tam.id = s;
            getline(ss, s, ';'); tam.loaiGD = atoi(s.c_str());
            getline(ss, s, ';'); tam.soLuong = atoi(s.c_str());

            dsgd.push_back(tam);
        }
        dsgd.erase(dsgd.begin() + dsgd.size()); // delete last empty element
    }
}

void XuLy::ghiFileKH() {
    ofstream outfile;
    outfile.open(customer);

    if (outfile.eof()) {
        cout << "Faild to open this file !" << endl;
    } else {
        for (int i = 0; i < dskh.size(); i++) {
            outfile << dskh[i].id << ";" << dskh[i].hoTen << ";" << dskh[i].soDu << endl;
        }
    }

    outfile.close();
}

void XuLy::ghiFileGD() {
    ofstream outfile;
    outfile.open(transaction);

    if (outfile.eof()) {
        cout << "Faild to open this file !" << endl;
    } else {
        for (int i = 0; i < dsgd.size(); i++) {
            outfile << dsgd[i].id << ";" << dsgd[i].loaiGD << ";" << dsgd[i].soLuong << endl;
        }
    }

    outfile.close();
}
