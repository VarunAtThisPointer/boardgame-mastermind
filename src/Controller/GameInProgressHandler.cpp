#include "GameInProgressHandler.h"

/*
 * Destructor
 */
GameInProgressHandler::~GameInProgressHandler() {

}

/*
 * Constructor
 */
GameInProgressHandler::GameInProgressHandler(std::shared_ptr<GameModel> gameModelPtr) : 	GameStateHandler(gameModelPtr)
{}
/*
 * This API is allowed to be called by View in GAME_IN_PROGRESS state.
 * It Initializes the Model
 */
void GameInProgressHandler::stopGame()
{
	m_gameModelPtr->initGame();
}
/*
 * This API is allowed to be called by View in GAME_IN_PROGRESS state.
 * It adds the Code Pegs in Model.
 */
bool GameInProgressHandler::addCodePegs(int rowIndex, Peg PegObj, int pegIndex)
{
	if(m_gameModelPtr)
	{
		m_gameModelPtr->getGameBoard().addCodePegInRow(rowIndex, PegObj, pegIndex);
		if(m_gameModelPtr->getGameBoard().getVecOfPegRows()[rowIndex].IsCodePegsAndKeyPegsAreEqual())
		{
			m_gameModelPtr->setState(GAME_ENDED);
			return true;
		}
	}
	return false;
}
/*
 * This API is allowed to be called by View in GAME_IN_PROGRESS state.
 * It sets the Model state to GAME_ENDED.
 */
void GameInProgressHandler::endGame()
{
	m_gameModelPtr->setState(GAME_ENDED);
}
