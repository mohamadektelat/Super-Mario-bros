#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Player.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>


//---------------------------------------------------------------------------------------------------------------------


Player::Player(const std::shared_ptr<Board>& board) :
    MovingObject(OBJECTWIDTH, PLAYERHEIGHT, board),
    m_Sprite(OBJECTWIDTH, PLAYERHEIGHT),
    m_JumpSound(JUMPSOUNDSPATH),
    m_StompSound(STOMPSOUNDSPATH),
    m_DiedSound(DIEDSOUNDPATH),
    m_TrampolineSound(TRAMPOLINESOUNDPATH)
{
    /* SET (MOVE, MAX, JUMP, STOP) SPEED FOR PLAYER */
    setPosition(PLAYERFIRSTPOS);
    setMaxSpeed(PLAYERMAXSPEED);
    setMoveSpeed(PLAYERSPEED);
    setJumpSpeed(PLAYERJUMPSPEED);
    setStopSpeed(PLAYERSTOPSPEED);

    /* TRY TO LOAD THE PLAYER TEXTURE: THROW EXCEPTION IN CASE FAILURE */
    try
    {
        m_Textures.load(MARIOID, MARIOPATH);
        m_Fonts.load(FONTID, FONTSPATH);
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    m_Sprite.setTexture(m_Textures.get(MARIOID));
}


//---------------------------------------------------------------------------------------------------------------------


void Player::jump()
{
    /* IN CASE NO JUMP: JUST IGNORE */
    if (!m_JumpKeyReleased)    return;

    /* UPDATE THE JUMP STATUS */
    m_JumpKeyReleased = false;

    /* IF STILL ON GROUND AND JUMP BUTTON IS PRESSED */
    if (onGround())
    {
        m_JumpSound.play();
        MovingObject::jump();
    }
}


//---------------------------------------------------------------------------------------------------------------------


void Player::endJump()
{
    m_JumpKeyReleased = true;

    if (getVelocity().y < PLAYERJUMPSPEED / 2) setVerticalVelocity(PLAYERJUMPSPEED / 2);
}


//---------------------------------------------------------------------------------------------------------------------


void Player::move(Direction dir)
{
    /* SET DIRECTION TO THE PLAYER THEN MOVE */
    setDirection(dir);
    MovingObject::move(dir);
}


//---------------------------------------------------------------------------------------------------------------------


void Player::endWalk()
{
    m_HorisontalButtonHeld = false;
}


//---------------------------------------------------------------------------------------------------------------------


void Player::updatePosition()
{
    /* IN CASE PLAYER IS NOT ON GROUND: PLAY MATCHING TEXTURE */
    if (!onGround())    
        m_Sprite.set(3);

    else if (m_Sprite.getCurrentTexture() == 3) 
        m_Sprite.set(ZERO);

    /* IN CASE PLAYER IS MOVING IN GROUND: PLAY RUNNING TEXTURE */
    else if (m_HorisontalButtonHeld)  
        m_Sprite.update(ZERO, 2);

    /* ELSE: PLAY INITIAL TEXTURE */
    else                     
        m_Sprite.update(ZERO, ZERO);

    MovingObject::updatePosition();

    m_Sprite.setPosition(getPosition().x, getPosition().y);
}


//---------------------------------------------------------------------------------------------------------------------


void Player::draw(sf::RenderWindow& window)
{
    /* GAME DATA SETTINGS: LIFE */
    sf::Text text1("Life: " + std::to_string(m_Lifes), m_Fonts.get(FONTID));
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::White);
    text1.setPosition({ window.getView().getCenter().x-170.f , -6.f });
    window.draw(text1);

    /* GAME DATA SETTINGS: COINS */
    sf::Text text2("Coins: " + std::to_string(m_Coins), m_Fonts.get(FONTID));
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition({ window.getView().getCenter().x + 90.f , -6.f });
    window.draw(text2);
    window.draw(m_Sprite);

    /* GAME DATA SETTINGS: SCORE */
    sf::Text text3("Score: " + std::to_string(m_Score), m_Fonts.get(FONTID));
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition({ window.getView().getCenter().x-50.f , -6.f });
    window.draw(text3);
    window.draw(m_Sprite);
}


//---------------------------------------------------------------------------------------------------------------------


sf::Sprite Player::getSprite() const
{
    return m_Sprite;
}


//---------------------------------------------------------------------------------------------------------------------


void Player::setLife(int vary)
{
    if(vary < ZERO)
        if (m_Lifes > 1)
        {
            m_DiedSound.play();
            sf::sleep(sf::seconds(3));
        }
    m_Lifes +=vary;
}


//---------------------------------------------------------------------------------------------------------------------


int Player::getLife() const
{
    return m_Lifes;
}


//---------------------------------------------------------------------------------------------------------------------


void Player::setCoin()
{
    m_Coins += 1;
    setScore();
}


//---------------------------------------------------------------------------------------------------------------------


void Player::setNumOfEnemys()
{
    m_NumberOfEnemys += 1;
    setScore();
}


//---------------------------------------------------------------------------------------------------------------------


void Player::setScore()
{
    m_Score = (m_Coins * 300) + (m_NumberOfEnemys * 100);
}


//---------------------------------------------------------------------------------------------------------------------


int Player::getScore() const
{
    return m_Score;
}


//---------------------------------------------------------------------------------------------------------------------


void Player::stomp()
{
    setVerticalVelocity(PLAYERJUMPSPEED / 2);
    m_StompSound.play();
}


//---------------------------------------------------------------------------------------------------------------------


void Player::stompTrampoline()
{
    setVerticalVelocity((PLAYERJUMPSPEED* 2)/3 );
    m_TrampolineSound.play();
}


//---------------------------------------------------------------------------------------------------------------------


bool Player::isAlive()
{
    return !(m_Lifes == ZERO);
}


//---------------------------------------------------------------------------------------------------------------------


void Player::reset()
{
    MovingObject::reset();
    setPosition(PLAYERFIRSTPOS);
    m_Lifes = 3;
    m_Score = ZERO;
    m_Coins = ZERO;
    m_NumberOfEnemys = ZERO;
}


//---------------------------------------------------------------------------------------------------------------------


void Player::kill()
{
    setLife(-1);
    setPosition(PLAYERFIRSTPOS);
    setVelocity({ ZERO,ZERO });
    if (getLife() == ZERO)
        MovingObject::kill();
}


//---------------------------------------------------------------------------------------------------------------------


void Player::setDirection(Direction new_dir)
{
    /* UPDATE HORIZONAL BUTTON */
    m_HorisontalButtonHeld = true;

    /* IN CASE NEW DIRECTION IS PRESSED: FLIP AND MOVE */
    if (getDirection() != new_dir)
    {
        m_Sprite.flip();
        MovingObject::setDirection(new_dir);
    }
}


//---------------------------------------------------------------------------------------------------------------------
