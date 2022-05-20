#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Game.h"
#include "Controller.h"


//---------------------------------------------------------------------------------------------------------------------


int main()
{
    sf::RenderWindow Window(sf::VideoMode(WINDOWWIDTH, WINDOWHIEGHT), GAMETITLE, sf::Style::Fullscreen);
    Window.setFramerateLimit(60);
    Controller c(Window);
    c.startGame(Window);
    return EXIT_SUCCESS;
}


//---------------------------------------------------------------------------------------------------------------------

