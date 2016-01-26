#include "MainMenuStateHandler.h"
/*
 * Destructor
 */
MainMenuStateHandler::~MainMenuStateHandler() {
}
/*
 * Constructor
 */
MainMenuStateHandler::MainMenuStateHandler(std::shared_ptr<GameModel> gameModelPtr) : 	GameStateHandler(gameModelPtr)
{

}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It starts the Game in Model
 */
void MainMenuStateHandler::startGame()
{
	m_gameModelPtr->startGame();
}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It starts the Model state to HELP_MODE
 */
void MainMenuStateHandler::gotoHelpMenu()
{
	m_gameModelPtr->setState(HELP_MODE);
}
/*
 * This API is allowed to be called by View in MAIN_MENU state.
 * It exits the application.
 */
void MainMenuStateHandler::exit()
{
	abort();
}
