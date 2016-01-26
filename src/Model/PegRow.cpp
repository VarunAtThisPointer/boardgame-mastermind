#include "PegRow.h"
#include <iostream>
/*
 * Provides the functionality to add key peg in the row
 */
bool PegRow::addKeyPeg(Peg keyPeg, int index)
{
	if(index < m_vecOfKeyPegs.size())
	{
		m_vecOfKeyPegs.push_back(keyPeg);
		return true;
	}
	return false;
}

/*
 * Constructor
 * Initializes the Code Peg and Key Peg List
 */
PegRow::PegRow(int pegCount)
{
	m_pegsCount = pegCount;
	for(int i = 0 ; i < m_pegsCount; i++)
		m_vecOfKeyPegs.push_back(Peg(EMPTY, KEY));
	for(int i = 0 ; i < m_pegsCount; i++)
		m_vecOfCodePegs.push_back(Peg(EMPTY, CODE));


	m_isFilled = false;
}

/*
 * Returns the list of code pegs
 */
std::vector<Peg> PegRow::getVecOfCodePegs() const {
	return m_vecOfCodePegs;
}
/*
 * Returns the list of key pegs
 */
std::vector<Peg> PegRow::getVecOfKeyPegs() const {
	return m_vecOfKeyPegs;
}
/*
 * Provides the functionality to add Code Peg
 */
bool PegRow::addCodePeg(Peg codePeg, int index)
{
	if(index <m_pegsCount)
	{
		m_vecOfCodePegs[index] = codePeg;
		return true;
	}
	return false;
}
/*
 * Checks if Code Peg and shield pegs are equal, by
 * checking if all Key pegs are Black.
 */
bool PegRow::IsCodePegsAndKeyPegsAreEqual()
{
	int matchCount = 0;
	if( m_vecOfKeyPegs.size() == m_pegsCount)
	{
		for(int k = 0; k < m_vecOfKeyPegs.size(); k++)
		{
			if(m_vecOfKeyPegs[k].getPegColor() == BLACK)
				matchCount++;

		}
	}
	return (matchCount == m_pegsCount);
}
/*
 * Update key peg for specified index.
 * It checks Code Peg at index is of same color as code peg in shield for same
 * index the set the key peg for that index as BLACK.
 * If Code Peg at index is of same color as any of code peg in shield the set the key
 * peg for this index as WHITE.
 */
bool PegRow::updateKeyPegs(std::vector<Peg> vecOfShieldPegs, int index)
{

	if(vecOfShieldPegs.size() == m_vecOfCodePegs.size() && vecOfShieldPegs.size() == m_vecOfKeyPegs.size() && index < vecOfShieldPegs.size())
	{
		int i = index;
		{
			if(vecOfShieldPegs[i].getPegColor() == m_vecOfCodePegs[i].getPegColor() )
			{
				m_vecOfKeyPegs[i] = Peg(BLACK, CODE) ;
			}
			else
			{
				for(int k = 0; k < vecOfShieldPegs.size(); k++)
				{
					if(m_vecOfCodePegs[i].getPegColor() == vecOfShieldPegs[k].getPegColor() && i != k)
					{
						if(m_vecOfKeyPegs[k].getPegColor() != BLACK)
							m_vecOfKeyPegs[i] =  Peg(WHITE, CODE) ;
					}
				}
			}
			for(int k = 0; k < m_vecOfKeyPegs.size(); k++)
			{
				if(m_vecOfKeyPegs[k].getPegColor() == WHITE)
				{
					int blackCount = 0;
					int whiteCount = 0;
					int elementCount = 0;
					for(int j = 0; j < m_vecOfCodePegs.size(); j++)
					{
						if( (m_vecOfCodePegs[j].getPegColor() == m_vecOfCodePegs[k].getPegColor()) && (m_vecOfKeyPegs[j].getPegColor() == BLACK) )
						{
							blackCount++;
						}
					}
					for(int j = 0; j < m_vecOfCodePegs.size(); j++)
					{
						if( (m_vecOfCodePegs[j].getPegColor() == m_vecOfCodePegs[k].getPegColor()) && (m_vecOfKeyPegs[j].getPegColor() == WHITE) )
						{
							whiteCount++;
						}
					}
					for(int j = 0; j < m_vecOfCodePegs.size(); j++)
					{
						if( (vecOfShieldPegs[j].getPegColor() == m_vecOfCodePegs[k].getPegColor()) ) 
						{
							elementCount++;
						}
					}
					if(whiteCount + blackCount > elementCount)
					{
						m_vecOfKeyPegs[k] =  Peg(EMPTY, CODE) ;
					}
				}
			}
		}
		
		
		
		return true;
	}
	return false;
}

/*
 * Check if current Row is filled or not
 */
bool PegRow::isFilled() const {
	return m_isFilled;
}
/*
 * Mark the row as filled
 */
void PegRow::setIsFilled(bool isFilled) {
	m_isFilled = isFilled;
}
