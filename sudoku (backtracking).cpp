#include "bits/stdc++.h"
#define N 9
using namespace std;

int grid[N][N];

bool isInColumn(int grid[N][N], int c, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[i][c] == x)
            return true;
    }
    return false;
}

bool isInRow(int grid[N][N], int r, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[r][i] == x)
            return true;
    }
    return false;
}

bool isInSubgrid(int grid[N][N], int r, int c, int x) {
    int sqroot = sqrt(N);
    int parent_r = (r / sqroot) * sqroot;
    int parent_c = (c / sqroot) * sqroot;

    for (int i = 0; i < sqroot; i++) {
        for (int j = 0; j < sqroot; j++) {
            if (grid[parent_r + i][parent_c + j] == x) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int r, int c, int x) {
    return !(isInColumn(grid, c, x) || isInRow(grid, r, x) || isInSubgrid(grid, r, c, x));
}

bool findEmptyCell(int grid[N][N], int &r, int &c) {
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (grid[r][c] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N]) {
    int r, c;

    if (findEmptyCell(grid, r, c) == false) {
        return true;
    }

    for (int x = 1; x <= N; x++) {
        if (isSafe(grid, r, c, x)) {
            grid[r][c] = x;
            if (solveSudoku(grid) == true)
                return true;
            grid[r][c] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/

/*

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9

*/
