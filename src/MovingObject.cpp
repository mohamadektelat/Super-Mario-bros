#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MovingObject.h"
#include <iostream>
#include <cmath>

//---------------------------------------------------------------------------------------------------------------------


MovingObject::MovingObject(const int width, const int height, const std::shared_ptr<Board>& board) :
    m_Board(board),
    m_Width(width),
    m_Height(height)
{}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setJumpSpeed(const float value)
{
    m_JumpSpeed = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setMoveSpeed(const float value)
{
    m_MoveSpeed = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setMaxSpeed(const float value)
{
    m_MaxSpeed = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setStopSpeed(const float value)
{
    m_StopSpeed = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setVerticalVelocity(const float value)
{
    m_Velocity.y = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setHorisontalVelocity(const float value)
{
    m_Velocity.x = value;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setVelocity(const sf::Vector2f _velocity)
{
    m_Velocity = _velocity;
}


//---------------------------------------------------------------------------------------------------------------------


sf::Vector2f MovingObject::getVelocity() const
{
    return m_Velocity;
}


//---------------------------------------------------------------------------------------------------------------------


sf::Vector2f MovingObject::getPosition() const
{
    return m_Position;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setPosition(const sf::Vector2f _position)
{
    m_Position = _position;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::reset()
{
    m_IsAlive = true;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::move(Direction dir)
{
    /* SET DIRECTION FIRST, THEN SET VELOCITY */
    setDirection(dir);
    m_Velocity.x = m_Velocity.x + dir * m_MoveSpeed;

    if (fabsf(m_Velocity.x) > m_MaxSpeed) m_Velocity.x = dir * m_MaxSpeed;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::jump()
{
    setVerticalVelocity(m_JumpSpeed);
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::updatePosition()
{
    /* UPDATE Y VELOCITY AND POSITION */
    m_Velocity.y += GRAVITY;
    m_Position.y += m_Velocity.y;
    checkForGround();

    if (!isAlive())  return;

    checkForRoof();

    /* CHECK & SET (X) VELOCITY AND POSITION */
    if (fabsf(m_Velocity.x) < m_StopSpeed)    
        m_Velocity.x = ZERO;
    else if (m_Velocity.x > ZERO)              
        m_Velocity.x -= m_StopSpeed;
    else                                
        m_Velocity.x += m_StopSpeed;
    m_Position.x += m_Velocity.x;
    checkForWall();

}


//---------------------------------------------------------------------------------------------------------------------


MovingObject::Direction MovingObject::getDirection() const
{
    return m_Dir;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setDirection(Direction new_dir)
{
    if (m_Dir != new_dir)  m_Dir = new_dir;
}


//---------------------------------------------------------------------------------------------------------------------


bool MovingObject::onGround() const
{
    return m_OnGround;
}


//---------------------------------------------------------------------------------------------------------------------


bool MovingObject::isAlive() const
{
    return m_IsAlive;
}


//---------------------------------------------------------------------------------------------------------------------


float MovingObject::leftBoundary() const
{
    return m_Position.x;  //positionX;
}


//---------------------------------------------------------------------------------------------------------------------


float MovingObject::rightBoundary() const
{
    return m_Position.x + m_Width;
}


//---------------------------------------------------------------------------------------------------------------------


float MovingObject::topBoundary() const
{
    return m_Position.y;
}


//---------------------------------------------------------------------------------------------------------------------


float MovingObject::bottomBoundary() const
{
    return m_Position.y + m_Height;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::kill()
{
    m_IsAlive = false;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::setLife(int vary)
{
}

//---------Privata functiones---------------


int MovingObject::bufferedRoundoff(float i) const
{
    //If there are no decimals at all, give the same box we are on
    if (i == (int)i) 
        return i - 1;
    else           
        return i;
}


//---------------------------------------------------------------------------------------------------------------------


int MovingObject::left() const
{
    return m_Position.x; 
}


//---------------------------------------------------------------------------------------------------------------------


int MovingObject::right() const
{
    return bufferedRoundoff(m_Position.x + m_Width);   
}


//---------------------------------------------------------------------------------------------------------------------


int MovingObject::top() const
{
    return m_Position.y;
}


//---------------------------------------------------------------------------------------------------------------------


int MovingObject::bottom() const
{
    return bufferedRoundoff(m_Position.y + m_Height);
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::checkForGround()
{
    /* IN CASE FALLING DOWN: KILL OBJECT */
    if (m_Position.y > m_Board->bottomBoundary() - m_Height)
    {
        kill();
        return;
    }

    /* CHECK IF ON GROUND: SET Y VELOCITY & POSITION */
    if (m_Board->isSolidBlock(bottom(), left()) ||    
        m_Board->isSolidBlock(bottom(), right()))     
    {
        m_Position.y = top();
        m_Velocity.y = ZERO;
        m_OnGround = true;
    }
    else    m_OnGround = false;
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::checkForRoof()
{
    /*  CHECK IF ON ROOF: SET Y VELOCITY & POSITION */
    if (m_Board->isSolidBlock(top(), left()) ||   
        m_Board->isSolidBlock(top(), right()))   
    {
        m_Position.y = top() + 1;
        m_Velocity.y = -m_Velocity.y;
    }
}


//---------------------------------------------------------------------------------------------------------------------


void MovingObject::checkForWall()
{

    /* IN CASE LEFT BOUNDARY IS LEFT: SET X POSITION AND VELOCITY */
    if (m_Position.x < m_Board->leftBoundary())
    {
        m_Position.x = m_Board->leftBoundary();
        m_Velocity.x = ZERO;
    }

    /* IN CASE RIGHT BOUNDARY IS RIGHT: SET X POSITION AND VELOCITY */
    if (m_Position.x > m_Board->rightBoundary() - m_Width)
    {
        m_Position.x = m_Board->rightBoundary() - m_Width;
        m_Velocity.x = ZERO;
    }

    /* IS WALL FUNCTION: RETURNS YES IF WALL IS FOUND, FALSE OTHERWISE */
    auto isWall = [&](const float x)
    {
        for (int i = ZERO; i < m_Height; i++)
        {
            if (m_Board->isSolidBlock(top() + i, x))
                return true;
        }
        if (m_Board->isSolidBlock(bottom(), x)) return true;
        return false;
    };

    /* IN CASE WALL IS LEFT OR RIGHT: SET VELOCITY & POSITION */
    if (isWall(left()))
    {
        m_Position.x = left() + 1;
        m_Velocity.x = ZERO;
    }

    //Check right
    if (isWall(right()))
    {
        m_Position.x = right() - 1;
        m_Velocity.x = ZERO;
    }
}


//---------------------------------------------------------------------------------------------------------------------
