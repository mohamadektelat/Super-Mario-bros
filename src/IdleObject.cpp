#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "IdleObject.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------


IdleObject::IdleObject(const sf::Vector2f position, const std::shared_ptr<Board>& board , std::string id , std::string path) :
    m_Sprite(m_Width, m_Height, 0.1),
    m_Position(position)
{
    try
    {
        m_Textures.load(id, path);
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    /*m_GrassMusic.openFromFile(m_GrassMusicPath);*/
    m_Sprite.setTexture(m_Textures.get(id));
    m_Sprite.setPosition(position.x, position.y);
}


//---------------------------------------------------------------------------------------------------------------------


AnimatedSprite& IdleObject::getSprite()
{
    return m_Sprite;
}


//---------------------------------------------------------------------------------------------------------------------


void IdleObject::draw(sf::RenderWindow& window)
{
    window.draw(m_Sprite);
}


//---------------------------------------------------------------------------------------------------------------------


sf::Vector2f IdleObject::getPosition() const
{
    return m_Position;
}


//---------------------------------------------------------------------------------------------------------------------
