/*
 * This class represents the View from MVC Design.
 * It fetches the information from Model and generates the User Interface
 * It's shows the game data to use and accepts input from it.
 */
#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_
#include "Observer.h"
#include "Scene.h"
#include "MainMenuScene.h"
#include "GameModel.h"
#include "GameController.h"
#include "GameScene.h"
#include "EndScene.h"
#include "HelpScene.h"
#include <list>
#include <memory>
#include <functional>
#include <algorithm>
#include <map>

using namespace std::placeholders;
class GameView : public Observer
{
	std::shared_ptr<Scene> m_activeScene;
	std::shared_ptr<GameModel> m_gameModelPtr;
	std::shared_ptr<GameController> m_gameControlletPtr;
	std::map<GameState, std::shared_ptr<Scene> > m_mapOfGameScenes;
public:
	GameView(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameCtrlPtr);
	virtual ~GameView(){}
	void update();
	void render();
};

#endif /* GAMEVIEW_H_ */
