#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Board;

const int SIZE = 8;

bool threat(Board board, int row, int col) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == 'Q')
            return true;
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == 'Q')
            return true;
    }
    for (int i = row, j = col; 0 <= i && j < SIZE; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
int main() {
    Board board(SIZE, vector<char>(SIZE));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }
}