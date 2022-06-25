#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
int numRows = board.size();
int numCols = board[0].size();

int countNeighbors(int r, int c) {
    int numNeigh = 0;
    for(int i = r-1; i <= r+1; i++) {
        for(int j = c-1; j <= c+1; j++) {
            if((i==r && j==c)
                || i<0 
                || j<0 
                || i == numRows 
                || j == numCols)
                continue;
            if(board[i][j] == 1 || board[i][j] == 3) numNeigh++;
        }
    }

    return numNeigh;
}

// In-Place
void gameOfLife() {
    /**
     * Original | New | State
     *    0        0      0
     *    1        0      1
     *    0        1      2
     *    1        1      3
     */

    for(int r = 0; r < numRows; r++) {
        for(int c = 0; c < numCols; c++) {
            int numNeigh = countNeighbors(r, c);

            if(board[r][c]) {
                if(numNeigh == 2 || numNeigh == 3) board[r][c] = 3;
            }
            else {
                if(numNeigh == 3) board[r][c] = 2; 
            }
        }
    }

    for(int r = 0; r < numRows; r++) {
        for(int c = 0; c < numCols; c++) {
            if(board[r][c] == 1 ) board[r][c] = 0;
            else if(board[r][c] == 2 || board[r][c] == 3) board[r][c] = 1;
        }
    }
}

int main() {
    for(auto line : board) {
        for(auto val : line) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    gameOfLife();
    for(auto line : board) {
        for(auto val : line) {
            cout << val << " ";
        }
        cout << endl;
    }
}