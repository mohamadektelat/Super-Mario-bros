#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class GoompaO : public Enemy
{
public:
	GoompaO(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};