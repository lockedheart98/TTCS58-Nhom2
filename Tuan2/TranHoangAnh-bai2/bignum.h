#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED



#endif // BIGNUM_H_INCLUDED


#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ===== prototype =====
void hienThiStack(stack<int> t);
stack<int> chuyenDoi(string s);
string chuyenDoi2(stack<int> t);
string cong(string tmp1, string tmp2);
string tru(string tmp1, string tmp2);
string nhan(string tmp1, string tmp2);
void popAll(stack<int> &t);


// ===== function =====
void hienThiStack(stack<int> t) {
    while(!t.empty()) {
        cout << t.top();
        t.pop();
    }
}

stack<int> chuyenDoi(string s) {
    stack<int> t;
    for(int i = 0; i < s.size(); i++) {
        t.push(s[i]-48); // tu ky tu => so  -48
    }

    return t;
}

string chuyenDoi2(stack<int> t) {
    string str;
    while(!t.empty()) {
        str += t.top() + 48;
        t.pop();
    }
    return str;
}

string cong(string tmp1, string tmp2) {
    stack<int> a;
    stack<int> b;
    stack<int> result;
    string str;


    a = chuyenDoi(tmp1);
    b = chuyenDoi(tmp2);

    // m: so nho, s: ket qua cong 2 so
    int m = 0, s;

    while(!a.empty() || !b.empty()) {

        if (!a.empty() && !b.empty()) {
            s = a.top() + b.top() + m;

            if (s >= 10) {
                m = 1;
                s %= 10;
            } else m = 0;

            a.pop();
            b.pop();

        } else if (!a.empty() && b.empty()) { // stack a empty
            s = a.top() + m;

            if (s >= 10) {
                m = 1;
                s %= 10;
            } else m = 0;

            a.pop();
        } else if (a.empty() && !b.empty()) { // stack b empty
            s = b.top() + m;
            if (s >= 10) {
                m = 1;
                s %= 10;
            } else m = 0;

            b.pop();
        }

        result.push(s); // push to result
    }

    // if m is exist
    if (m) {
        result.push(m);
    }

    while(!result.empty()) {
        str += result.top() + 48;
        result.pop();
    }

    return str;
}

string tru(string tmp1, string tmp2) {

    stack<int> a;
    stack<int> b;
    stack<int> result;

    string str = "";

    while(tmp1.length() < tmp2.length()) {
        tmp1 = "0" + tmp1;
    }
    while(tmp1.length() > tmp2.length()) {
        tmp2 = "0" + tmp2;
    }

    // check negative
    bool ngt = 0;
    if (tmp1 < tmp2) {
        swap(tmp1, tmp2);
        ngt = 1;
    }


    a = chuyenDoi(tmp1);
    b = chuyenDoi(tmp2);

    int m = 0, s;
    while(!a.empty() || !b.empty()) {
        if (a.top() < (b.top() + m)) {
            //cout << a.top() << "-" << b.top() + m << endl;
            s = (a.top() + 10) - (b.top() + m);
            m = 1;
        } else {
            //cout << a.top() << "-" << b.top() + m << endl;
            s = a.top() - (b.top()+m);
            m = 0;
        }
        a.pop();
        b.pop();

        result.push(s);
    }


    // delete 0 in front
    bool flag = 0;
    string tmp;
    while(!result.empty()) {
        tmp = result.top()+48;
        if ((tmp) != "0") {
            str += tmp;
            flag = 1;
        } else if (flag){
            str += tmp;
        }
        result.pop();
    }


    // add -
    if (ngt) {
        str = "-" + str;
    }

    return str;
}


string nhan(string tmp1, string tmp2) {
    stack<int> a;
    stack<int> b;
    stack<int> result;
    string str = "0";


    a = chuyenDoi(tmp1);
    b = chuyenDoi(tmp2);

    int s = 0; // ket qua nhan 2 so

    string tmp; // ket qua sau khi nhan 1 don vi stack a
    int dem = 0;
    while(!b.empty()) {
        a = chuyenDoi(tmp1); // khoi phuc lai stack a
        int m = 0; // so nho
        int n = 0; // so hang don vi
        while(!a.empty()) {
            s = b.top() * a.top();
            n = s%10 + m;
            m = 0;
            m += s/10;

            // kiem tra n > 10
            if (n / 10) {
                n = n%10;
                m++;
            }

            result.push(n);
            a.pop();
        }

        //
        if (m) {
            result.push(m);
        }
        // sau khi chuyen tu stack -> string
        // thuc hien clear stack
        tmp = chuyenDoi2(result);

        //hienThiStack(result);
        popAll(result); // clear stack


        // them so 0 tuong tung vao moi ket qua nhan
        for (int i = 0; i < dem; i++) {
            tmp = tmp + "0";
        }
        dem++;

        // thuc hien cong lai
        //cout << str << "+" << tmp << endl;
        str = cong(str, tmp);

        b.pop();
    }

    return str;
}

void popAll(stack<int> &t) {
    while(!t.empty()) {
        t.pop();
    }
}
