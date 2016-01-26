
#ifndef HELPSCENE_H_
#define HELPSCENE_H_

#include "Scene.h"

class HelpScene: public Scene {
public:
	HelpScene();
	virtual ~HelpScene();
	bool render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr);
};

#endif /* HELPSCENE_H_ */
