#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MainMenu.h"
#include "Utils.h"
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


MainMenu::MainMenu()
{
	try {
		/* LOAD FONT */
		m_Font.loadFromFile(FONTSPATH);
		m_Texture.load("menu", BACKGROUNDPATH);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	/* SET ALL SETTINGS OF THE GAME */
	setSettings();

	m_Selected = 0;

	/* LOAD AND SET BACKGROUND OF THE GAME */
	m_Sprite.setTexture(m_Texture.get("menu"));
}


//---------------------------------------------------------------------------------------------------------------------


MainMenu::~MainMenu()
{}


//---------------------------------------------------------------------------------------------------------------------


// Draw Main Menu
void MainMenu::draw(sf::RenderWindow& window, const char& mode)
{
	sf::View view;
	view.reset(sf::FloatRect(ZERO,ZERO, m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().height));
	window.setView(view);
	window.draw(m_Sprite);
	if (mode == 'f')
	{
		for (int i = ZERO; i < 3; i++)
			window.draw(m_MainMenu[i]);
		return;
	}
	else if (mode == 's')
	{
		for (int i = 4; i < 10; i++)
			window.draw(m_MainMenu[i]);

		return;
	}
	window.draw(m_MainMenu[3]);
	window.draw(m_MainMenu[2]);
}


//---------------------------------------------------------------------------------------------------------------------


void MainMenu::setButton(std::string string, const sf::Color& color, const sf::Vector2f v2, const int index)
{
	m_MainMenu[index].setFont(m_Font);
	m_MainMenu[index].setFillColor(color);
	m_MainMenu[index].setString(string);
	m_MainMenu[index].setCharacterSize(70);
	m_MainMenu[index].setPosition(v2);
}


//---------------------------------------------------------------------------------------------------------------------


bool MainMenu::click(const sf::Vector2f& pos, const int index)
{
	if (m_MainMenu[index].getGlobalBounds().contains(pos))
	{
		if (m_clicked)
			m_clicked = false;
		else
			m_clicked = true;

		return true;
	}
	return false;
}


//---------------------------------------------------------------------------------------------------------------------


sf::Text MainMenu::displaySettings(const int index)
{
	return m_MainMenu[index];
}


//---------------------------------------------------------------------------------------------------------------------


void MainMenu::setSettings()
{
	float xWidth = WINDOWWIDTH / 2 - 300;
	/* PLAY BUTTON */
	setButton(PLAY, sf::Color::Black, sf::Vector2f(xWidth + 850, (WINDOWHIEGHT + 4500) / (MAX_MAIN_MENU) * 2), ZERO);
	/* MODES BUTTON */
	setButton(BUTTONS, sf::Color::Black, sf::Vector2f(xWidth + 775, (WINDOWHIEGHT + 5100) / (MAX_MAIN_MENU) * 2), 1);
	/* EXIT BUTTON */
	setButton(EXIT, sf::Color::Black, sf::Vector2f(xWidth + 850, (WINDOWHIEGHT + 5700) / (MAX_MAIN_MENU) * 2), 2);
	/* PLAY AGAIN BUTTON */
	setButton(PLAYAGAIN, sf::Color::Black, sf::Vector2f(xWidth + 750, (WINDOWHIEGHT + 5100) / (MAX_MAIN_MENU) * 2), 3);
	/* BACK BUTTON */
	setButton(BACK, sf::Color::Black, sf::Vector2f(xWidth - 20, (WINDOWHIEGHT+150) / (MAX_MAIN_MENU) * 2), 4);
	/* MOVEMENT BUTTON */
	setButton(MOVEMENT, sf::Color::Black, sf::Vector2f(xWidth+350, (WINDOWHIEGHT + 4700) / (MAX_MAIN_MENU) * 2), 5);
	setButton(MOVE, sf::Color::Green, sf::Vector2f(xWidth + 350, (WINDOWHIEGHT + 4950) / (MAX_MAIN_MENU) * 2), 6);
	/* MUSIC BUTTON */
	setButton(PAUSE, sf::Color::Green, sf::Vector2f(xWidth + 350, (WINDOWHIEGHT + 5200) / (MAX_MAIN_MENU) * 2), 7);
	setButton(VOL, sf::Color::Black, sf::Vector2f(xWidth + 350, (WINDOWHIEGHT + 5450) / (MAX_MAIN_MENU) * 2), 8);
	setButton(VOLUME, sf::Color::Green, sf::Vector2f(xWidth + 350, (WINDOWHIEGHT + 5700) / (MAX_MAIN_MENU) * 2), 9);
}


//---------------------------------------------------------------------------------------------------------------------