#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "IdleObject.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class Trampoline : public IdleObject
{
public:
    /* TRAMPOLINE CONSTRUCTOR */
    Trampoline(const sf::Vector2f position, const std::shared_ptr<Board>& board);

    /* GET THE TYPE OF THE OBJECT */
    virtual std::string name()override;

    /* UPDATE THE ANIMATION */
    void update();
    virtual void setTaken()override;
    virtual bool isTaken()override;
};