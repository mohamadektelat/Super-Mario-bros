#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MainMenu.h"


//---------------------------------------------------------------------------------------------------------------------


class Controller
{
public:
	Controller(sf::RenderWindow& window);
	void startGame(sf::RenderWindow& window);
private:
	void displaySettings(sf::RenderWindow& window);
	Game m_Game;
	void playAgain(sf::RenderWindow& window);
	std::unique_ptr<MainMenu> m_Menu;
	bool m_FirstTime = true;
	Sound m_MenuMusic;
	Sound m_ClickSound;
};