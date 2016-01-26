#ifndef ENDSCENE_H_
#define ENDSCENE_H_

#include "Scene.h"

class EndScene: public Scene {
public:
	EndScene();
	virtual ~EndScene();
	bool render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr);
};

#endif /* ENDSCENE_H_ */
