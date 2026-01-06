#include <stdio.h>
#include <stdlib.h>
#include "n_queens.h"

// Helper function to calculate absolute value
// Used to check diagonal attacks between queens
int ft_abs(int x)
{
    return (x < 0 ? -x : x);
}

// Check if placing a queen at (step, column) is safe
// Parameters:
//   b[] - board array where b[row] = column of queen in that row
//   step - current row we're trying to place a queen
//   column - column we want to place the queen in
int is_safe(int *b, int step, int column)
{
    // Check all previously placed queens (rows 0 to step-1)
    for (int i = 0; i < step; i++)
    {
        // Two conditions that make placement unsafe:
        // 1. Same column: b[i] == column
        //    Queens attack each other vertically
        // 2. Same diagonal: ft_abs(b[i] - column) == ft_abs(i - step)
        //    Queens attack each other diagonally
        //    Diagonal attack occurs when the slope between two queens = ±1
        //    Slope = (row2-row1)/(col2-col1) = ±1
        //    So |col2-col1| = |row2-row1|
        if (b[i] == column || ft_abs(b[i] - column) == ft_abs(i - step))
            return (0); // Unsafe position
    }
    return (1); // Safe position
}

// Recursive backtracking function to solve N-Queens
// Parameters:
//   b[] - board array representing queen positions
//   n - size of the chessboard (n x n)
//   step - current row we're working on
void solve(int *b, int n, int step)
{
    // Base case: all queens placed successfully
    if (step == n)
    {
        // Print the solution
        // Each number represents the column of the queen in that row
        for (int i = 0; i < n; i++)
        {
            fprintf(stdout, "%d", b[i]);
            if (i < n - 1) fprintf(stdout, " "); // Space between numbers
        }
        fprintf(stdout, "\n");
        return;
    }

	//"step" in a programm defines how many queens was set before.
	// step == 0: 0 queens placed → Working on row 0 (first row)
	// step == 1: 1 queen placed → Working on row 1 (second row)
	// step == 2: 2 queens placed → Working on row 2 (third row)
	// step == n: All n queens placed → Solution found!
    // Try placing a queen in each column of the current row
    for (int column = 0; column < n; column++)
    {
        // Check if this position is safe (no conflicts with previous queens)
        if (is_safe(b, step, column))
        {
            // CHOOSE: Place queen at (step, column)
            b[step] = column;
            
            // EXPLORE: Recursively solve for the next row
            solve(b, n, step + 1);
            
            // UNCHOOSE: Backtrack happens automatically when function returns
            // No explicit removal needed since we overwrite b[step] in next iteration
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2) return (0);
    int n = atoi(av[1]);
    if (n <= 0) return (0);
    int *b = malloc(sizeof(int) * n);
    if (!b) return (1); 
    solve(b, n, 0);
    free(b);
    return (0);
}
