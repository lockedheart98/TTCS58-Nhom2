#include <iostream>
#include <fstream>

#define path "output1.txt"

using namespace std;

// ===== prototype =====

int taoNgauNhien(int arr[50][50], int &n, int &m);
void xuatMang(int arr[50][50], int n, int m);
void xoaDong(int arr[50][50], int &n, int &m, int x);
void xoaCot(int arr[50][50], int &n, int &m, int x);
bool doiXung(int arr[50][50], int n, int m);
bool cheoChinh(int arr[50][50], int n, int m, int p1, int p2);
bool cheoPhu(int arr[50][50], int n, int m, int p1, int p2);
bool ngangDoc(int arr[50][50], int n, int m, int p1, int p2);
void soHoangHau(int arr[50][50], int n, int m);










int main() {
    int arr[50][50];
/*
    {
        {2, 2, 7},
        {2, 1, 6},
        {5, 6, 2}
    }
*/
    int n, m;
    taoNgauNhien(arr, n, m);
    xuatMang(arr, n, m);
    soHoangHau(arr, n, m);
    xoaCot(arr, n, m, 1);
    xoaDong(arr, n, m, 1);
    cout << "doi xung: " << doiXung(arr, n, m) << endl;
    cout << "check: " << ngangDoc(arr, n, m, 2, 2) << endl;
    xuatMang(arr, n, m);
}


// ===== function =====

int taoNgauNhien(int arr[50][50], int &n, int &m) {
    cout << "Nhap n: ";
    cin >> n;
    m = n;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 50 + 1;
        }
    }
}

void xuatMang(int arr[50][50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void xoaDong(int arr[50][50], int &n, int &m, int x) {
    for (int i = x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i+1][j];
        }
    }
    n--;
}

void xoaCot(int arr[50][50], int &n, int &m, int x) {
    for (int i = 0; i < n; i++) {
        for (int j = x; j < m - 1; j++) {
            arr[i][j] = arr[i][j+1];
        }
    }
    m--;
}

bool doiXung(int arr[50][50], int n, int m) {
    for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i][j] != arr[j][i])
				return 0;
	return 1;
}

bool cheoChinh(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];

    int tmp1 = p1 - 1;
    int tmp2 = p2 - 1;
    // cheo chinh tren
    while(tmp1 >= 0 && tmp2 >= 0) {
        if (x < arr[tmp1][tmp2])
            return 0;
        tmp1--;
        tmp2--;
    }

    tmp1 = p1 + 1;
    tmp2 = p2 + 1;
    // cheo chinh duoi
    while(tmp1 < n && tmp2 < m) {
        if (x < arr[tmp1][tmp2])
            return 0;
        tmp1++;
        tmp2++;
    }

    return 1;
}

bool cheoPhu(int arr[50][50], int n, int m, int p1, int p2) {
    int x = arr[p1][p2];

    int tmp1 = p1 - 1;
    int tmp2 = p2 + 1;
    // cheo phu tren
    while(tmp1 >= 0 && tmp2 < m) {
        if (x < arr[tmp1][tmp2])
            return 0;
        tmp1--;
        tmp2++;
    }

    tmp1 = p1 + 1;
    tmp2 = p2 - 1;
    // cheo phu duoi
    while(tmp1 < m && tmp2 >= 0) {
        if (x < arr[tmp1][tmp2])
            return 0;
        tmp1++;
        tmp2--;
    }

    return 1;
}

bool ngangDoc(int arr[50][50], int n, int m, int p1, int p2) {

    int x = arr[p1][p2];

    // ngang
    for (int i = p2 - 1; i >= 0 ; i--) {
        if (x < arr[p1][i])
            return 0;
    }
    for (int i = p2 + 1; i < m ; i++) {
        if (x < arr[p1][i])
            return 0;
    }

    // doc
    for (int i = p1 - 1; i >= 0; i--) {
        if (x < arr[i][p2])
            return 0;
    }
    for (int i = p1 + 1; i < n; i++) {
        if (x < arr[i][p2])
            return 0;
    }

    return 1;
}

void soHoangHau(int arr[50][50], int n, int m) {
    ofstream outfile;
    outfile.open(path);

    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            if (ngangDoc(arr, n, m, i, j) && cheoChinh(arr, n, m, i, j) && cheoPhu(arr, n, m, i, j)) {
                outfile << i << " " << j <<  " " << arr[i][j] << endl;
            }
        }
    }

    outfile.close();
}
