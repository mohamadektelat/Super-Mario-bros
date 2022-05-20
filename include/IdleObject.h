#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class IdleObject
{
public:

    /* IDLE OBJECTS CONSTRUCTOR */
    IdleObject(const sf::Vector2f position, const std::shared_ptr<Board>& board , std::string id, std::string path);

    void draw(sf::RenderWindow& window);

    /* VIRTUAL FUNCTIONS */
    virtual std::string name() = 0;
    virtual void update()=0;
    virtual void setTaken()=0;
    virtual bool isTaken()=0;

    sf::Vector2f getPosition() const;   //Get the character's position

    AnimatedSprite& getSprite();
private:
    sf::Vector2f m_Position;
    static const int m_Height = 1;
    static const int m_Width = 1;
    Resource_Holder<sf::Texture, std::string> m_Textures;

    AnimatedSprite m_Sprite;

};