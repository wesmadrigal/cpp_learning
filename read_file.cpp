#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using std::cout;
using std::string;
using std::vector;


enum class State {kEmpty, kObstacle};

// change return type to use state
vector<State> ParseLine(string line) {
    std::istringstream my_stream(line);
    vector<State> v;

    char c;
    int i;
    while (my_stream >> i >> c && c == ',') {
        if (i == 0) {
            v.push_back(State::kEmpty);
        } else {
            v.push_back(State::kObstacle);
        }
    }

    return v;
}


string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️ ";
        default: return "0 ";
    }
}


void PrintBoard(vector<vector<State>> board) {
    for (int i = 0; i<board.size(); i++) {
        for (int j=0; j < board[i].size(); j++) {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}



vector<vector<State>> ReadBoardFile(string fpath){
    std::ifstream my_file;
    my_file.open(fpath);

    vector<vector<State>> ve = {};
    if (my_file) {

        cout << "the file stream has been created" << "\n";

        string line;
        while (my_file >> line) {
            cout << line;
            cout << "\n";

            vector<State> v = ParseLine(line);

            ve.push_back(v);
        }
    }

    // finally print the board back out
    //
    cout << "printing out the parsed board" << "\n";        
    return ve;
    //PrintBoard(ve);
}

int main() {
    vector<vector<State>> board = ReadBoardFile("files/1.board");
    PrintBoard(board);
}
