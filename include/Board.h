#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Block.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


//Creates a world. The world holds all the blocks in the environment
class Board
{
public:

    /* Constructor: initialize board with initial gravity */
    Board();

    //Loads a path from a given file, see Levels.txt for format
    void loadMaps();

    std::unordered_multimap<char, sf::Vector2f> getObject();

    /* draw the board on the giving window */
    void draw(sf::RenderWindow& window);

    //The world's left border
    int leftBoundary() const;

    //The world's right border
    int rightBoundary() const;

    //The upper limit of the world
    int topBoundary() const;

    //The lower limit of the world
    int bottomBoundary() const;

    //Checks whether a block at a given coordinate can be traversed or not
    bool isSolidBlock(const int x, const int y) const;

    //Check if Mario has reached the goal, submit his x value
    bool reachedFinish(const int x) const;

    void setLevel();

    bool gameWon();

    void reset();

private:
    /* array of maps */
    std::vector<std::vector<std::vector<std::unique_ptr<Block>>>> m_Maps;

    std::vector<std::unordered_multimap<char, sf::Vector2f>> m_Objects;
    std::unordered_map<int,int> m_FinishLines;
    std::ifstream m_File;
    int m_X , m_Y ;
    int m_Level = ZERO;
    const int m_Levels =NUMOFLEVELS;
};