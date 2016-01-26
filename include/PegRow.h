/*
 * This class represents a Peg Row on the Board.
 * It contains a list of Code Pegs and Key Pegs.
 * Also provides the operations to add Code Pegs, it
 * internally updates the key pegs on addition of Code Pegs.
 */
#ifndef PEGROW_H_
#define PEGROW_H_

#include "Peg.h"

#include <vector>
#include <memory>

class PegRow {
	std::vector<Peg> m_vecOfCodePegs;
	std::vector<Peg> m_vecOfKeyPegs;

	int m_pegsCount;
	bool m_isFilled;
	bool addKeyPeg(Peg keyPeg, int index);
public:
	PegRow(int pegCount);
	virtual ~PegRow(){}

	std::vector<Peg> getVecOfCodePegs() const ;

	std::vector<Peg> getVecOfKeyPegs() const ;
	bool addCodePeg(Peg codePeg, int index);
	bool IsCodePegsAndKeyPegsAreEqual();
	bool updateKeyPegs(std::vector<Peg> vecOfShieldPegs, int index);
	bool isFilled() const ;
	void setIsFilled(bool isFilled) ;
};

#endif /* PEGROW_H_ */
