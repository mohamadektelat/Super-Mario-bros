#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class GoompaB : public Enemy
{
public:
	GoompaB(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};