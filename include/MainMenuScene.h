#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "Scene.h"

class MainMenuScene: public Scene {
public:
	MainMenuScene();
	virtual ~MainMenuScene();
	bool render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr);

};

#endif /* MAINMENUSCENE_H_ */
