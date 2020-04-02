#include "Cell.h"
#include <iostream>
#include <vector>
#include <algorithm>


Cell::Cell(const int m_Number_toInsertValue, const bool m_Check_ifNumbertoInsert_isPossible)
{
	m_Readvalue = m_Number_toInsertValue;
	m_Check_ReadValue_Validity = m_Check_ifNumbertoInsert_isPossible;

	//Add the possible numbers to the vector array.
	for (int i = 1; i <= 9; ++i) {
		m_PossibleNumber.push_back(i);
	}

}

Cell::~Cell()
{
}

Cell::Cell()
{
	m_Readvalue = 0;
	m_Check_ReadValue_Validity = false;

	//Add your possible number to the vector array
	for (int i = 1; i <= 9; ++i) {
		m_PossibleNumber.push_back(i);


	}
}




int Cell::get_candidateNumberPosition(int index) const

{

	return m_PossibleNumber[index];
}


int Cell::get_candidatecell_size() const
{
	return m_PossibleNumber.size();
}




int Cell::get_ReadValue()const
{
	return m_Readvalue;
}

void Cell::set_value(int  new_Value)
{
	m_Readvalue = new_Value;
}

void Cell::set_ReadValue_Validity(bool new_Value)
{
	m_Check_ReadValue_Validity = new_Value;
}

bool Cell::Get__ReadValue_Validity()const

{
	return m_Check_ReadValue_Validity;
}

// This will work for both the role and the column to always check for duplicate
void Cell::set_candidates_in_cells(int newPossibleNumber)
{
	bool Validate_number = false;
	for (unsigned int i = 0; i <m_PossibleNumber.size(); ++i ) 
	{
		if (m_PossibleNumber[i] == newPossibleNumber) {
			Validate_number = true;
		}
		
	}
	if (Validate_number = false) {
		m_PossibleNumber.push_back(newPossibleNumber);
	}
	
}

void Cell::delete_PossibleNumber(int remove_PossibleNumber)
{
	for (unsigned int i = 0; i < m_PossibleNumber.size(); ++i)
	{
		if (m_PossibleNumber[i] == remove_PossibleNumber) {
		

		m_PossibleNumber.erase(m_PossibleNumber.begin() + i);
		 	
		}

		
	}
}

