#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "GoompaO.h"

//---------------------------------------------------------------------------------------------------------------------


GoompaO::GoompaO(const sf::Vector2f position, const std::shared_ptr<Board>& board):
	Enemy(position , board , "goomba" ,GOOMBAPATH,0,1,true)
{
}


//---------------------------------------------------------------------------------------------------------------------