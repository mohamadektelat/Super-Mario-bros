#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MovingObject.h"
#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class Player : public MovingObject
{
public:

    /* PLAYER CONSTRUCTOR */
    Player(const std::shared_ptr<Board>& board);

    void jump() override;

    void endJump();

    /* MOVE PLAYER IN GIVING DIRECTION */
    void move(Direction dir) override;

    void endWalk();

    void updatePosition() override;

    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    virtual void setLife(int vary);

    int getLife()const;

    /* ADD COIN TO PLAYER COINS */
    void setCoin();

    void setNumOfEnemys();

    void setScore();

    int getScore()const;

    /* UPDATE STOMP WITH PLAYER */
    void stomp();

    /* UPDATE JUMP OF TRAMPOLINE */
    void stompTrampoline();

    /* CHECK IF PLAYER IS ALIVE */
    bool isAlive();

    void reset();
    
    /* KILL PLAYER */
    void kill();

private:
    void setDirection(Direction dir) override;


    //-----Variables and constants------------
    Resource_Holder<sf::Texture, std::string> m_Textures;

    Resource_Holder<sf::Font, std::string> m_Fonts;

    AnimatedSprite m_Sprite;
    Sound m_JumpSound;
    Sound m_StompSound;
    Sound m_DiedSound;
    Sound m_TrampolineSound;
 
    int m_Lifes = PLAYERLIFE;
    int m_Coins = ZERO;
    int m_NumberOfEnemys = ZERO;
    int m_Score = ZERO;

    bool m_HorisontalButtonHeld = false;

    bool m_JumpKeyReleased = true;
};