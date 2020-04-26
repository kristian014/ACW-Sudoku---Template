#pragma once
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class Cell
{
public:
	Cell(const int m_Number_toInsertValue,  const bool m_Check_ifNumbertoInsert_isPossible);
	~Cell();

	Cell();

	//Set your Accessors / getters
	int get_ReadValue()const;
	bool Get__ReadValue_Validity()const;
	int get_candidatecell_size() const;
	int get_candidateNumberPosition(const int First_CandidateNumber) const;
	int getsizeofnewvector()const;

	int get_candidatesecondvectorNumberPosition(const int First_CandidateNumber) const;
    
	
	// set mutators

	void set_value(int  new_Value);
	void set_ReadValue_Validity(bool new_Value);
	bool set_candidates_in_cells(int check);
	void delete_PossibleNumber(int remove_PossibleNumber);
	void Search_CandidateList ( int const indexofcell) ;
private:
	
	int m_Readvalue;
	bool m_Check_ReadValue_Validity;
	vector<int> m_PossibleNumber;
	vector <int>::iterator storecellvalues;
	vector <int> solutionvector;

	bool found [9];
	bool checknumberinCell;
};

