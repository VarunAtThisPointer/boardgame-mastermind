/*
 * It's an abstract class represents the Game Scenes.
 * Client of this class can render it.
 */
#ifndef SCENE_H_
#define SCENE_H_
#include "GameModel.h"
#include "GameController.h"
#include <memory>

class Scene {
public:
	Scene();
	virtual ~Scene();
	virtual bool render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr) = 0;
	virtual void init(){}
};

#endif /* SCENE_H_ */
