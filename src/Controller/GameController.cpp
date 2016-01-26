#include "GameController.h"

/*
 * Constructor
 */
GameController::GameController(std::shared_ptr<GameModel> gameModelPtr)
:m_gameModelPtr(gameModelPtr)
{

}
/*
 * Initializes a Map of State and State Event Handlers
 */
void GameController::init()
{
	m_mapOfGameStateHandlerPtr[MAIN_MENU] = std::shared_ptr<GameStateHandler>(new MainMenuStateHandler(m_gameModelPtr) );
	m_mapOfGameStateHandlerPtr[GAME_IN_PROGRESS] = std::shared_ptr<GameStateHandler>(new GameInProgressHandler(m_gameModelPtr) );
	m_mapOfGameStateHandlerPtr[GAME_ENDED] = std::shared_ptr<GameStateHandler>(new GameEndedStateHandler(m_gameModelPtr) );
	m_mapOfGameStateHandlerPtr[HELP_MODE] = std::shared_ptr<GameStateHandler>(new HelpStateHandler(m_gameModelPtr) );
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::stopGame()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->stopGame();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::startGame()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->startGame();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
bool GameController::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			return m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->addCodePegs(rowIndex, PegObj, pegIndex);
		}
	}
	return false;
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::gotoMainMenu()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->gotoMainMenu();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::gotoHelpMenu()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->gotoHelpMenu();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::exit()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->exit();
		}
	}
}
/*
 * Searches the current active State Handler based on the current State and
 * forwards the control to State specific Handler
 */
void GameController::endGame()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameStateHandlerPtr.find(m_gameModelPtr->getState()) != m_mapOfGameStateHandlerPtr.end())
		{
			m_mapOfGameStateHandlerPtr[m_gameModelPtr->getState()]->endGame();
		}
	}
}
