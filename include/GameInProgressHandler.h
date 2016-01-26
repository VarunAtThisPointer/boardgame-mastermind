/*
 * This class is a Game State Handler.
 * It implements the APIs that are allowed in GAME_IN_PROGRESS state.
 */
#ifndef GAMEINPROGRESSHANDLER_H_
#define GAMEINPROGRESSHANDLER_H_

#include "GameStateHandler.h"
#include <iostream>
class GameInProgressHandler: public GameStateHandler {
public:
	GameInProgressHandler(std::shared_ptr<GameModel> gameModelPtr);
	virtual ~GameInProgressHandler();
	virtual void stopGame();
	virtual bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
	virtual void endGame();
};

#endif /* GAMEINPROGRESSHANDLER_H_ */
