#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void InitWindow();
	void InitKeys();
	void InitStates();
	


public:
	//Constructors/Destructors

	Game();
	virtual ~Game();

	//Funcs
	void QuitApplication();

	void UpdateDt();
	void Update();
	void UpdateSFMLEvents();

	void Render();

	void Run();

};

#endif

