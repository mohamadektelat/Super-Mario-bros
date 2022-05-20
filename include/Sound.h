#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Audio.hpp>
#include <string>


//---------------------------------------------------------------------------------------------------------------------


class Sound : public sf::Sound
{
public:
    Sound(std::string path);

private:
    sf::SoundBuffer m_Buffer;
};