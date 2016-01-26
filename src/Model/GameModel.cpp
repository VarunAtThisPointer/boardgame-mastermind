#include "GameModel.h"
#include <stdlib.h> 
#include <time.h>  

/*
 * Constructor
 */
GameModel::GameModel(int rowCount, int pegsInRow) : m_rowCount(rowCount), m_pegsInRow(pegsInRow), m_gameBoard(m_rowCount, m_pegsInRow)
{
	m_state  = MAIN_MENU;
	srand (time(NULL));
}

/*
 * Returns the associated Game Board Object
 */
Board & GameModel::getGameBoard() {
	return m_gameBoard;
}


/*
 * Starts the Game by initializing Game Board and also
 * setting the Game State to GAME_IN_PROGRESS
 */
void GameModel::startGame()
{
	m_gameBoard = Board(m_rowCount, m_pegsInRow);
	setState(GAME_IN_PROGRESS);
	m_gameBoard.addPegInShield(Peg((PegColor)(rand() % 6), CODE), 0);
	m_gameBoard.addPegInShield(Peg((PegColor)(rand() % 6), CODE), 1);
	m_gameBoard.addPegInShield(Peg((PegColor)(rand() % 6), CODE), 2);
	m_gameBoard.addPegInShield(Peg((PegColor)(rand() % 6), CODE), 3);
}

/*
 * This function will initialize the Game Model by setting the
 * state to MAIN_MENU and also notifies all observers that
 * state has changed.
 *
 */
void GameModel::initGame() {
	m_state = MAIN_MENU;
	notifyAllObservers();
}

/*
 * This function returns the current state of the Game
 *
 */
GameState GameModel::getState() const {
	return m_state;
}

/*
 * This function sets the state and notify all observers
 * that state of subject had been changed
 *
 */
void GameModel::setState(GameState state) {
	m_state = state;
	notifyAllObservers();
}

/*
 * This function returns the count of Code/Key Pegs in a row
 *
 */
int GameModel::getPegsInRow() const {
	return m_pegsInRow;
}

/*
 * This function returns the total number of rows in a Board
 * for the game.
 *
 */
int GameModel::getRowCount() const {
	return m_rowCount;
}

