#include "GameState.h"
	GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
		this->InitKeybinds();
}

	void GameState::EndState()
	{
		
	}

	void GameState::UpdateInput(const float& dt)
	{
		this->CheckForQuit();


		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
			this->player.Move(dt, -1.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
			this->player.Move(dt, 1.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
			this->player.Move(dt, 0.0f, -1.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
			this->player.Move(dt, 0.0f, 1.0f);
	}

	void GameState::Update(const float& dt)
{
		this->UpdateMousePositions();
		this->UpdateInput(dt);

		this->player.Update(dt);
}
	void GameState::Render(sf::RenderTarget* target)
{
		if (!target)
		target = this->window;

		this->player.Render(target);
}
	void GameState::InitKeybinds()
	{
		std::ifstream ifs("Config/gamestate_keybinds.ini");
		if (ifs.is_open()) {
			std::string key = "";
			std::string keyValue = "";
			while (ifs >> key >> keyValue)
			{
				this->keybinds[key] = this->supportedKeys->at(keyValue);

			}
		}
		ifs.close();


		

	}
	GameState::~GameState() 
{

}