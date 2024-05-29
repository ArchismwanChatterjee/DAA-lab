#include <stdio.h>
#include <stdbool.h>

#define N 8


void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(board[i][j])
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}


bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check if there is a queen in the same row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check if there is a queen in the upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check if there is a queen in the lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueenUtil(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueenUtil(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueen() {
    int board[N][N] = {0};

    if (solveNQueenUtil(board, 0)) {
        printf("Solution exists!\n");

        printSolution(board);
    } else {
        printf("Solution does not exist!\n");
    }
}

int main() {
    solveNQueen();

    return 0;
}

/*
Solution exists!
Q . . . . . . . 
. . . . . . Q . 
. . . . Q . . . 
. . . . . . . Q 
. Q . . . . . .
. . . Q . . . .
. . . . . Q . .
. . Q . . . . .
*/