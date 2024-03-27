#include "Button.h"

Button::Button(float x, float y, float width, float height,
	std::string text, sf::Font* font, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor) 
{
	this->buttonState = BTN_IDLE;

	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));

	this->font = font;


	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12.0f);
	this->text.setPosition(
		(this->shape.getPosition().x / 2.f) + this->shape.getPosition().x,
		(this->shape.getPosition().y + height/2) );

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);



}
Button::~Button() 
{


}

void Button::Update(const sf::Vector2f mousePos)
{
	//Update the enum for hover and pressed

	//Hover
	this->buttonState = BTN_IDLE;
	if (this->shape.getGlobalBounds().contains(mousePos)) 
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			this->buttonState = BTN_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_PRESSED:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);

}

const bool Button::IsPressed() const
{
	if (this->buttonState == BTN_PRESSED)
	return true;

	return false;
}
