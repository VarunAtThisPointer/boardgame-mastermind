/*
 * This file acts as a Game Model for the Game.
 * It contains all the settings of Game and also contains
 * the Board associated with the Game
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include "Board.h"
#include "Subject.h"
#include <memory>

enum GameState
{
	MAIN_MENU = 0,
	GAME_IN_PROGRESS,
	GAME_ENDED,
	HELP_MODE,
};
class GameModel : public Subject
{
	int m_rowCount;
	int m_pegsInRow;
	Board m_gameBoard;
	GameState m_state;
public:
	GameModel(int rowCount, int pegsInRow);
	virtual ~GameModel(){}
	Board & getGameBoard();
	void startGame();
	void initGame();
	GameState getState() const;
	void setState(GameState state);
	int getPegsInRow() const;
	int getRowCount() const;

};



#endif /* GAMEMODEL_H_ */
