/*
 * This class acts as Controller in MVC Design.
 * It provides the APIs to modify the Model Based on active State
 */
#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "GameModel.h"
#include "GameStateHandler.h"
#include "GameInProgressHandler.h"
#include "HelpStateHandler.h"
#include "GameEndedStateHandler.h"
#include "MainMenuStateHandler.h"
#include <memory>
#include <map>

class GameController {
	std::shared_ptr<GameModel> m_gameModelPtr;
	std::map<int, std::shared_ptr<GameStateHandler> > m_mapOfGameStateHandlerPtr;

public:
	GameController(std::shared_ptr<GameModel> gameModelPtr);
	void init();
	virtual ~GameController(){}
	void stopGame();
	void startGame();
	bool addCodePegs(int rowIndex, Peg PegObj, int pegIndex);
	void gotoMainMenu();
	void gotoHelpMenu();
	void exit();
	void endGame();
};

#endif /* GAMECONTROLLER_H_ */
