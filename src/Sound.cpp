#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Sound.h"
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


Sound::Sound(std::string path)
{
    if (!m_Buffer.loadFromFile(path))
        throw std::runtime_error("Failed to load " + path);

    setBuffer(m_Buffer);
}


//---------------------------------------------------------------------------------------------------------------------
