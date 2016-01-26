#include "HelpStateHandler.h"
/*
 * Destructor
 */
HelpStateHandler::~HelpStateHandler() {
}
/*
 * Constructor
 */
HelpStateHandler::HelpStateHandler(std::shared_ptr<GameModel> gameModelPtr) : GameStateHandler(gameModelPtr)
{

}
/*
 * This API is allowed to be called by View in GAME_IN_PROGRESS state.
 * It sets the Model state to MAIN_MENU.
 */
void HelpStateHandler::gotoMainMenu()
{
	m_gameModelPtr->setState(MAIN_MENU);
}
