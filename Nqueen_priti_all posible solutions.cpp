
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 20;  
int board[MAX]; // To hold the column position of queens
//Each element of the array represents a row on the chessboard. For example:
//board[0] represents the position of the queen in row 1.
//board[1] represents the position of the queen in row 2, and so on.

//If board[0] = 2, it means a queen is placed at row 1, column 3 (since arrays start from index 0).

void printSolution(int n) {
    for (int i = 0; i < n; i++)
	//responsible for iterating over each loop on the chesssboard
	 {
	 for (int j = 0; j < n; j++) { //o, when board[i] == j, it means a queen is placed at row i and column j.
            if (board[i] == j) // Check if a queen is placed in row i and column j
                cout << "1 "; // Queen is placed
            else
                cout << "0 "; // No queen
        }
        cout << endl; // New line for the next row
    }
    cout << endl; // Separate different solutions
}

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) 
		//This works because the absolute difference in column positions (board[i] - col) must equal the absolute difference in row positions (i - row) for two queens to be on the same diagonal.{
            return false;//not safe to place queens
        }
        return true;//it is safe to place the queen
    }
    
   

//board[i] refers to the column position of the queen in row i
//The solveNQueens() function then uses recursion and backtracking to try different ways of placing queens on the board, row by row.
void solveNQueens(int row, int n) {
    if (row == n) {//checks whether all queens are placed successfully
        printSolution(n); // Print the solution when all queens are placed
        return;//The function printSolution(n) is called to display the current board configuration
    }

    for (int col = 0; col < n; col++)
    //The function tries to place a queen in every column of the current row.
	 {//After this base case, the for loop continues for rows where row != n
        if (isSafe(row, col, n)) {
            board[row] = col; // Place queen
            solveNQueens(row + 1, n); // Move to the next row
            // No need to backtrack as we overwrite in the next iteration
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n; // Input for number of queens
    solveNQueens(0, n);//start solving from row 0 with n queens
    return 0;
}



