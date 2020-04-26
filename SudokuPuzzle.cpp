#include "SudokuPuzzle.h"
#include <chrono>
#include <iostream>

using namespace std;


SudokuPuzzle::SudokuPuzzle(void)
{
	Check_NumberGoing_IntotheLoop = false;
	 numberofcellsolved = 0;
	//m_blockMatrix[2] = 0;
}

SudokuPuzzle::~SudokuPuzzle(void)
{
}

void SudokuPuzzle::solve(const char filenameIn[]) {
	// Read puzzle from text file
	
	readPuzzle(filenameIn);
	const auto startTime = std::chrono::high_resolution_clock::now();
	SolveSudoku();
	//hiddensingle();
	const auto endTime = std::chrono::high_resolution_clock::now();
	const auto duration = (endTime - startTime).count();
	// Sample timing output in nanoseconds
	cout << duration << "ns" << endl;
	cout << numberofcellsolved << " Cell solved"
		<< std::endl;

	DisplaySoduko_Solution();
	
	}



bool SudokuPuzzle::SolveSudoku()
{

	cout << "in here to solve soduko" <<endl;

	while (solvepuzzle == false)

	{
		numberofcellsolved++;
		solvepuzzle = true;


		for (int rowlenght = 0; rowlenght < m_Lenght; ++rowlenght) {

			for (int columnlength = 0; columnlength < m_Lenght; ++columnlength) {


				if (m_cellRows[rowlenght].getCell(columnlength)->get_ReadValue() == 0) {

					
					m_CellBlocks[Getblockindex2(rowlenght, columnlength)].SetCell(Getblockindexvalue(rowlenght, columnlength), m_cellRows[rowlenght].getCell(columnlength));

					for (int j = 0; j < m_Lenght; ++j) {

						if (m_cellRows[rowlenght].getCell(j)->get_ReadValue() != 0)

							m_cellRows[rowlenght].getCell(columnlength)->delete_PossibleNumber(m_cellRows[rowlenght].getCell(j)->get_ReadValue());


						if (m_CellColumns[columnlength].getCell(j)->get_ReadValue() != 0)

							m_CellColumns[columnlength].getCell(rowlenght)->delete_PossibleNumber(m_CellColumns[columnlength].getCell(j)->get_ReadValue());

						if (m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(j)->get_ReadValue() != 0)
							m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(Getblockindexvalue(rowlenght, columnlength))->delete_PossibleNumber
							(m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(j)->get_ReadValue());
					}


					if (m_cellRows[rowlenght].getCell(columnlength)->get_candidatecell_size() == 1)
						if (!m_cellRows[rowlenght].getCell(columnlength)->Get__ReadValue_Validity())
							m_cellRows[rowlenght].getCell(columnlength)->set_value(m_cellRows[rowlenght].getCell(columnlength)->get_candidateNumberPosition(0));
					solvepuzzle = false;

				}
				
				
				}
				
			}
		
		}
	return true;
};




bool SudokuPuzzle::hiddensingle()
{

	while (solvepuzzle == false) {

		numberofcellsolved++;
		solvepuzzle = true;

		for (int rowlenght = 0; rowlenght < m_Lenght; ++rowlenght) {

			for (int columnlength = 0; columnlength < m_Lenght; ++columnlength) {

				if (m_cellRows[rowlenght].getCell(columnlength)->get_ReadValue() == 0) {
					m_CellBlocks[Getblockindex2(rowlenght, columnlength)].SetCell(Getblockindexvalue(rowlenght, columnlength), m_cellRows[rowlenght].getCell(columnlength));
					solvepuzzle = false;
					/*for (int i = 0; i < m_Lenght; i++)
					{*/

					//for (int i = 0; i < m_Lenght; ++i) {

						// for row
						for (int j = 0; j < m_Lenght; ++j) {

							if (m_cellRows[rowlenght].getCell(j)->get_ReadValue() != 0)

								m_cellRows[rowlenght].getCell(columnlength)->Search_CandidateList(m_cellRows[rowlenght].getCell(j)->get_ReadValue());

						}

						//////// for column
						for (int j = 0; j < m_Lenght; ++j) {
							if (m_CellColumns[columnlength].getCell(j)->get_ReadValue() != 0)
								m_CellColumns[columnlength].getCell(rowlenght)->Search_CandidateList(m_CellColumns[columnlength].getCell(j)->get_ReadValue());

						}

						//////// for block	
						for (int j = 0; j < m_Lenght; ++j) {

							if (m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(j)->get_ReadValue() != 0)
								m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(Getblockindexvalue(rowlenght, columnlength))->Search_CandidateList(m_CellBlocks[Getblockindex2(rowlenght, columnlength)].getCell(j)->get_ReadValue());

						}

					//}

						if (m_cellRows[rowlenght].getCell(columnlength)->getsizeofnewvector() == 1)
							if (m_cellRows[rowlenght].getCell(columnlength)->Get__ReadValue_Validity())
								m_cellRows[rowlenght].getCell(columnlength)->set_value(m_cellRows[rowlenght].getCell(columnlength)->get_candidatesecondvectorNumberPosition(0));
						//solvepuzzle = false;
				
				}
			
			}


		}

	}
	return false;
};

void SudokuPuzzle::readPuzzle(const char filenameIn[]) 
{
	
	
	    /*
			this process reads the file in from the text file.
			checks the numbers in the text files if its 0.
			if its not, keep getting the row, set the column and get the block from the row and column. 

		*/
	ifstream infile(filenameIn);
	
	if (infile.is_open())
	{

		for (int rowlenght = 0; rowlenght < m_Lenght; rowlenght++) {
			for (int columnlenght = 0; columnlenght < m_Lenght; columnlenght++) {

				

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

				
				// passing the block by address to a method that has a pointer to that address
				//GetBoxIndex(rowlenght, columnlenght, &m_blockMatrix[0]);

				//m_CellBlocks[m_blockMatrix[0]].SetCell(m_blockMatrix[1], m_cellRows[rowlenght].getCell(columnlenght));

				m_CellBlocks[Getblockindex2(rowlenght, columnlenght)].SetCell(Getblockindexvalue(rowlenght, columnlenght), m_cellRows[rowlenght].getCell(columnlenght));
				

			}

		}

	}
};


// https://stackoverflow.com/questions/9357408/creating-9-subarrays-from-a-9x9-2d-array-java

int SudokuPuzzle::Getblockindex2(int const row, int const column)const 
{
	return ((row / 3) * 3) + column / 3;
};

int SudokuPuzzle::Getblockindexvalue(int const row, int const column)const
{
	return column % 3 + (row % 3) * 3;
};





// the main purpose of this is getting the first and second index of the array. 
// parsing the address of the array and in the function the pointer points to the address
//
 void SudokuPuzzle::GetBoxIndex(const int row, const int column,   int* const PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock)const
{
	 // https://stackoverflow.com/questions/9357408/creating-9-subarrays-from-a-9x9-2d-array-java
	 // this is the formular to calculate for block index and block value index
	const int blockindex = ((row / 3) * 3) + column / 3;
	const int blockindexvalue = column % 3 + (row % 3) * 3; 
		
	 // this is for the block index
	PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock[0] = blockindex;

	// block index value 
	PointerTo_m_blockMatrix_pointer_value_Indexof_theSingleBlock[1] = blockindexvalue ;
		
	
};
	
void SudokuPuzzle::DisplaySoduko_Solution()const
{

	// This is to output the file to the textfile 
	ofstream output("sudoku_solution.txt");
	// this checks while the file is still open
	while (output.is_open())
	{
		for (int i = 0; i < m_Lenght; i++) {
			for (int j = 0; j < m_Lenght; j++) {
				// keep getting the cell row and it's value to output.
				output << m_cellRows[i].getCell(j)->get_ReadValue() << " ";
			}

			output << endl;
		}
		// close the file after no value in it. 
		output.close();
	}

};





