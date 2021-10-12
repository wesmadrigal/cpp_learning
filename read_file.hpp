#ifndef READ_FILE_HPP
#define READ_FILE_HPP

#include <string>
using std::vector;
using std::string;

enum class State;

// function ParseLine declaration
vector<State> ParseLine(string line);


// CellString function declaration
string CellString(State cell);

// PrintBoard function declaration
void PrintBoard(vector<vector<State>> board);

// ReadBoardFile declaration
vector<vector<State>> ReadBoardFile(string fpath);

#endif
