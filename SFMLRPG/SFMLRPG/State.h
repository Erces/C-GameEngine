
#ifndef STATE_H
#define STATE_H
#include "Entity.h"

class State
{

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;

	std::vector<sf::Texture> textures;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



	virtual void InitKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
	virtual ~State();

	const bool& GetQuit() const;

	virtual void CheckForQuit();
	virtual void EndState() = 0;
	virtual void UpdateMousePositions();

	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
};
#endif

#ifndef GET_KEY
#define GET_KEY_BIND this->keybinds.at
#define GET_KEY_INPUT this->supportedKeys->at
#endif

