#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>


//---------------------------------------------------------------------------------------------------------------------


//Class for a sprite, inherited by sf :: Sprite
class Sprite : public sf::Sprite
{
public:

    /* DEFAULT CONSTRUCTOR */
    Sprite() = default;

    /* FLIP THE SPRITE TO OTHER DIRECTION */
    void flip();

    /* SET POSITION OF THE SPRITE */
    void setPosition(float x, float y);

    /* SET TEXTURE OF THE SPRITE */
    void setTexture(sf::Texture& texture);

    /* GET THE TEXTURE SIZE */
    static int getTextureSize();

private:
    static constexpr int textureSize = 16;

    static float convertCoords(const float c);
};