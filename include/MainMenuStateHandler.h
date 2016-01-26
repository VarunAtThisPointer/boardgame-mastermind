/*
 * This class is a Game State Handler.
 * It implements the APIs that are allowed in MAIN_MENU state.
 */
#ifndef MAINMENUSTATEHANDLER_H_
#define MAINMENUSTATEHANDLER_H_

#include "GameStateHandler.h"
#include <iostream>

class MainMenuStateHandler: public GameStateHandler {
public:

	MainMenuStateHandler(std::shared_ptr<GameModel> gameModelPtr);
	virtual ~MainMenuStateHandler();
	virtual void startGame();
	virtual void gotoHelpMenu();
	virtual void exit();
};

#endif /* MAINMENUSTATEHANDLER_H_ */
