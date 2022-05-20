#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AudioController.h"


//---------------------------------------------------------------------------------------------------------------------


void Audio_Controller::toggleMute()
{
    static float prevVolume;

    if (!m_Muted)
    {
        prevVolume = getGlobalVolume();
        setGlobalVolume(.01); //Does not work to set directly to 0 for some reason, set very low so it is quiet anyway
    }
    else setGlobalVolume(prevVolume);
    m_Muted = !m_Muted;
}


//---------------------------------------------------------------------------------------------------------------------


bool Audio_Controller::muted()
{
    return m_Muted;
}


//---------------------------------------------------------------------------------------------------------------------


void Audio_Controller::increaseVolume(const float amount)
{
    setGlobalVolume(getGlobalVolume() + amount);
}


//---------------------------------------------------------------------------------------------------------------------


void Audio_Controller::decreaseVolume(const float amount)
{
    setGlobalVolume(getGlobalVolume() - amount);
}


//---------------------------------------------------------------------------------------------------------------------
