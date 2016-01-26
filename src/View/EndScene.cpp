#include "EndScene.h"
/*
 * Constructor
 */
EndScene::EndScene() {
}
/*
 * Destructor
 */
EndScene::~EndScene() {
}
/*
 * Renders the current scene
 * Shows the Data Related to End Scene on screen i.e. Either Game Won or Lost
 */
bool EndScene::render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr)
{

	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************GAME ENDED*****************************************"<<std::endl;
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::vector<PegRow > pegRows = gameModelPtr->getGameBoard().getVecOfPegRows();
	bool gameWon = false;
	for(int i = 0; i < pegRows.size(); i++)
	{
		if(pegRows[i].IsCodePegsAndKeyPegsAreEqual())
		{
			gameWon = true;
			break;
		}
	}
	std::cout<<std::endl;
	if(gameWon)
		std::cout<<"**Game Won**"<<std::endl;
	else
		std::cout<<"**Game Lost**"<<std::endl;

	std::cout<<std::endl;

	std::cout<<"Press any alphabet key to enter Main Menu"<<std::endl;
	std::string str;
	std::cin>>str;
	gameControllerPtr->gotoMainMenu();
	return true;


}
