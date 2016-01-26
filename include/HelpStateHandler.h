/*
 * This class is a Game State Handler.
 * It implements the APIs that are allowed in HELP state.
 */
#ifndef HELPSTATEHANDLER_H_
#define HELPSTATEHANDLER_H_

#include "GameStateHandler.h"

class HelpStateHandler: public GameStateHandler {
public:
	HelpStateHandler(std::shared_ptr<GameModel> gameModelPtr);
	virtual ~HelpStateHandler();
	virtual void gotoMainMenu();
};

#endif /* HELPSTATEHANDLER_H_ */
