
#pragma once
#include "Cell.h"

class CellGroup
{

public:
	CellGroup();
	~CellGroup();

	void SetCell(const int First_cellvalue,  Cell * const &cell);

	 Cell* getCell(int First_cellvalue) const;


private:

	 Cell  * m_cells[9];


};

