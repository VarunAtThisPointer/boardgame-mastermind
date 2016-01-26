#include "HelpScene.h"

/*
 * COnstructor
 */
HelpScene::HelpScene() {
	// TODO Auto-generated constructor stub

}
/*
 * Destructor
 */
HelpScene::~HelpScene() {
}
/*
 * Renders the current scene
 * Shows the Help Data for the Game.
 */
bool HelpScene::render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr)
{

	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	std::cout<<"*************************HELP MENU*****************************************"<<std::endl;
	std::cout<<"---------------------------------------------------------------------------"<<std::endl;
	
	std::cout<<"Here should be the text realted to Game Help"<<std::endl<<std::endl<<std::endl;

	std::cout<<"Press any alphabet key to enter Main Menu"<<std::endl;
	std::string str;
	std::cin>>str;
	gameControllerPtr->gotoMainMenu();
	return true;


}
