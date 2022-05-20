#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Board.h"
#include "AnimatedSprite.h"
#include <string>


//---------------------------------------------------------------------------------------------------------------------


class MovingObject
{
public:

    /* A MOVING OBJECT CONSTRUCTOR WHICH BUILDS CHARACHTERS USING GIVING WIDTH AND HEIGHT */
    MovingObject(const int width, const int height, const std::shared_ptr<Board>& board);  

    /* SET (JUMP, MOVE, MAX, STOP) SPEEDS FOR THE MOVING OBJECT */
    void setJumpSpeed(const float value);   
    void setMoveSpeed(const float value);   
    void setMaxSpeed(const float value);    
    void setStopSpeed(const float value);   

    /* SET & GET (VERTICAL, HORISONAL) VELOCITY FOR MOVING OBJECT */
    void setVerticalVelocity(const float value);    
    void setHorisontalVelocity(const float value); 
    void setVelocity(const sf::Vector2f _velocity); 
    sf::Vector2f getVelocity() const;   


    /* SET & GET POSITION FOR MOVING OBJECT */
    sf::Vector2f getPosition() const;   
    void setPosition(const sf::Vector2f _position); 

    virtual sf::Sprite getSprite() const = 0;  

    virtual void draw(sf::RenderWindow& window) = 0;    

    void reset();

    /* ENUM FOR DIRECTIONS */
    enum Direction 
    {
        Left = -1,
        Right = 1
    };

    /* VIRTUAL FUNCTIONS TH ADJUST IN CHILDREN CLASSES */
    virtual void move(Direction dir);   
    virtual void jump();   
    virtual void updatePosition();  
    virtual void setDirection(Direction dir);
    virtual bool isAlive() const;
    virtual void kill();
    virtual void setLife(int vary);

    Direction getDirection() const;

    bool onGround() const;

    /* BOUNDARIES FUNCTIONS */
    float leftBoundary() const;
    float rightBoundary() const;
    float topBoundary() const;
    float bottomBoundary() const;

private:

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;


    //-----Variables and constants------------

    const std::shared_ptr<Board> m_Board;

    const int m_Height;
    const int m_Width;

    bool m_OnGround = false;

    float m_JumpSpeed = ZERO;
    float m_MoveSpeed = ZERO;
    float m_MaxSpeed = ZERO;
    float m_StopSpeed = ZERO;

    sf::Vector2f m_Velocity = { ZERO, ZERO };
    sf::Vector2f m_Position;

    Direction m_Dir = Right;

    bool m_IsAlive = true;

};