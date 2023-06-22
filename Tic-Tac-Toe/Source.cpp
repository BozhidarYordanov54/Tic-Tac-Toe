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

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic-Tac-Toe");

    Shapes::DrawShape shape;
    sf::Event event;

    std::vector<sf::Vector2i> circlePositions;
    std::vector<sf::Vector2i> exesPositions;

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

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            unsigned int pos = mousePos(event);
            int row = pos % 10 - 1;
            int column = pos / 10 - 1;

            if (row >= 0 && column >= 0)
            {
                bool positionOccupied = false;

                for (const auto& position : circlePositions)
                {
                    if (position.x == row && position.y == column)
                    {
                        positionOccupied = true;
                        break;
                    }
                }

                if (!positionOccupied)
                {
                    for (const auto& position : exesPositions)
                    {
                        if (position.x == row && position.y == column)
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
                        circlePositions.push_back(sf::Vector2i(row, column));
                    }
                    else
                    {
                        exesPositions.push_back(sf::Vector2i(row, column));
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
        for (const auto& position : exesPositions)
        {
            shape.drawCross(position.x, position.y, gridSize, window, windowWidth, windowHeight);
        }

        window.display();
    }

    return 0;
}
