#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "IdleObject.h"
#include "Enemy.h"
#include "Board.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class Grass : public Enemy
{
public:
    Grass(const sf::Vector2f position, const std::shared_ptr<Board>& board);

};