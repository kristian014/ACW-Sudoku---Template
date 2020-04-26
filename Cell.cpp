#include "Cell.h"


Cell::Cell(const int m_Number_toInsertValue, const bool m_Check_ifNumbertoInsert_isPossible)
{
	m_Readvalue = m_Number_toInsertValue;
	m_Check_ReadValue_Validity = m_Check_ifNumbertoInsert_isPossible;

    set_candidates_in_cells(m_Number_toInsertValue);

}

Cell::~Cell()
{
	 
}

// default constructor
Cell::Cell()
{
	m_Readvalue = 0;
	m_Check_ReadValue_Validity = false;

}




int Cell::get_candidateNumberPosition(const int First_CandidateNumber) const

{

	return m_PossibleNumber[First_CandidateNumber];
}


int Cell::get_candidatecell_size() const
{
	return m_PossibleNumber.size();
}


int Cell::getsizeofnewvector()const
{
	return solutionvector.size();

}

int Cell::get_candidatesecondvectorNumberPosition(const int First_CandidateNumber) const
{

	return solutionvector[First_CandidateNumber];
}


int Cell::get_ReadValue()const
{
	return m_Readvalue;
}

void Cell::set_value(const int  new_Value)
{
	m_Readvalue = new_Value;
}

void Cell::set_ReadValue_Validity(const bool new_Value) 
{
	m_Check_ReadValue_Validity = new_Value;
}

bool Cell::Get__ReadValue_Validity()const

{
	return m_Check_ReadValue_Validity;
}


bool Cell::set_candidates_in_cells(int check)

{
	for (unsigned int i = 1; i <= 9; ++i){
		
		 m_PossibleNumber.push_back(i);
		
	}
	return true;
}

void Cell::delete_PossibleNumber(const int remove_PossibleNumber)
{
	// https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

	storecellvalues = find(m_PossibleNumber.begin(), m_PossibleNumber.end(), remove_PossibleNumber);

	if (storecellvalues != m_PossibleNumber.end())
	{
		m_PossibleNumber.erase(storecellvalues);
	}
}



void Cell::Search_CandidateList(int const indexofcell) {



		//Checking if item already exists in the list
		storecellvalues = find(m_PossibleNumber.begin(), m_PossibleNumber.end(), indexofcell);

	if (storecellvalues != m_PossibleNumber.end())
	{
		m_PossibleNumber.erase(storecellvalues);
	}

	
};
			
		
	




//for (int I = 1, J = 0; I < 10; ++I, ++J)
//{
//	if (std::find(Data.begin(), Data.end(), I) == Data.end())
//	{
//		CellInfo.push_back(I);
//	}
//}

	/*std::sort(m_PossibleNumber.begin(), m_PossibleNumber.end());
	m_PossibleNumber.erase(std::unique(m_PossibleNumber.begin(), m_PossibleNumber.end()), m_PossibleNumber.end());*/



	//if (std::find(m_PossibleNumber.begin() , m_PossibleNumber.end(), indexofcell) == m_PossibleNumber.end())
	//		{
	//			//CellInfo.push_back(I);
	//	return false;
	//		}
	//
	//
	//if (m_PossibleNumber[i] == indexofcell) {

			//m_PossibleNumber.erase(m_PossibleNumber.begin() + (i));
			// this means there is same value in the cell.. don't add it

/*

std::sort(std::begin(arr), std::end(arr));
auto u = std::unique(std::begin(arr), std::end(arr));
bool containsDuplicate = u != std::end(arr);


*/
