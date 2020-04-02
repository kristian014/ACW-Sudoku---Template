
#pragma once
#include "Cell.h"
class CellGroup
{
public:
	CellGroup();
	~CellGroup();

	void SetCell(int First_cellvalue, Cell *cell);

	Cell* getCell(int First_cellvalue) const;


private:
	
	Cell* m_cells[9];
	

};

