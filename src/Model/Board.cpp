#include "Board.h"

/*
 * Constructor
 * Initializes the code and key pegs
 */
Board::Board(int rowCount, int pegsInRow)
{
	m_RowCount = rowCount;
	m_PegsInARowCount = pegsInRow;
	for(int i =0 ; i < m_RowCount; i++)
	{
		m_vecOfPegRows.push_back(PegRow(m_PegsInARowCount));
	}
	m_vecOfPegsInShield.reserve(m_PegsInARowCount);
	for(int i =0 ; i < m_PegsInARowCount; i++)
	{
		m_vecOfPegsInShield.push_back(Peg(EMPTY, CODE));
	}
}

/*
 * Provides the functionality to add the given Code Peg in the
 * specified Peg row.
 */
bool Board::addCodePegInRow(int rowIndex, Peg & PegObj, int pegIndex)
{
	bool bResult = false;
	if(rowIndex < m_vecOfPegRows.size())
	{
		bResult =  m_vecOfPegRows[rowIndex].addCodePeg(PegObj, pegIndex);
		m_vecOfPegRows[rowIndex].updateKeyPegs(m_vecOfPegsInShield, pegIndex);

	}
	return bResult;
}
/*
 * Shield contains the Code Pegs that user has to identify.
 * This function provies the functionality to add Peg in shield
 */
bool Board::addPegInShield(Peg PegObj, int pegIndex)
{
	if(pegIndex < m_PegsInARowCount)
	{
		m_vecOfPegsInShield[pegIndex] = PegObj;
		return true;
	}
	return false;
}

/*
 * Returns the Peg rows list
 */
std::vector<PegRow > Board::getVecOfPegRows() const {
	return m_vecOfPegRows;
}

/*
 * Returns the list of Pegs in shield
 */
std::vector<Peg> Board::getVecOfPegsInShield() const {
	return m_vecOfPegsInShield;
}
