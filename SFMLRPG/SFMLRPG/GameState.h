#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
class GameState: public State{
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	//Functions	
	void EndState();

	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
private:
	Entity player;
	
	void InitKeybinds();

};
#endif // !MAINMENU_H

