#include <iostream>
#include <memory>
#include "PegRow.h"
#include "Peg.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"


int main()
{
	// Create Game Model
	std::shared_ptr<GameModel> gameModelPtr = std::make_shared<GameModel>(12,4);
	

	// Create Game Controller
	std::shared_ptr<GameController> gameControllerPtr = std::make_shared<GameController>(gameModelPtr);
	gameControllerPtr->init();
	
	// Create Game View
	std::shared_ptr<GameView> gameViewObj = std::make_shared<GameView>(gameModelPtr, gameControllerPtr);
	gameModelPtr->attach(gameViewObj);
	
	// Start the Game
	gameViewObj->render();
	return 0;
}
