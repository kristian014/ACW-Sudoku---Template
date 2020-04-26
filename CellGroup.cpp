#include "CellGroup.h"
//#pragma once



	CellGroup::CellGroup()
	{
		for (int i = 0; i < 9; ++i) {
			m_cells[i] = new Cell();
		}
	}
	CellGroup::~CellGroup()
	{
		for (int i = 0; i < 9; ++i) {
			
			m_cells[i] = nullptr;
			delete m_cells[i];
			
		}
	};

	void CellGroup::SetCell(const int First_cellvalue,  Cell  *const & cell)
	{
		 m_cells[First_cellvalue] = cell;
	}

	
	 Cell* CellGroup::getCell(int First_cellvalue)const  

	{
		 return m_cells[First_cellvalue];
	}


