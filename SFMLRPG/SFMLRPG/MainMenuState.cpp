#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys,states)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFonts();
	this->InitKeybinds();
	this->InitButtons();
	
	//this->bg.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->bg.setFillColor(sf::Color::Magenta);
}

void MainMenuState::EndState()
{
	std::cout << "Ending main menu scene!" << "\n";
}

void MainMenuState::UpdateInput(const float& dt)
{
	//this->CheckForQuit();
	
}

void MainMenuState::UpdateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->Update(this->mousePosView);
	}
	if (this->buttons["GAME_STATE"]->IsPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	if (this->buttons["EXIT"]->IsPressed())
	{
		this->quit = true;
	}

}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateInput(dt);
	this->UpdateButtons();

	//Debug Mouse Position
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	
	
}
void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->bg);
	this->RenderButtons(target);

	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x , this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
}
void MainMenuState::RenderButtons(sf::RenderTarget * target)
{
	for (auto &it : this->buttons)
	{
		it.second->Render(target);
	}

}
void MainMenuState::InitVariables()
{
}
void MainMenuState::InitBackground()
{
	this->bg.setSize(sf::Vector2f
	(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y))
	);

	
	if (!this->bgTexture.loadFromFile("Images/bg01.jpeg")) {
		throw "ERROR:MAIN MENU FAILED TO LOAD BACKGROUND TEXTURE";
	}
	this->bg.setTexture(&this->bgTexture);
}
void MainMenuState::InitFonts()
{
	if (!this->font.loadFromFile("Fonts/OpenSans.ttf")) 
	{
		throw("COULD NOT LOAD FONT!!!");
	}
}
void MainMenuState::InitKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
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
void MainMenuState::InitButtons()
{
	this->buttons["GAME_STATE"] = new Button(50, 250, 150, 50, "Start",
		&this->font, sf::Color(70, 70, 70, 200),
		sf::Color(155, 155, 155, 200),
	sf::Color(22, 22, 22, 200));
	

	this->buttons["SETTINGS"] = new Button(50, 350, 150, 50, "Settings",
		&this->font, sf::Color(70, 70, 70, 200),
		sf::Color(155, 155, 155, 200),
		sf::Color(22, 22, 22, 200));

	this->buttons["EXIT"] = new Button(50, 450, 150, 50, "Exit",
		&this->font, sf::Color(70, 70, 70, 200),
		sf::Color(155, 155, 155, 200),
		sf::Color(22, 22, 22, 200));
}
MainMenuState::~MainMenuState() 
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) 
	{
		delete it->second;
	}
}