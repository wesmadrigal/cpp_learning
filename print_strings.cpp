#include <iostream>
#include <string>
using std::cout;
using std::string;

void PrintStrings(string s1, string s2) {
    cout << s1;

    cout << s2;
}

int main() {

    string s1 = "C++ is ";
    string s2 = "Pretty cool so far";

    PrintStrings(s1, s2);
}
