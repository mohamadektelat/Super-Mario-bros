#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


AnimatedSprite::AnimatedSprite(const int width, const int height, const double speed) :
    width(width),
    height(height),
    speed(speed)
{
    setTextureRect(sf::IntRect(ZERO, ZERO, width * getTextureSize(), height * getTextureSize()));
}


//---------------------------------------------------------------------------------------------------------------------


void AnimatedSprite::set(const int texture)
{
    currentTexture = texture;
    setTextureRect(sf::IntRect(texture * getTextureSize(), ZERO, 16, 32));
}


//---------------------------------------------------------------------------------------------------------------------


void AnimatedSprite::update(const int startTexture, const int endTexture)
{
    /* UPDATE CURRENT TEXTURE IN CASE NEXT TEXTURE IS AVAILABLE */
    if (currentTexture == endTexture || currentTexture == ZERO)
        nextTextureRight = !nextTextureRight;

    /* SET END TEXTURE IN CASE THERE IS ONE, START TEXTURE OTHERWISE */
    if (currentTexture <= endTexture && nextTextureRight)
        animate(endTexture);
    else
        animate(startTexture);
}


//---------------------------------------------------------------------------------------------------------------------


int AnimatedSprite::getCurrentTexture() const
{
    return currentTexture;
}


//---------------------------------------------------------------------------------------------------------------------


void AnimatedSprite::animate(const int targetTexture)
{
    if (targetTexture == currentTexture) return;

    auto now = clock::now();

    std::chrono::duration<double> duration = now - lastframe;
    if (duration.count() > speed)
    {
        int x;
        if (currentTexture < targetTexture)  x = getTextureRect().left + getTextureSize();
        else                                x = getTextureRect().left - getTextureSize();

        setTextureRect(sf::IntRect(x, ZERO, width * getTextureSize(), height * getTextureSize()));

        currentTexture = x / getTextureSize();
        lastframe = clock::now();
    }
}


//---------------------------------------------------------------------------------------------------------------------
