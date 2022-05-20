#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Audio/Listener.hpp>


//---------------------------------------------------------------------------------------------------------------------


class Audio_Controller : public sf::Listener
{
public:
    Audio_Controller() = delete;

    static void toggleMute();   //Switches between whether or not to hear sound

    static bool muted();    //Returns if the sound is mutated or not

    static void increaseVolume(const float amount = 10.f);  //Increases the volume by a given amount

    static void decreaseVolume(const float amount = 10.f);  //Decreases the volume by a given amount

private:
    inline static bool m_Muted = false;
};