#include "Peg.h"

/*
 * Constructor
 * Initialize color and type of Peg
 */
Peg::Peg(PegColor color, PegType pegType) : m_PegColor(color), m_PegType(pegType)
{}

/*
 * Returns the color of Peg
 */
PegColor Peg::getPegColor() const {
	return m_PegColor;
}

/*
 * sets the color of Peg
 */
void Peg::setPegColor(PegColor pegColor) {
	m_PegColor = pegColor;
}

/*
 * Returns the type of Peg
 */
PegType Peg::getPegType() const {
	return m_PegType;
}

/*
 * sets the type of Peg
 */
void Peg::setPegType(PegType pegType) {
	m_PegType = pegType;
}
