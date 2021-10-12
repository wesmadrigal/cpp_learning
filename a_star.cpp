#include "read_file.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::out_of_range;


enum class State {kEmpty, kObstacle};

bool ValueInArray(vector<vector<int>> array, vector<int> value) {
    bool in_array = false;
    for (int i = 0; i<array.size(); i++) {
        if (array[i] == value) {
            in_array = true;
            break;
        }
    }
    return in_array;
}

bool CheckValidCell(vector<int> coords, vector<vector<State>> board) {
    try {
        cout << coords[0];
        cout << "\n";
        cout << coords[1];
        State result = board[coords[0]][coords[1]];
        switch(result) {
            case State::kObstacle: return false;
            default: return true;
        }
        return true;
    // coordinate isn't on the board
    } catch (out_of_range) {
        return false;
    }
} 

vector<vector<int>> Search(vector<vector<State>> board, vector<int> start, vector<int> goal) {
    // build the x and y axis of the board
    int Y = board.size();
    int X = board[0].size();

    // initialize an empty path
    vector<vector<int>> path = {{start}, };

    vector<vector<int>> checked {};

    vector<vector<int>> open_list = {};

    // this should be an index like: {0, 0}
    vector<int> curnode = start;

    int g_value = 0;

    while (!ValueInArray(path, goal)) {
        // build possible paths from point
       
        vector<vector<int>> possible_neighbors = {
            {curnode[0]+1, curnode[1]},
            {curnode[0]-1, curnode[1]},
            {curnode[0], curnode[1]+1},
            {curnode[0], curnode[1]-1}
        };

        for (int i=0; i<possible_neighbors.size(); i++) {
            bool valid = CheckValidCell(possible_neighbors[i], board);
            if (valid == true) {
                // push the neighbor onto the open list
                open_list.push_back(possible_neighbors[i]);
            }
        }

        // iterate through all open_list nodes and pick the one with the
        // shortest f score (g-value + heuristic)
        vector<int> optimal = {NULL, NULL};
        for (int i=0; i<open_list.size(); i++) {
            if (!optimal[0]) {
                optimal = open_list[i];
            
            } else {
                // compute dist
                int f = g_value + std::abs(open_list[i][0]-goal[0]) + std::abs(open_list[i][1]-goal[1]);
                int curoptf = g_value + std::abs(optimal[0]-goal[0])+std::abs(optimal[1]-goal[1]);
                if (f < curoptf) {
                    optimal = open_list[i];
                }
            }

            checked.push_back(open_list[i]);
        }

        // now that we have the optimal next step lets re-initialize the open_list
        curnode = optimal;
        if (curnode == goal) {
            path.push_back(curnode);
            break;
        }
        // increment the gvalue
        g_value++;                    
    }

    return path;
    
}



void PrintSolution(vector<vector<int>> path) {
    // to be implemented
}



int main() {
    vector<vector<State>> board = ReadBoardFile("files/1.board");

    // now that we've got the board read in we can deal w/ the obstacles
    vector<int> start = {0, 0};
    vector<int> goal = {5, 4};

    vector<vector<int>> path = Search(board, start, goal);

}
