#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Game.h"
#include "Controller.h"


//---------------------------------------------------------------------------------------------------------------------



Controller::Controller(sf::RenderWindow& window) :
    m_Game(window),
    m_Menu(std::make_unique<MainMenu>()),
    m_MenuMusic(MENUSOUNDPATH),
    m_ClickSound(CLICKSOUNDPATH)
{
    m_ClickSound.setVolume(70);
}


//---------------------------------------------------------------------------------------------------------------------



void Controller::startGame(sf::RenderWindow& window)
{
    m_MenuMusic.play();
    sf::Event event;
    while (window.isOpen())
    {
        /* IN CASE NOT FIRST TIME TO PLAY (PLAY AGAIN CLICKED) */
        if (!m_FirstTime)
        {
            playAgain(window);
        }

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
                
                /* CHECK WHERE MOUSE CLICKED*/
            case sf::Event::MouseButtonReleased:
            {
                if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), 2))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    window.close();
                }
                else if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), ZERO))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    m_FirstTime = false;
                    m_MenuMusic.pause();
                    m_Game.run(window);
                    m_MenuMusic.play();
                }
                else if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), 1))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    displaySettings(window);
                }
            }
            default:
                break;
            }
        }
        window.clear();
        m_Menu->draw(window, 'f');
        window.display();
    }
}


//---------------------------------------------------------------------------------------------------------------------



void Controller::displaySettings(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {  
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), 4))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    return;
                }
                break;
            default:
                break;
            }

        }
        window.clear();
        m_Menu->draw(window, 's');
        window.display();
    }
}


//---------------------------------------------------------------------------------------------------------------------



void Controller::playAgain(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.isOpen())
    {
        m_Game.reset();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), 3))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    m_MenuMusic.pause();
                    m_Game.run(window);
                    m_MenuMusic.play();
                }
                else if (m_Menu->click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), 2))
                {
                    m_ClickSound.play();
                    sf::sleep(sf::milliseconds(250));
                    window.close();
                }
                break;
            default:
                break;
            }

        }
        window.clear();
        m_Menu->draw(window, 'a');
        window.display();
    }
}


//---------------------------------------------------------------------------------------------------------------------
