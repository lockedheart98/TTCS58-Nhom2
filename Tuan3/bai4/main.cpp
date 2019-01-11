#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;

struct canh {
    int a; // dinh trai
    int b; // dinh phai
    int value;
};

// ===== prototype =====
void xuatMang2d(int arr[100][100], int n, int m);
void readFile(int graph[100][100], int &V);
void writeFile(vector<canh> result);
int sum(vector<canh> result);
bool isExist(int dinh[], int vt, canh tam);
void findMin(vector<canh> &dsCanh, vector<canh> &result, int dinh[], int V, int &vt);
void prim(int graph[100][100], int V);



int main() {
    int graph[100][100];
    int V; // kich thuoc mang ( so dinh )
/*
    Mo ta thuat toan prim theo cach giai tay

    Cau tru thu muc
    dong dau tien la so dinh
    Các dòng sau là ma trận
    Ma tran the hien khoang cach giua cac dinh
    vd: graph[1][0] -> khoang cach giua 2 dinh [1,0] la: 2


    int graph[5][5] =   {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    tuong duong cac canh:
    [0,1] = 2
    [0,3] = 6
    [1,2] = 3
    [1,3] = 8
    [1,4] = 5
    [2,4] = 7
    [3,4] = 9
*/
    readFile(graph, V);
    xuatMang2d(graph, V, V);
    prim(graph, V);
    return 0;
}

// ===== function =====

void xuatMang2d(int arr[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void readFile(int graph[100][100], int &V) {
    ifstream inFile("input.txt"); // chuyen thanh input2.txt giai cay khung 2

    if (inFile.fail()) {
        cout << "Failed to open this file." << endl;
    } else {
        inFile >> V;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                inFile >> graph[i][j];
        }
    }
}

void writeFile(vector<canh> result) {
    ofstream outFile("output.txt");

    for (int i = 0; i < result.size(); i++) {
        outFile << "[" << result[i].a << "," <<  result[i].b << "]" << ":" << result[i].value << endl;
    }
    outFile << "Tong trong so: " << sum(result) << endl;
}

int sum(vector<canh> result) {
    int sum = 0;
    for (int i = 0; i < result.size(); i++)
        sum += result[i].value;
    return sum;
}

bool isExist(int dinh[], int vt, canh tam) {
    for (int i = 0; i < vt + 1; i++ ) { // vt dang la chi so hien tai cua dinh => + 1
        if (tam.a == dinh[i]) {
            for (int j = 0 ; j < vt + 1; j++)
                if (tam.b == dinh[j])
                    return 1;
        }
        if (tam.b == dinh[i]) {
            for (int j = 0; j < vt + 1; j++)
                if (tam.a == dinh[j])
                    return 1;
        }
    }

    return 0;
}

void findMin(vector<canh> &dsCanh, vector<canh> &result, int dinh[], int V, int &vt) {
    int Min = 0;
    // tim ra vi tri canh nho nhat
    for (int i = 0; i < dsCanh.size(); i++) {
        if (dsCanh[Min].value > dsCanh[i].value) {
            Min = i;
        }
    }

    // ghi dinh da xet
    vt++;
    dinh[vt] = dsCanh[Min].b;

    // push vao ket qua
    result.push_back(dsCanh[Min]);


    // Mo phong
    cout << endl << "Them cac canh ke dinh " << dinh[vt - 1] << " vao danh sach: " << "(Tru cac canh da tung them vao)" << endl;
    for (int i = 0 ; i < dsCanh.size(); i++) {
        cout << "[" << dsCanh[i].a << "," << dsCanh[i].b << "]";
    }
    cout << endl << "Canh nho nhat la: ";
    cout << "[" << dsCanh[Min].a << "," << dsCanh[Min].b << "]";
    cout << " -> chon vao ket qua" << endl;

    cout << "Loai canh ";
    cout << "[" << dsCanh[Min].a << "," << dsCanh[Min].b << "]";
    cout << " ra khoi danh sach" << endl;
    cout << "Chon dinh " << dsCanh[Min].b << " de xet cac canh them vao." << endl;

    // loai bo canh nho nhat
    dsCanh.erase(dsCanh.begin() + Min);
}

void prim(int graph[100][100], int V) {
    int dinh[V]; // cac dinh da xet
    int vt = 0; // vi tri cua ds dinh
    vector<canh> dsCanh; // ds cac canh dang xet
    vector<canh> result; // ket qua
    dinh[vt] = 0; // chon 0 lam diem xuat phat

    // Mo phong
    cout << "Bat dau tu dinh 0" << endl;

    // push canh
    for (int j = 0 ; j < V - 1; j++) {          // lap toi da V - 1 ( vi khong duong lon hon so dinh)
        for (int i = 0 ; i < V; i++ ) {
            if (graph[dinh[vt]][i]) {
                canh tam;
                tam.a = dinh[vt]; // a la dinh
                tam.b = i; // i la vi tri canh b
                tam.value = graph[dinh[vt]][i];

                // kiem tra trung lap
                if (!isExist(dinh, vt, tam))
                    dsCanh.push_back(tam);
            }
        }

        // tim canh nho nhat
        findMin(dsCanh, result, dinh, V, vt);
    }

    // Mo phong
    cout << endl << "Ket qua: " << endl;
    for (int i = 0 ; i < result.size(); i++) {
        cout << "[" << result[i].a << "," << result[i].b << "] ";
    }
    cout << endl << "Tong trong so: " << sum(result);

    writeFile(result);
}
