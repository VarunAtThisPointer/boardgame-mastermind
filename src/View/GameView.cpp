
#include "GameView.h"


/*
 * Constructor
 * It initializes the Scene map based on the Game State
 * Also initializes the active scene.
 */
GameView::GameView(std::shared_ptr<GameModel> gameModelPtr, std::shared_ptr<GameController> gameCtrlPtr): m_gameModelPtr(gameModelPtr), m_gameControlletPtr(gameCtrlPtr)
{
	m_mapOfGameScenes[MAIN_MENU] = std::shared_ptr<Scene>(new MainMenuScene());
	m_mapOfGameScenes[GAME_IN_PROGRESS] = std::shared_ptr<Scene>(new GameScene());
	m_mapOfGameScenes[GAME_ENDED] = std::shared_ptr<Scene>(new EndScene());
	m_mapOfGameScenes[HELP_MODE] = std::shared_ptr<Scene>(new HelpScene());

	m_activeScene = m_mapOfGameScenes[MAIN_MENU];



}
/*
 * This function will be invoked by Subject, to notify the state change.
 * On notification it changes the active scene and render it.
 */
void GameView::update()
{
	if(m_gameModelPtr)
	{
		if(m_mapOfGameScenes.find(m_gameModelPtr->getState()) != m_mapOfGameScenes.end())
			m_activeScene = m_mapOfGameScenes[m_gameModelPtr->getState()];
	}
	m_activeScene->init();
	//render();
}
/*
 * This function renders the active scene i.e. make it visible
 */
void GameView::render()
{
	while(!!m_activeScene )
	{
		system("clear");
		if( m_activeScene->render(m_gameModelPtr, m_gameControlletPtr) == false)
		{
			std::cout<<std::endl<<"***Thanks For Playing***"<<std::endl;
			break;
		}
	}
}
