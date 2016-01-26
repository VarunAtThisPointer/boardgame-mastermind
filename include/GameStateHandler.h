/*
 *This class acts as a Generic State Handler
 */
#ifndef GAMESTATEHANDLER_H_
#define GAMESTATEHANDLER_H_
#include "GameModel.h"
#include <memory>

class GameStateHandler {
protected:
	std::shared_ptr<GameModel> m_gameModelPtr;
public:
	GameStateHandler(std::shared_ptr<GameModel> gameModelPtr);
	virtual ~GameStateHandler(){}
	virtual void stopGame();
	virtual void endGame();
	virtual void startGame();
	virtual bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
	virtual void gotoMainMenu();
	virtual void gotoHelpMenu();
	virtual void exit();
};

#endif /* GAMESTATEHANDLER_H_ */
