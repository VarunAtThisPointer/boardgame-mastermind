/*
 * This class represents the Active Game screen i.e. Game screen in
 * case of state GAME_IN_PROGRESS
 */
#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "Scene.h"
#include <iterator>
#include <map>
#include <algorithm>
#include <string>

class GameScene: public Scene {
	bool m_gameStoped;
	std::map< std::string, PegColor> m_MapOfStates;
	std::map<  PegColor, std::string> m_MapOfColors;
public:
	GameScene();
	std::vector<std::string> getAllPegNames();
	void init();
	virtual ~GameScene(){}
	bool getPegColor(std::string color, PegColor & pegColor);
	bool render(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameControllerPtr);
private:
	void addPegData(int row, int pegNum, std::shared_ptr<GameController> gameControllerPtr,
			 std::shared_ptr<GameModel> gameModelPtr);
};

#endif /* GAMESCENE_H_ */
