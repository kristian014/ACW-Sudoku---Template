#pragma once
#include <vector>
#include "CellGroup.h"
#include "Cell.h"
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define  m_Lenght 9

// Add your code here

class SudokuPuzzle {
public:
	SudokuPuzzle();
	~SudokuPuzzle();
	void solve (char filenameIn[]);

private:
	//void Print_Sudoku_Row_Column_Block() ;

	void readPuzzle(char filenameIn[]);
	void DisplaySoduko_Solution()const;
	void SolveSudoku();

	void GetBoxIndex(const int row, const int column,  int* PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock)const;


	CellGroup m_cellRows[9];
	CellGroup m_CellColumns[9];
	CellGroup m_CellBlocks[9];

	bool solvepuzzle = false ;
	int m_blockMatrix[2];

	
};
