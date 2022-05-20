#pragma once

//---------------------------------------------------------------------------------------------------------------------


#include "Block.h"
#include <iostream>
#include <SFML/Graphics.hpp>


//---------------------------------------------------------------------------------------------------------------------


Block::Block(Type type, const int x, const int y)
{
    try
    {
        m_Textures.load(type, BLOCKSPATH, sf::IntRect(Sprite::getTextureSize() * type, ZERO, Sprite::getTextureSize(), Sprite::getTextureSize()));
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    m_Sprite.setTexture(m_Textures.get(type));

    m_Sprite.setPosition(x, y);
}


//---------------------------------------------------------------------------------------------------------------------


void Block::draw(sf::RenderWindow& window)
{
    window.draw(m_Sprite);
}


//---------------------------------------------------------------------------------------------------------------------

