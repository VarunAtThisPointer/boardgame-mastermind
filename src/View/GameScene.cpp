#include "GameScene.h"


/*
 * Constructor
 * Initializes the internal maps.
 */
GameScene::GameScene()
{
	m_gameStoped = false;
	m_MapOfStates["RED"] = RED;
	m_MapOfStates["YELLOW"]= YELLOW;
	m_MapOfStates["GREEN"]= GREEN;
	m_MapOfStates["ORANGE"]= ORANGE;
	m_MapOfStates["VOILET"]= VOILET;
	m_MapOfStates["BLUE"]= BLUE;
	m_MapOfStates["WHITE"]= WHITE;
	m_MapOfStates["BLACK"]= BLACK;
	m_MapOfStates["EMPTY"]= EMPTY;

	for(std::map< std::string, PegColor>::iterator it = m_MapOfStates.begin(); it != m_MapOfStates.end(); it++)
	{
		m_MapOfColors[it->second] = it->first;
	}

}
/*
 * Returns a list of all possible Peg Names.
 */
std::vector<std::string> GameScene::getAllPegNames()
{
	std::vector<std::string> vecOfStrs;
	for(std::map< std::string, PegColor>::iterator it = m_MapOfStates.begin(); it != m_MapOfStates.end(); it++)
	{
		if(it->first != "EMPTY" && it->first != "BLACK" && it->first != "WHITE" )
			vecOfStrs.push_back(it->first);

	}
	return vecOfStrs;
}
/*
 * Initializes the Game
 */
void GameScene::init()
{
	m_gameStoped = false;
}
/*
 * Fetch the PegColor based on passed string.
 * Also check if it's correct string or not.
 */
bool GameScene::getPegColor(std::string color, PegColor & pegColor)
{
	if(color == "EMPTY" || color == "WHITE" || color == "BLACK")
		return false;

	if(m_MapOfStates.find(color) != m_MapOfStates.end())
	{

		pegColor = m_MapOfStates[color];
		return true;
	}

	return false;
}
/*
 * Render the Current Scene.
 * It displays the Game Information and accepts input from user for all the rows in Board
 */
bool GameScene::render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr)
{
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************GAME STARTED*****************************************"<<std::endl;
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	
	std::cout<<"Game Status :: ";
	std::cout<<"Please enter the data for "<<gameModelPtr->getRowCount() <<std::endl;
	std::cout<<"Colors Allowed are ::  ";
	std::vector<std::string>  allColorNames = getAllPegNames();
	for(int i = 0; i < allColorNames.size(); i++)
	{
		std::cout<<allColorNames[i];
		if(i < allColorNames.size() -1 )
			std::cout<<" , ";
	}
	std::cout<<std::endl;
	std::cout<<"Give STOP Command to stop the game and return to Main Menu"<<std::endl;
	for( int i = 0; i < gameModelPtr->getRowCount() ; i++)
	{
		if(m_gameStoped)
			return true;
		for(int k = 0; k < gameModelPtr->getPegsInRow(); k++)
		{
			addPegData(i,k, gameControllerPtr, gameModelPtr);
			if(m_gameStoped)
				return true;
		}
		std::cout << "Peg Rows " << (i + 1) << " completed" << std::endl;

		std::cout << "Code Pegs for Peg Row " << (i + 1) << " are :: "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfCodePegs()[0].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfCodePegs()[1].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfCodePegs()[2].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfCodePegs()[3].getPegColor()]<<std::endl;


		std::cout << "Key Pegs for Peg Row " << (i + 1) << " are :: "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[0].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[1].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[2].getPegColor()]
				<< " , "
				<< m_MapOfColors[gameModelPtr->getGameBoard().getVecOfPegRows()[i].getVecOfKeyPegs()[3].getPegColor()]<<std::endl;
	}
	gameControllerPtr->endGame();
	return true;

}
/*
 * It Accepts an input for Peg Color and adds the Peg Data to the back-end Model.
 */
void GameScene::addPegData(int row, int pegNum, std::shared_ptr<GameController> gameControllerPtr,
			 std::shared_ptr<GameModel> gameModelPtr) {

		if(m_gameStoped)
			return;

		std::cout << "For PegRow " << (row + 1)
				<< " , Please enter CodePeg "<<(pegNum + 1)<<" :: ";
		std::string color;
		std::cin >> color;
		PegColor pegColor;
		if (getPegColor(color, pegColor) == true) {
			if(gameControllerPtr->addCodePegs(row, Peg(pegColor, CODE), pegNum) )
			{
				m_gameStoped = true;
			}
		}
		else if(color == "STOP")
		{
			gameControllerPtr->stopGame();
			m_gameStoped = true;
		}
		else
		{
			std::cout << "Wrong Choice :: Do it again" << std::endl;
			this->addPegData(row, pegNum, gameControllerPtr, gameModelPtr);
		}
	}
