#include <iostream>
#include <vector>
using std::vector;
using std::cout;

void PrintBoard(vector<vector<int>> board) {
    for (int i = 0; i<board.size(); i++) {
        for (int j=0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
        cout << "\n";        
    }
}

int main() {
    // 3 ways of declaring a vector
    vector<vector<int>> board{
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0}};

    PrintBoard(board);

    /*
    std::string b;
    b = "hello there ole boy";
    cout << "Everything worked!" << "\n";

    cout << b << "\n";

    // 2D vectors
    vector<vector<int>> v {{1, 2}, {3, 4}};

    vector<int> vn = {9,10,11};
    cout << "2D vector initialized" << "\n";
    */
}
