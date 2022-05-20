#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>
#include "Utils.h"
#include "IdleObject.h"


//---------------------------------------------------------------------------------------------------------------------


class Question : public IdleObject
{
public:

    /* QUESTION BOX CONSTRUCTOR */
    Question(const sf::Vector2f position, const std::shared_ptr<Board>& board);

    /* GET THE TYPE OF THE OBJECT */
    virtual std::string name()override;
    bool isTaken() override;
    void setTaken()override;

    /* UPDATE THE ANIMATION OF THE BOX ONCE TAKEN */
    void update()override;
private:
    bool m_taken = false;
};