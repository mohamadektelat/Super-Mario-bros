#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Turtle.h"


//---------------------------------------------------------------------------------------------------------------------


Turtle::Turtle(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
	Enemy(position, board, "ss", "sprite1.png", 0, 3, true)
{
}


//---------------------------------------------------------------------------------------------------------------------
