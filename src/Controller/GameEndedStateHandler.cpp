#include "GameEndedStateHandler.h"
/*
 * Constructor
 */
GameEndedStateHandler::~GameEndedStateHandler()
{}

/*
 * Destructor
 */
GameEndedStateHandler::GameEndedStateHandler(std::shared_ptr<GameModel> gameModelPtr) : 	GameStateHandler(gameModelPtr)
{}

/*
 * This API is allowed to be called by View in GAME_ENDED state.
 * It sets the Model State to MAIN_MENU.
 */
void GameEndedStateHandler::gotoMainMenu()
{
	m_gameModelPtr->setState(MAIN_MENU);
}

