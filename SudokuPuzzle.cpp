#include "SudokuPuzzle.h"
#include <chrono>
#include <Windows.h>
#include <iostream>

using namespace std;

SudokuPuzzle::~SudokuPuzzle(void)
{
}




void SudokuPuzzle::solve(char filenameIn[]) {
	// Read puzzle from text file
	readPuzzle(filenameIn);
	SolveSudoku();
	}



void SudokuPuzzle::SolveSudoku()
{
	
	const auto startTime = std::chrono::high_resolution_clock::now();

	// Get end time
	const auto endTime = std::chrono::high_resolution_clock::now();
	const auto duration = (endTime - startTime).count();

	bool solvefinalpuzzle = true;
	int m_blockMatrix[2];
	int counter = 1;
	cout << "in here to solve soduko" <<endl;


	do {

		solvefinalpuzzle = true;


		for (int row = 0; row < m_Lenght; ++row) {

			for (int column = 0; column < m_Lenght; ++column) {

				if (!m_gridRows[row].getCell(column)->Get__ReadValue_Validity())
				{
					if (m_gridRows[row].getCell(column)->get_ReadValue() == 0) {

						solvefinalpuzzle = false;

						GetBoxIndex(row, column, &m_blockMatrix[0]);
						for (int j = 0; j < 9; ++j) {

							if (m_gridRows[row].getCell(j)->get_ReadValue() != 0)
							{
								m_gridRows[row].getCell(column)->
									delete_PossibleNumber(m_gridRows[row].getCell(j)->get_ReadValue());
							}
							if (m_gridColumns[column].getCell(j)->get_ReadValue() != 0)
							{
								m_gridColumns[column].getCell(row)->delete_PossibleNumber(m_gridColumns[column].getCell(j)->get_ReadValue());
							}

							if (m_gridBlocks[m_blockMatrix[0]].getCell(j)->get_ReadValue() != 0)
							{
								m_gridBlocks[m_blockMatrix[0]].getCell(m_blockMatrix[1])->
									delete_PossibleNumber(m_gridBlocks[m_blockMatrix[0]].getCell(j)->get_ReadValue());
							}

						}
						if (m_gridRows[row].getCell(column)->get_candidatecell_size() == 1) {
							m_gridRows[row].getCell(column)->set_value(m_gridRows[row].getCell(column)->get_candidateNumberPosition(0));
						}

					}


				}



			}

		}
	}

	while (solvefinalpuzzle == false);

		//SolveSudoku();
		// Get start time

		// Sample timing output in nanoseconds
		cout << duration << "ns"
			<< std::endl;
		DisplaySoduko_Solution();
		//Print_Sudoku_Row_Column_Block();

};





void SudokuPuzzle::readPuzzle(char filenameIn[]) {
	
	

	ifstream infile(filenameIn);
	int m_blockMatrix[2];
	
		
		for (int row = 0; row < m_Lenght; row++) {
			for (int column = 0; column < m_Lenght; column++) {
				int Check_NumberGoing_IntotheLoop;
				bool Make_Everynumber_Inthe_LoopTrue = true;
				
				infile >> Check_NumberGoing_IntotheLoop;

				if (Check_NumberGoing_IntotheLoop == 0)

				{
					Make_Everynumber_Inthe_LoopTrue = false;
				}
					// you have your row
					m_gridRows[row].SetCell(column, new Cell(Check_NumberGoing_IntotheLoop, Make_Everynumber_Inthe_LoopTrue));

					// set your column
					m_gridColumns[column].SetCell(row, m_gridRows[row].getCell(column));

					GetBoxIndex(row, column, &m_blockMatrix[0]);
					m_gridBlocks[m_blockMatrix[0]].SetCell(m_blockMatrix[1], m_gridRows[row].getCell(column));

				

			}

		}

	
};

void SudokuPuzzle::Print_Sudoku_Row_Column_Block()const


{
	cout << "in this place";
	cout.clear();

	for (int row = 0; row < m_Lenght; ++row) {
		for (int column = 0; column < m_Lenght; ++column) {
			cout << m_gridRows[row].getCell(column)->get_ReadValue() << " ";
		}

		cout << endl;
	}


	cout << endl;


	for (int column = 0; column < m_Lenght; ++column) {
		for (int row = 0; row < m_Lenght; ++row) {
			cout << m_gridColumns[row].getCell(column)->get_ReadValue() << " ";
		}

		cout << endl;
	}


	cout << endl;
	cout << "Blocks" << endl;


	int m_blockMatrix[2];
	for (int row = 0; row < m_Lenght; ++row) {
		for (int column = 0; column < m_Lenght; ++column) {
		
			GetBoxIndex(row, column, &m_blockMatrix[0]);
			cout << m_gridBlocks[m_blockMatrix[0]].getCell(m_blockMatrix[1])->get_ReadValue() << " ";
		}

		cout << endl;
	}
};


void SudokuPuzzle::GetBoxIndex(const int row, const int column,  int* PointerTo_m_blockMatrix_and_Indexof_theSingleBlock)const
{

	int blockRowValueIndex = 0;
	int m_Row_Blockindex = 0;
	int m_blockMatixindex = 0;
	int m_blockMatrixValues = 0;
	int m_Column_Blockindex = 0;

if (row < 3)
{
	//m_blockrow = 0;
	m_blockMatixindex = (column / 3);
	m_Row_Blockindex = row;
}

else if (Range_Within_Rows(2, 6, row))
{
	m_blockMatixindex = 3 + (column / 3);
	m_Row_Blockindex = row - 3;
}
else if (Range_Within_Rows(5, 9, row))
{
	m_blockMatixindex = 6 + (column / 3);
	m_Row_Blockindex = row - 6;
}

if (column < 3)
{

	m_Column_Blockindex = column;
}

else if (Range_Within_Rows(2, 6, column))
{

	m_Column_Blockindex = column - 3;
}
else if (Range_Within_Rows(5, 9, column))
{

	m_Column_Blockindex = column - 6;
}



		m_blockMatrixValues = (m_Row_Blockindex * 3) + m_Column_Blockindex;
		PointerTo_m_blockMatrix_and_Indexof_theSingleBlock[0] = m_blockMatixindex;
		PointerTo_m_blockMatrix_and_Indexof_theSingleBlock[1] = m_blockMatrixValues;
	
};
	
void SudokuPuzzle::DisplaySoduko_Solution()const
{
	ofstream output("sudoku_solution.txt");
	while (output.is_open())
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				output << m_gridRows[i].getCell(j)->get_ReadValue() << " ";
			}

			output << endl;
		}
		output.close();
	}
};

