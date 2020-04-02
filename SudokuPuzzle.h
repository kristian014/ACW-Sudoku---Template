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
	SudokuPuzzle(void): m_Lenght(9), m_Blocksize(m_Lenght/3){}
	~SudokuPuzzle(void);
	void solve (char filenameIn[]);

private:
	void Print_Sudoku_Row_Column_Block()const ;

	void readPuzzle(char filenameIn[]);
	void DisplaySoduko_Solution()const;
	void SolveSudoku();

	void GetBoxIndex(const int row, const int column,  int* PointerTo_m_blockMatrix_and_Indexof_theSingleBlock)const;

	CellGroup m_gridRows[9];
	CellGroup m_gridColumns[9];
	CellGroup m_gridBlocks[9];

	
	//int m_blockMatrix[2];
	int m_Lenght;
	int m_Blocksize = m_Lenght/3;
	
	
};
template<class T>
inline bool Range_Within_Rows(T LowerBound, T UpperBound, T Value) { return ((LowerBound < Value) && (Value < UpperBound)); }