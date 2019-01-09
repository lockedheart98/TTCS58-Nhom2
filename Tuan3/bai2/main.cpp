#include <windows.h>
#include <iostream>
//setColor
using namespace std;
int main() {
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k=0;k<=255;k++) {
        SetConsoleTextAttribute(hConsoleColor, k);
        cout << k << " - Change color!  ";
        if (k%3==0) cout << endl;
    }
    return 0;
}
