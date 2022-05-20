#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Sprite.h"
#include <chrono>
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class AnimatedSprite : public Sprite
{
public:

    /* ANIMATED SPRITE CONSTRUCTOR WITH GIVING PARAMETERS: (WIDTH, HEIGHT, SPEED) */
    AnimatedSprite(const int width, const int height, const double speed = 0.1);    

    /* UPDATE ANIMATION TEXTURE */
    void update(const int startTexture, const int endTexture);      

    /* SET A TEXTURE WITHOUT ANIMATING IT */
    void set(const int texture);    

    int getCurrentTexture() const;  

private:

    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;

    bool nextTextureRight = true;

    const double speed;

    const int width, height;

    int currentTexture = ZERO;

    void animate(const int targetFrame);
};