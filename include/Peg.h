/*
 * This class represents the Peg for the MasterMind game.
 */
#ifndef PEG_H_
#define PEG_H_

enum PegColor
{
	RED = 0,
	YELLOW,
	GREEN,
	ORANGE,
	VOILET,
	BLUE,
	WHITE,
	BLACK,
	EMPTY,
};
enum PegType
{
	CODE = 0,
	KEY,
};

class Peg
{
	PegColor m_PegColor;
	PegType  m_PegType;
public:
	Peg(PegColor color, PegType pegType);
	virtual ~Peg(){}
	PegColor getPegColor() const ;
	void setPegColor(PegColor pegColor);
	PegType getPegType() const;
	void setPegType(PegType pegType);
};

#endif /* PEG_H_ */
