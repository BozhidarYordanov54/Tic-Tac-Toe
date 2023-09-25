#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <iostream>

const unsigned int gridSize = 150;
const unsigned int windowWidth = 450;
const unsigned int windowHeight = 450;

unsigned int mousePos(sf::Event& event)
{
    unsigned int value = 0;

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            unsigned int posX = event.mouseButton.x;
            unsigned int posY = event.mouseButton.y;

            if (posX < gridSize)
            {
                value += 10;
            }
            else if (posX < gridSize * 2)
            {
                value += 20;
            }
            else
            {
                value += 30;
            }

            if (posY < gridSize)
            {
                value += 1;
            }
            else if (posY < gridSize * 2)
            {
                value += 2;
            }
            else
            {
                value += 3;
            }
        }
    }

    std::cout << value << std::endl;
    return value;
}

bool checkWin(const std::vector<sf::Vector2i>& positions)
{
    // Possible winning combinations
    const std::vector<std::vector<sf::Vector2i>> winCombinations = {
        {{0, 0}, {0, 1}, {0, 2}}, // Horizontal rows
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 0}, {2, 0}}, // Vertical columns
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}}, // Diagonals
        {{0, 2}, {1, 1}, {2, 0}}
    };

    for (const auto& combination : winCombinations)
    {
        bool isWin = true;

        for (const auto& pos : combination)
        {
            if (std::find(positions.begin(), positions.end(), pos) == positions.end())
            {
                isWin = false;
                break;
            }
        }

        if (isWin)
        {
            return true;
        }
    }

    return false;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic-Tac-Toe");

    Shapes::DrawShape shape;
    sf::Event event;

    std::vector<sf::Vector2i> circlePositions;
    std::vector<sf::Vector2i> exesPositions;
    
    bool isGameOver = false;

    //Generating random number for determining player turn at the begging of the game
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int playerTurn = 1 + (std::rand() % 10);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        shape.drawGrid(gridSize, window);

        int row = 0;
        int col = 0;

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            unsigned int pos = mousePos(event);
            row = pos / 10 - 1;
            col = pos % 10 - 1;

            if (row >= 0 && col >= 0)
            {
                bool positionOccupied = false;

                for (const auto& position : circlePositions)
                {
                    if (position.x == row && position.y == col)
                    {
                        positionOccupied = true;
                        break;
                    }
                }

                if (!positionOccupied)
                {
                    for (const auto& position : exesPositions)
                    {
                        if (position.x == row && position.y == col)
                        {
                            positionOccupied = true;
                            break;
                        }
                    }
                }

                if (!positionOccupied)
                {
                    if (circlePositions.size() == exesPositions.size())
                    {
                        circlePositions.push_back(sf::Vector2i(row, col));
                        if (checkWin(circlePositions))
                        {
                            std::cout << "Circle wins!" << std::endl;
                            isGameOver = true; // Player has won
                        }
                    }
                    else
                    {
                        exesPositions.push_back(sf::Vector2i(row, col));
                        if (checkWin(exesPositions))
                        {
                            std::cout << "Exes Win!" << std::endl;
                            isGameOver = true; // Player has won
                        }
                    }
                }
            }
        }

        // Draw circles
        for (const auto& position : circlePositions)
        {
            shape.drawCircle(position.x, position.y, gridSize, window, windowWidth, windowHeight);
        }

        // Draw exes
       //for (const auto& position : exesPositions)
       //{
       //    shape.drawCross(position.x, position.y, gridSize, window, windowWidth, windowHeight);
       //}

        window.display();
    }

    return 0;
}
