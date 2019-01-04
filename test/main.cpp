#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s); // stream data
    string item; // string put data into

    while (getline(ss, item, delim)) { //
        cout << item << endl;
        elems.push_back(item); // push to vector
    }
}

int main() {
    ifstream infile ("input.txt");

    string line;

    while (getline(infile, line))
    {
        vector<string> row_values;

        split(line, ',', row_values);

        for (auto v: row_values)
            cout << v << ',' ;

        cout << endl;
     }

    return 0;
}
