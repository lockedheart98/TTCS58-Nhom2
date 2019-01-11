#include <iostream>
#include <vector>
#include <fstream>



using namespace std;


// ===== prototype =====
void xuatMang2d(int arr[100][100], int n, int m);
void readFile(int graph[100][100], int &V);


struct canh {
    int a; // dinh trai
    int b; // dinh phai
    int value;
};


void findMin(vector<canh> &dsCanh, vector<canh> &result, int dinh[], int V, int &vt) {
    int Min = 0;
    for (int i = 0; i < dsCanh.size(); i++) {
        if (dsCanh[Min].value > dsCanh[i].value) {
            Min = i;
        }
    }


    vt++;
    cout << "Min: " << Min << endl;
    dinh[vt] = dsCanh[Min].b;

    // push vao ket qua
    result.push_back(dsCanh[Min]);

    // loai bo canh nho
    dsCanh.erase(dsCanh.begin() + Min);
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

/*
    for (int i = 0; i < dsCanh.size(); i++) {
        if ((tam.a == dsCanh[i].a && tam.b == dsCanh[i].b)  || (tam.a == dsCanh[i].b && tam.b == dsCanh[i].a))
            return 1;
    }

    for (int i = 0; i < result.size(); i++) {
        if ((tam.a == result[i].a && tam.b == dsCanh[i].b) || (tam.a == result[i].b && tam.b == result[i].a))
            return 1;
    }
*/
    return 0;
}


void prim(int graph[100][100], int V) {
    int dinh[V];
    int vt = 0; // vi tri cua ds dinh
    vector<canh> dsCanh; // ds cac canh dang xet
    vector<canh> result; // ket qua
    dinh[vt] = 0; // chon 0 lam diem xuat phat

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

        // check dsCanh
        for (int i = 0 ; i < dsCanh.size(); i++) {
            cout << dsCanh[i].a << " " << dsCanh[i].b << " :" << dsCanh[i].value << endl;
        }
        cout << "=========" << endl;


    }

    // xuat result
    for (int i = 0 ; i < result.size(); i++) {
        cout << result[i].a << " " << result[i].b << endl;
    }
    cout << "=========" << endl;
}



int main() {
    int graph[100][100];
    int V;
/*
    int graph[5][5] =   {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
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
    ifstream inFile("input2.txt");

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
