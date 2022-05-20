#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceHolder.h"


//---------------------------------------------------------------------------------------------------------------------


Enemy::Enemy(const sf::Vector2f position, const std::shared_ptr<Board>& board , const std::string id, const std::string path,int first, int last, bool moving) :
    MovingObject(OBJECTWIDTH, OBJECTHEIGHT, board),
    m_Sprite(OBJECTWIDTH, OBJECTHEIGHT, 0.1),
    m_first(first),
    m_last(last),
    m_isMoving(moving)
{
    /* SET (X) VELOCITY OF ENEMY */
    setHorisontalVelocity(ENEMYSPEED);
    setStopSpeed(0);

    /* SET POSITION */
    MovingObject::setPosition(position);

    /* TRY TO LOAD IMAGE FROM PATH: THROW EXCEPTION WHEN ERROR OCCURS */
    try
    {
        m_Textures.load(id, path);
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    m_Sprite.setTexture(m_Textures.get(id));
}


//---------------------------------------------------------------------------------------------------------------------


void Enemy::updatePosition()
{
    if (m_isMoving)
    {
        /* UPDATE LAST TEXTURE */
        m_Sprite.update(m_first, m_last);

        /* IN CASE STUCK: FLIP & GO */
        if (getVelocity().x == ZERO)
        {
            flip();
            setHorisontalVelocity(ENEMYSPEED * getDirection());
        }

        MovingObject::updatePosition();

        m_Sprite.setPosition(getPosition().x, getPosition().y);
        return;
    }
    m_Sprite.setPosition(getPosition().x, getPosition().y);
    m_Sprite.update(m_first, m_last);
}


//---------------------------------------------------------------------------------------------------------------------



sf::Sprite Enemy::getSprite() const
{
    return m_Sprite;
}


//---------------------------------------------------------------------------------------------------------------------



void Enemy::kill()
{
    setLife(-1);
    if (getLife() == ZERO)
        MovingObject::kill();
}


//---------------------------------------------------------------------------------------------------------------------



void Enemy::setLife(int vary)
{
    m_Life +=vary;
}


//---------------------------------------------------------------------------------------------------------------------



int Enemy::getLife() const
{
    return m_Life;
}


//---------------------------------------------------------------------------------------------------------------------



bool Enemy::getMoving() const
{
    return m_isMoving;
}


//---------------------------------------------------------------------------------------------------------------------


/* FLIP DIRECTION TO THE OTHER DIRECTION */
void Enemy::flip()
{
    if (getDirection() == Left)  
        setDirection(Right);
    else                        
        setDirection(Left);

    m_Sprite.flip();
}


//---------------------------------------------------------------------------------------------------------------------



void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(m_Sprite);
}


//---------------------------------------------------------------------------------------------------------------------
