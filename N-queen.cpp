/*
N-Queen problem is a classical problem of placing N chess queens 
on an N×N chessboard in such a way that no two queens threaten each other. 
In other words, the solution must have no two queens share the same row, column, or diagonal.

The program is implemented using backtracking, which is a general algorithmic
technique for finding all (or some) solutions to a computational 
problem that incrementally builds candidates to the solutions 
and abandons a candidate ("backtracks") as soon as it determines that the 
candidate cannot possibly be completed to a valid solution.

The program first initializes an empty chess board with zeros. 
Then it starts placing queens in each row one by one, 
and checks if the queen is safe to place using the safetyCheck function. 
If the position is safe, it places the queen on that position and calls the nQueenSolver 
function recursively to place the remaining queens. If the solution is found, it returns 1, 
otherwise it backtracks and removes the queen from that position and tries the next position.

The safetyCheck function checks if there is any queen in the same row, column, or diagonal, 
and returns 0 if there is any, otherwise it returns 1. The rowCheck and colCheck functions check 
for queens in the same row and column respectively, while the diagonalCheckLeft and diagonalCheckRight 
functions check for queens in the left and right diagonal respectively.

The printChessBoard function prints the chess board with the queens placed as "♕". 
It prints the board using loops, and prints horizontal and vertical lines using strings.

The main function calls the nQueenSolver function with the size of the chess board, 
which is set to 8 by default. It then calls the printChessBoard function to print the solution.
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <array> 

#define SIZE 8
#define SPACE " "
#define BLANK 0
#define LINE "|"
#define NEWROW "===="

// Function to print the chess board with the queens placed
void printChessBoard(int chessBoard[SIZE][SIZE])
{
    // Loop through each row of the chess board
	for (int i = 0; i < SIZE; i++)
	{
		// Print the space between the rows
		std::cout << SPACE << SPACE << SPACE << SPACE << std::endl;
        
        // Print the horizontal lines
        for(int k = 0; k<SIZE;k++)
        {
            std::cout << NEWROW;
        }
        // Start a new line
        std::cout<<std::endl;
		
        // Loop through each column of the current row
		for (int j = 0; j < SIZE; j++)
		{
			// Print the space before each cell
			std::cout << SPACE;
			
			// If the cell is blank, print a space
			if (BLANK == chessBoard[i][j])
			{
				std::cout << SPACE;
			}
			// If the cell is not blank, print a queen
			else
			{
				std::cout << "♕";
			}
			
			// Print the space after each cell and a vertical line
			std::cout << SPACE;
			std::cout << LINE;
		}
	}
	
    // Print the bottom horizontal lines of the chess board
    std::cout<<std::endl;
	for(int k = 0; k<SIZE;k++)
        {
            std::cout << NEWROW;
        }
    // Start a new line
    std::cout<<std::endl;
}

// Function to check if there is a queen in the same row
int rowCheck(int row, int chessBoard[SIZE][SIZE]){

    // Loop through each column of the current row
    for (int i = 0; i < SIZE; i++){
     
        // If there is a queen in the current column, return 1
        if (1 == chessBoard[row][i]){
            return 1;
        }
    }
    // If there is no queen in the current row, return 0
    return 0;
}

// Function to check if there is a queen in the same column
int colCheck(int col, int chessBoard[SIZE][SIZE]){

    // Loop through each row of the current column
    for (int i = 0; i < SIZE; i++){

        // If there is a queen in the current row, return 1
        if (1 == chessBoard[i][col]){
            return 1;
        }
    }
    return 0;
}

// Function to check if there is a queen in the same left diagonal
int diagonalCheckLeft(int row, int col, int chessBoard[SIZE][SIZE]){
    // Check for queens in the left diagonal, starting from the current position and moving upwards and to the left
    while(((row)>0) && (col)>0){
        row--;
        col--;
    }
 
    // Check for queens in the left diagonal, starting from the new position and moving downwards and to the right
    while( (row<SIZE) && (col<SIZE) ){
        if(chessBoard[row][col]==1){
            // If a queen is found, return 1
            return 1;
        }
        row++;
        col++;
    }
    // If no queen is found, return 0
    return 0;
}

// Function to check if there is a queen in the same right diagonal
int diagonalCheckRight(int row, int col, int chessBoard[SIZE][SIZE]){
    // Check for queens in the right diagonal, starting from the current position and moving upwards and to the right
    while(((row)>0) && (col)<(SIZE-1)){
        row--;
        col++;
    }
    // Check for queens in the right diagonal, starting from the new position and moving downwards and to the left
    while( (row<SIZE) && (col>=0) ){
        if(chessBoard[row][col]==1){
            // If a queen is found, return 1
            return 1;
        }
        row++;
        col--;
    }
 
    // If no queen is found, return 0
    return 0;
}

// Function to check if a position is safe to place a queen
int safetyCheck(int row, int col, int chessBoard[SIZE][SIZE]){
    if(1==rowCheck(row,chessBoard)){
        // If there is a queen in the same row, return 0
        return 0;
    }
 
    else if(1==colCheck(col,chessBoard)){
        // If there is a queen in the same column, return 0
        return 0;
    } 
    else if(1==diagonalCheckLeft(row,col,chessBoard)){
        //if there is a queen in the same left diagonal, return 0
        return 0;
    }
    else if(1==diagonalCheckRight(row,col,chessBoard)){
        //if there is a queen in the same right diagonal, return 0
        return 0;
    }
    else{
        //if no queen is found, return 1
        return 1;
    }
}

// Function to solve the N-Queen problem
int nQueenSolver(int queens, int chessBoard[SIZE][SIZE])
{   
    // If all queens have been placed, return 1
    if(queens == 0){
        return 1;
    } 
   
    // Loop through the chess board
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            // Check if the current position is safe to place a queen
            if(1==safetyCheck(i,j,chessBoard)){
                // Place the queen and decrement the number of queens to be placed
                chessBoard[i][j]=1;
                queens--;
                // Recursively call the function to place the remaining queens
                int solver=nQueenSolver(queens,chessBoard);
                if(solver==1){
                    // If all queens can be placed, return 1
                    return 1;
                }
                else{
                    // If the current position does not lead to a solution, remove the queen and increment the number of queens to be placed
                    chessBoard[i][j]=0;
                    queens++;  
                }
            }
        }
    }
    // If no solution is found, return 0
    return 0;
}

int main()
{
    // Initialize the chess board
    int chessBoard[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            chessBoard[i][j]=0;
        }
    }
    // Call the nQueenSolver function to solve the N-Queen problem
    nQueenSolver(SIZE,chessBoard);
	// Call the printChessBoard function to print the solution
	printChessBoard(chessBoard);
}

