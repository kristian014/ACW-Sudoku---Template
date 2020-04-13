#include "SudokuPuzzle.h"
#include <chrono>
#include <iostream>

using namespace std;

SudokuPuzzle::~SudokuPuzzle(void)
{
}

SudokuPuzzle::SudokuPuzzle(void)
{
}



void SudokuPuzzle::solve(char filenameIn[]) {
	// Read puzzle from text file
	const auto startTime = std::chrono::high_resolution_clock::now();
	readPuzzle(filenameIn);
	SolveSudoku();
	DisplaySoduko_Solution();
	const auto endTime = std::chrono::high_resolution_clock::now();
	const auto duration = (endTime - startTime).count();

	// Sample timing output in nanoseconds
	cout << duration << "ns"
		<< std::endl;
	
	}



void SudokuPuzzle::SolveSudoku()
{

	cout << "in here to solve soduko" <<endl;

		while (solvepuzzle == false)

	{
		solvepuzzle = true;


		for (int rowlenght = 0; rowlenght < m_Lenght; ++rowlenght) {

			for (int columnlength = 0; columnlength < m_Lenght; ++columnlength) {

				
					if (m_cellRows[rowlenght].getCell(columnlength)->get_ReadValue() == 0) {

						solvepuzzle = false;

						GetBoxIndex(rowlenght, columnlength, &m_blockMatrix[0]);


						for (int j = 0; j < m_Lenght; ++j) {

							if (m_cellRows[rowlenght].getCell(j)->get_ReadValue() != 0)
							
								m_cellRows[rowlenght].getCell(columnlength)->delete_PossibleNumber(m_cellRows[rowlenght].getCell(j)->get_ReadValue());
							

						if (m_CellColumns[columnlength].getCell(j)->get_ReadValue() != 0)
							
								m_CellColumns[columnlength].getCell(rowlenght)->delete_PossibleNumber(m_CellColumns[columnlength].getCell(j)->get_ReadValue());
							

						if (m_CellBlocks[m_blockMatrix[0]].getCell(j)->get_ReadValue() != 0)
							
								m_CellBlocks[m_blockMatrix[0]].getCell(m_blockMatrix[1])->delete_PossibleNumber(m_CellBlocks[m_blockMatrix[0]].getCell(j)->get_ReadValue());
							

						}
						if (m_cellRows[rowlenght].getCell(columnlength)->get_candidatecell_size() == 1) {
							m_cellRows[rowlenght].getCell(columnlength)->set_value(m_cellRows[rowlenght].getCell(columnlength)->get_candidateNumberPosition(0));
							solvepuzzle = false;
						}

					}

			}

		}
	} 

};


void SudokuPuzzle::readPuzzle(char filenameIn[]) {
	
	

	ifstream infile(filenameIn);
	
	
		
		for (int rowlenght = 0; rowlenght < m_Lenght; rowlenght++) {
			for (int columnlenght = 0; columnlenght < m_Lenght; columnlenght++) {

				int Check_NumberGoing_IntotheLoop;
				bool Make_Everynumber_Inthe_LoopTrue = true;
				
				infile >> Check_NumberGoing_IntotheLoop;

				if (Check_NumberGoing_IntotheLoop == 0)

				{
					Make_Everynumber_Inthe_LoopTrue = false;
					m_cellRows[rowlenght].SetCell(columnlenght, new Cell(Check_NumberGoing_IntotheLoop, Make_Everynumber_Inthe_LoopTrue));
				}

				else {

					Make_Everynumber_Inthe_LoopTrue = true;

					m_cellRows[rowlenght].SetCell(columnlenght, new Cell(Check_NumberGoing_IntotheLoop, Make_Everynumber_Inthe_LoopTrue));
				}
				
					m_CellColumns[columnlenght].SetCell(rowlenght, m_cellRows[rowlenght].getCell(columnlenght));

					GetBoxIndex(rowlenght, columnlenght, &m_blockMatrix[0] );
					
					m_CellBlocks[m_blockMatrix[0]].SetCell(m_blockMatrix[1], m_cellRows[rowlenght].getCell(columnlenght));


				

			}

		}

	
};

 void SudokuPuzzle::GetBoxIndex(const int row, const int column, int* PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock)const
{


	 int blockindex = ((row / 3) * 3) + column / 3;
	 int blockindexvalue = column % 3 + (row % 3) * 3; 
	
	PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock[0] = blockindex;
	PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock[1] = blockindexvalue ;
		
	
};
	
void SudokuPuzzle::DisplaySoduko_Solution()const
{
	ofstream output("sudoku_solution.txt");
	while (output.is_open())
	{
		for (int i = 0; i < m_Lenght; i++) {
			for (int j = 0; j < m_Lenght; j++) {
				output << m_cellRows[i].getCell(j)->get_ReadValue() << " ";
			}

			output << endl;
		}
		output.close();
	}
};

