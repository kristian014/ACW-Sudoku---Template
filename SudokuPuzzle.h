#pragma once
#include <vector>
#include "CellGroup.h"
#include "Cell.h"
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;



// Add your code here

class SudokuPuzzle {


public:
	SudokuPuzzle();
	~SudokuPuzzle();
	void solve (const char filenameIn[]);

private:
	//void Print_Sudoku_Row_Column_Block() ;

	void readPuzzle(const char filenameIn[]);
	void DisplaySoduko_Solution()const;
	bool SolveSudoku();

	void GetBoxIndex(const int row, const int column,  int* const PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock)const;
	int Getblockindex2(int const row, int const column)const ;
	int Getblockindexvalue(int const row, int const column)const ;

	bool hiddensingle();
	

	CellGroup m_cellRows[9];
	CellGroup m_CellColumns[9];
	CellGroup m_CellBlocks[9];
	const int  m_Lenght = 9;
	bool solvepuzzle = false ;
	 //int m_blockMatrix[2];
	int Check_NumberGoing_IntotheLoop;
	bool Make_Everynumber_Inthe_LoopTrue = true;
	int numberofcellsolved;
};
