#include "Game.h"

//Static funcs


//Initializer funcs


//Constructors/Destructors


void Game::InitWindow()
{
	std::ifstream ifs("Config/window.ini");

	sf::VideoMode windowBounds(800, 600);
	std::string title = "None";
	unsigned frameRateLimit = 60;
	bool verticalSyncEnabled = false;

	if (ifs.is_open()) 
	{
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> frameRateLimit;
		ifs >> verticalSyncEnabled;
	}
	ifs.close();

	this->window = new sf::RenderWindow(windowBounds, title);
	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::InitStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys));


}

void Game::InitKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open()) {
		std::string key = "";
		int keyValue = 0;
		while(ifs>> key >> keyValue)
		{
			this->supportedKeys[key] = keyValue;

		}
	}
	ifs.close();



	for (auto i : this->supportedKeys) {
		std::cout << i.first << " " << i.second << "\n";
	}
}

Game::Game()
{
	this->InitWindow();
	this->InitKeys();
	this->InitStates();
	
	
}
Game::~Game() 
{
	delete this->window;

	while (!this->states.empty()) 
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::QuitApplication()
{
	std::cout << "Ending Application!" << "\n";
}

void Game::UpdateDt()
{
	//Updates time deltaTime with the time it takes to update and render one frame.
	this->dt = this->dtClock.restart().asSeconds();

	//system("cls");
	//std::cout << this->dt << "\n";
}

void Game::Update()
{
	this->UpdateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->Update(this->dt);

		if (this->states.top()->GetQuit()) {
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else {
		this->QuitApplication();
		this->window->close();
	}
}

void Game::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::Render()
{
	this->window->clear();

	if (!this->states.empty()) {
		this->states.top()->Render(this->window);

	}

	this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen()) 
	{
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}
