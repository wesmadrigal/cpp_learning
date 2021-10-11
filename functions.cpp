#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::string;


int AddVect(vector<int> v) {
    int sum = 0;
    for (int i=0; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum;
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6};

    cout << AddVect(v) << "\n";

}
