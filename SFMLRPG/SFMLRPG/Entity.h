#ifndef  ENTITY_H
#define ENTITY_H

#pragma region INCLUDES
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


#pragma endregion

class Entity
{
private:


protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	virtual void Move(const float& dt, const float x, const float y);

	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);


};
#endif

