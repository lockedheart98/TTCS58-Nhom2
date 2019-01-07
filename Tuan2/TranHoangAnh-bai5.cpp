#include <stdio.h>
#include <math.h>
#include <winbgim.h>
#include <iostream>
#include <string.h>
using namespace std;

class Toado{
	public:
		int x, y;
		void Nhap(){
			cout<<"x: ";
			cin>>x;
			cout<<"y: ";
			cin>>y;
		}
};

class Hinh {
	protected:
		Toado a;
	public:
		void Ve() {}
};


class DuongThang:public Hinh {
	Toado b;
	public:
		void Nhap() {
			cout << "Toa do diem dau: " << endl;
			a.Nhap();
			cout << "Toa do diem cuoi: " << endl;
			b.Nhap();
		}
		void Ve() {
			Hinh::Ve();
			line(a.x, a.y, b.x, b.y);
		}
};

class Tron:public Hinh {
	int banKinh;
	public:
		void Nhap() {
			cout << "nhap toa do: " << endl;
			a.Nhap();
			cout << "nhap ban kinh: " << endl;
			cin >> banKinh;
		}
		void Ve() {
			Hinh::Ve();
			circle(a.x, a.y, banKinh);
		}

};

class ChuNhat:public Hinh {
	Toado b;
	public:
		void Nhap() {
			cout << "Nhap toa do trai tren: " << endl;
			a.Nhap();
			cout << "Nhap toa do phai duoi: " << endl;
			b.Nhap();
		}
		void Ve() {
			Hinh::Ve();
			rectangle(a.x, a.y, b.x, b.y);
		}
};

class Vuong: public Hinh {
	Toado b;
	public:
		void Nhap() {
			do {
				cout << "Nhap toa do trai tren: " << endl;
				a.Nhap();
				cout << "Nhap toa do phai duoi: " << endl;
				b.Nhap();

				// kt
				if (abs(a.x - b.x) != abs(a.y - b.y)) {
					cout << "Khong phai hinh vuong: " << endl;
				}
			} while(abs(a.x - b.x) != abs(a.y - b.y));

		}
		void Ve() {
			Hinh::Ve();
			rectangle(a.x, a.y, b.x, b.y);
		}
};

class TamGiac:public Hinh {
	Toado b, c;
	public:
		void Nhap() {
			cout << "Nhap toa do diem 1: " << endl;
			a.Nhap();
			cout << "Nhap toa do diem 2: " << endl;
			b.Nhap();
			cout << "Nhap toa do diem 3: " << endl;
			c.Nhap();
		}
		void Ve() {
			line(a.x, a.y, b.x, b.y);
			line(b.x, b.y, c.x, c.y);
			line(c.x, c.y, a.x, a.y);
		}
};


int main(){
	DuongThang dt;
	Tron tr;
	ChuNhat cn;
	Vuong v;
	TamGiac tg;
	int opt; // lua chon

	initwindow(800, 600);
    cleardevice();

    cout << "Chon hinh muon ve: " << endl;
    cout << "1. Duong thang" << endl;
    cout << "2. Tron" << endl;
	cout << "3. Chu nhat" << endl;
	cout << "4. Vuong" << endl;
	cout << "5. Tam giac" << endl;
			cout << "Nhap lua chon: ";
		cin >> opt;

		switch(opt) {
			case 1:
				dt.Nhap();
				dt.Ve();
				break;
			case 2:
				tr.Nhap();
				tr.Ve();
				break;
			case 3:
				cn.Nhap();
				cn.Ve();
				break;
			case 4:
				v.Nhap();
				v.Ve();
				break;
			case 5:
				tg.Nhap();
				tg.Ve();
				break;
		}
/*
	do {
		cout << "Nhap lua chon: ";
		cin >> opt;

		switch(opt) {
			case 1:
				dt.Nhap();
				dt.Ve();
				break;
			case 2:
				tr.Nhap();
				tr.Ve();
				break;
			case 3:
				cn.Nhap();
				cn.Ve();
				break;
			case 4:
				v.Nhap();
				v.Ve();
				break;
			case 5:
				tg.Nhap();
				tg.Ve();
				break;
		}
	} while (opt != 0);

*/


    return 0;
}
