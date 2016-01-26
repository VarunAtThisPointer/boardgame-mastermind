/*
 * This class represents the Board of the Game
 * It contains the several Peg Rows objects
 * Also provides the operations to add Code and key pegs
 */
#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include <memory>
#include "Peg.h"
#include "PegRow.h"

class Board
{
	std::vector<PegRow > m_vecOfPegRows;
	std::vector<Peg> m_vecOfPegsInShield;
	int m_RowCount;
	int m_PegsInARowCount;
public:
	Board(int rowCount, int pegsInRow);
	virtual ~Board(){}
	bool addCodePegInRow(int rowIndex, Peg & PegObj, int pegIndex);
	bool addPegInShield(Peg PegObj, int pegIndex);
	std::vector<PegRow > getVecOfPegRows() const ;
	std::vector<Peg> getVecOfPegsInShield() const;
};

#endif /* BOARD_H_ */
