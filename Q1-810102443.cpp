#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 8;

int main() {
    vector<vector<char> > board(SIZE, vector<char>(SIZE));
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = 0 ; j < SIZE ; j++) {
            cin >> board[i][j];
        }
    }
    cout << "Output: " << endl;
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}