#include "State.h"

State::State(sf::RenderWindow* _window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
	this->window = _window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
}
State::~State()
{
	
}

const bool& State::GetQuit() const
{
	return this->quit;
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(GET_KEY_BIND("ESCAPE")))) {
		this->quit = true; 
	}
}

void State::UpdateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));



}


