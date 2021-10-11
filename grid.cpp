#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;


int main() {

    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0}};

    cout << "Hello" << "\n";

    cout << board[0].size();
    cout << "\n";
    cout << board.size();
    cout << "\n";


    for (int i=0; i < board.size(); i++) {
        cout << "index ";
        cout << i;
        cout << " has size:";

        cout << "\n";
        cout << board[i].size();
        cout << "\n";
    }
}
