#pragma once
#include <vector>

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
	int get_candidateNumberPosition(int index) const;
	

    
	
	// set mutators

	void set_value(int  new_Value);
	void set_ReadValue_Validity(bool new_Value);
	void set_candidates_in_cells(int newPossibleNumber);
	void delete_PossibleNumber(int remove_PossibleNumber);

private:
	
	int m_Readvalue;
	bool m_Check_ReadValue_Validity;
	vector<int> m_PossibleNumber;


};

