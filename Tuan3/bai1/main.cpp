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



void timNgauNhien(int arr[], int n, int x) {
    int check[n];
    for (int i = 0; i < n; i++) {
        check[i] = 0;
    }
    int dem = 0;
    int tam;
    while(dem < x) {
        tam = rand() % n;

        if (!check[tam]) {
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
    do {
        cout << "nhap n: ";
        cin >> n;
    } while(n >= m);

    int arr[m];
    taoNgauNhien(arr, m);
    xuatMang(arr, m);
    timNgauNhien(arr, m, n);

}
