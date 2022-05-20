#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include <ResourceHolder.h>
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class MainMenu
{

public:

	/* CONSTRUCT A MAIN MENU WITH GIVING BORDERS */
	MainMenu();

	void draw(sf::RenderWindow& window, const char& mode);

	/* CHECK IF A BUTTON IS PRESSED */
	int mainMenuPressed()
	{
		return m_Selected;
	}

	~MainMenu();

	/* SET BUTTONS OF THE SCREEN */
	void setButton(std::string string, const sf::Color& color, const sf::Vector2f v2, const int index);

	/* CHECK IF CLICKED ON GIVIN POSITION */
	bool click(const sf::Vector2f& pos, const int index); //checks if clicked on the button

	sf::Text displaySettings(const int index);

	void setSettings();


private:
	int m_Selected;
	sf::Font m_Font;
	sf::Text m_MainMenu[MAX_MAIN_MENU];
	Resource_Holder<sf::Texture,std::string> m_Texture;
	sf::Sprite m_Sprite;
	bool m_clicked = false; //is button clicked (for border)
};