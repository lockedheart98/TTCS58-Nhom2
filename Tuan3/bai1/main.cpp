#include <iostream>
#include <ctime>

using namespace std;

int taoNgauNhien(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

}

void xuatMang(int arr[], int n) {
    for (int i = 0 ; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



void timNgauNhien(int arr[], int m) {
    int n;
    do {
        cout << "nhap n: ";
        cin >> n;
    } while(n >= m);


    int check[m];

    for (int i = 0; i < m; i++) {
        check[i] = 0;
    }
    int dem = 0;
    int tam;
    while(dem < n) {
        tam = rand() % m;

        if (!check[tam]) {  // kiem tra de khong lap lai vi tri da xuat
            cout << arr[tam] << " ";
            dem++;
            check[tam] = 1;
        } //else  cout << "fail" << tam << endl;
    }
}

int main() {
    srand(time(NULL)); // tao real random
    int n, m;
    cout << "nhap m: ";
    cin >> m;


    int arr[m];
    taoNgauNhien(arr, m);
    xuatMang(arr, m);
    timNgauNhien(arr, m);

}
