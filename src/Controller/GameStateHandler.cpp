#include "GameStateHandler.h"

/*
 * Constructor
 */
GameStateHandler::GameStateHandler(std::shared_ptr<GameModel> gameModelPtr) : m_gameModelPtr(gameModelPtr)
{}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::stopGame()
{
	std::cout<<"stopGame Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::endGame()
{
	std::cout<<"startGame Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::startGame()
{
	std::cout<<"startGame Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
bool GameStateHandler::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	std::cout<<"addCodePegs Not Allowed in this state"<<std::endl;
	return false;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::gotoMainMenu()
{
	std::cout<<"gotoMainMenu Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::gotoHelpMenu()
{
	std::cout<<"gotoHelpMenu Not Allowed in this state"<<std::endl;
}

/*
 * Provides the Generic Implementation. This API will called if View has called an API that is
 * not allowed in current State
 */
void GameStateHandler::exit()
{
	std::cout<<"exit Not Allowed in this state"<<std::endl;
}
