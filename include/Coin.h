#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "IdleObject.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class Coin : public IdleObject
{
public:
    Coin(const sf::Vector2f position, const std::shared_ptr<Board>& board);

    /* RETURN THE TYPE NAME OF THE OBJECT */
    virtual std::string name()override;

    /* SET COIN AS TAKEN*/
    void setTaken()override;

    /* CHECK IF COIN IS TAKEN ALREADY */
    bool isTaken()override;

    /* UPDATE ANIMATION OF COIN */
    void update()override;

private:
    bool m_GotCoin = false;
};