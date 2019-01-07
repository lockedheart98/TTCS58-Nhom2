#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
void xuatMang(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void nhap(int phong[], int lop[], int &nP, int &nL) {
    ifstream inputFile("input.txt");

    if (inputFile.fail()) {
        cout << "Faild to open this file !" << endl;
    } else {
        inputFile >> nP;
        //cout << "nP: " << nP << endl;

        for (int i = 0 ; i < nP; i++) {
            inputFile >> phong[i];
        }


        inputFile >> nL;
        //cout << "nL: " << nL << endl;

        for (int i = 0 ; i < nL; i++) {
            inputFile >> lop[i];
        }

    }
    inputFile.close();

}

void taoSoHieu(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}


void thamLam(int phong[], int lop[], int nP, int nL, int soHieuP[], int soHieuL[]) {
    if (nP > nL) {
        swap(nP, nL);
    }

    int solanChuyenGhe = 0;

    ofstream outputFile("output.txt");

    for (int i = 0; i < nP; i++) {
        cout << "Phong " << soHieuP[i] << ":Lop " << soHieuL[i] << endl;
        solanChuyenGhe += abs(phong[soHieuP[i]] - lop[soHieuL[i]]);
        cout << phong[soHieuP[i]] << "-" << lop[soHieuL[i]] << endl;
        cout << "so lan chuyen ghe: " << solanChuyenGhe << endl;
        outputFile << soHieuP[i] << " " <<  soHieuL[i] << endl;
    }
    outputFile << solanChuyenGhe;
}

void cachKhac(int phong[], int lop[], int nP, int nL, int soHieuP[], int soHieuL[]) {
    //
}



void thucHien(int phong[], int lop[], int nP, int nL) {
    int phongDaSuDung[nP];
    int soHieuP[nP];
    int soHieuL[nL];

    taoSoHieu(soHieuP, nP);
    taoSoHieu(soHieuL, nL);

    // sap xep
    for (int i = 0; i < nL-1; i++) {
        for (int j = 0; j < nL-i-1; j++) {
            if (lop[soHieuL[j]] < lop[soHieuL[j+1]])
                swap(soHieuL[j], soHieuL[j+1]);
        }
    }

    // sap xep
    for (int i = 0; i < nP-1; i++) {
        for (int j = 0; j < nP-i-1; j++) {
            if (phong[soHieuP[j]] < phong[soHieuP[j+1]])
                swap(soHieuP[j], soHieuP[j+1]);
        }
    }
    xuatMang(soHieuL, nL);
    xuatMang(soHieuP, nP);

    thamLam(phong, lop, nP, nL, soHieuP, soHieuL);



}


int main() {
    int phong[100], lop[100];
    int nP, nL;
    nhap(phong, lop, nP, nL);
    cout << nP << " " << nL << endl;
    //xuatMang(phong, nP);
    //xuatMang(lop, nL);
    thucHien(phong, lop, nP, nL);


}
