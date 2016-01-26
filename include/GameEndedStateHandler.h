/*
 * This class is a Game State Handler.
 * It implements the APIs that are allowed in GAME_ENDED state.
 */
#ifndef GAMEENDEDSTATEHANDLER_H_
#define GAMEENDEDSTATEHANDLER_H_
#include "GameStateHandler.h"

class GameEndedStateHandler : public GameStateHandler {
public:
	GameEndedStateHandler(std::shared_ptr<GameModel> gameModelPtr);
	virtual ~GameEndedStateHandler();
	virtual void gotoMainMenu();

};

#endif /* GAMEENDEDSTATEHANDLER_H_ */
