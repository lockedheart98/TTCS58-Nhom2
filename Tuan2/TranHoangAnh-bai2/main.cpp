#include <iostream>
#include <string>
#include <stack>

#include "bignum.h"

using namespace std;




int main() {


    int opt = 99;
    string a, b;
    while (opt) {
        cout << "1. Cong" << endl;
        cout << "2. Tru" << endl;
        cout << "3. Nhan" << endl;
        cout << "0. Thoat" << endl;

        cin >> opt;
        cin.ignore(1000,'\n');
        switch(opt) {
            case 1:
                cout << "Nhap a: ";
                getline(cin, a);
                cout << "Nhap b: ";
                getline(cin, b);
                cout << cong(a, b) << endl;
                break;
            case 2:
                cout << "Nhap a: ";
                getline(cin, a);
                cout << "Nhap b: ";
                getline(cin, b);
                cout << tru(a, b) << endl;
                break;
            case 3:
                cout << "Nhap a: ";
                getline(cin, a);
                cout << "Nhap b: ";
                getline(cin, b);
                cout << nhan(a, b) << endl;
                break;
        }
    }
}

