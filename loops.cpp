#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::string;


int main () {
    vector<vector<int>> a {{1, 2, 3, 4, 5},
        {6,7,8,9,10}};
    for (auto v: a) {
        cout << "top level index" << "\n";
        for (int j: v) {
            cout << "inner index" << "\n";
            cout << j;
            cout << "\n";
        }
    }
}
