#include "CellGroup.h"
//#pragma once



	CellGroup::CellGroup()
	{
		for (int i = 0; i < 9; ++i) {
			m_cells[i] = new Cell();
		}
	}
	CellGroup::~CellGroup() {};

	void CellGroup::SetCell(int First_cellvalue, Cell *cell)
	{
		m_cells[First_cellvalue] = cell;
	}

	Cell* CellGroup::getCell(int First_cellvalue) const

	{
		return  m_cells[First_cellvalue];
	}


