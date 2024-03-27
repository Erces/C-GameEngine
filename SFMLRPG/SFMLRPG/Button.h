#ifndef BUTTON_H
#define BUTTON_H

#include<vector>

#include <fstream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <ctime>
#include <stack>
#include <map>
#include <vector>

enum buttonStates{ BTN_IDLE = 0, BTN_HOVER,BTN_PRESSED};

class Button
{
protected:


private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:
	Button(float x,float y,float width,float height,
		std::string text,sf::Font* font,sf::Color idleColor,
		sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	void Update(const sf::Vector2f mousePos);
	void Render(sf::RenderTarget* target);

	const bool IsPressed() const;

};
#endif

