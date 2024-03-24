#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    // Check this row on left side
    for(int i = 0; i < col; i++)
        if(board[row][i] == 'Q')
            return false;
    // Check upper diagonal on left side
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 'Q')
            return false;
    // Check lower diagonal on left side
    for(int i = row, j = col; j >= 0 && i < n; i++, j--)
        if(board[i][j] == 'Q')
            return false;
    return true;
}

bool solveNQUtil(vector<string>& board, int col, vector<vector<string>>& solutions, int n) {
    if(col == n) {
        solutions.push_back(board);
        return true;
    }
    bool res = false;
    for(int i = 0; i < n; i++) {
        if(isSafe(i, col, board, n)) {
            board[i][col] = 'Q';
            res = solveNQUtil(board, col + 1, solutions, n) || res;
            board[i][col] = '.'; // BACKTRACK
        }
    }
    return res;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQUtil(board, 0, solutions, n);
    return solutions;
}

int main() {
    int n = 4; // Change n value for different solutions
    vector<vector<string>> solutions = solveNQueens(n);
    for(auto &solution : solutions) {
        for(auto &row : solution) {
            cout << row << "\n";
        }
        cout << "Solution End\n\n";
    }
    return 0;
}
