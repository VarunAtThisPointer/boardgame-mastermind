#include "MainMenuScene.h"

/*
 * Constructor
 */
MainMenuScene::MainMenuScene() {


}

/*
 * Destructor
 */
MainMenuScene::~MainMenuScene() {

}

/*
 * Renders the current scene
 * Shows the Help Data for the Game.
 */
bool MainMenuScene::render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr)
{
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************MasterMind Game*****************************************"<<std::endl;
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;

	std::cout<<"Main Menu :: "<<std::endl;
	std::cout<<"1 :: Start The Game"<<std::endl;
	std::cout<<"2 :: Help"<<std::endl;
	std::cout<<"3 :: Exit"<<std::endl;
	std::cout<<"Please Enter your choice  :: ";
	int choice = 0;
	std::cin>>choice;
	if(choice == 1)
		gameControllerPtr->startGame();
	else if(choice == 2)
		gameControllerPtr->gotoHelpMenu();
	else if(choice == 3)
		return false;
	else
		std::cout<<"Wrong Input, Please Retry"<<std::endl;
	return true;

}
