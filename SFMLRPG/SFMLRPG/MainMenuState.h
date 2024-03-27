#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "Button.h"
class MainMenuState : public State
{
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//Functions	
	void EndState();

	void UpdateInput(const float& dt);
	void UpdateButtons();
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
	void RenderButtons(sf::RenderTarget* target = nullptr);
private:
	sf::RectangleShape bg;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	void InitFonts();
	void InitKeybinds();
	void InitButtons();
};
#endif // !MAINMENU_H

