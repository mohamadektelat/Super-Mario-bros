#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class Turtle : public Enemy
{
public:
	Turtle(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};