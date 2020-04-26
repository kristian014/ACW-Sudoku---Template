#include "SudokuPuzzle.h"
#include "Main.h"

int main(const int argc, char **) {
	SudokuPuzzle puzzle;

	puzzle.solve("sudoku_puzzle8.txt"); 

	return 0;
}

