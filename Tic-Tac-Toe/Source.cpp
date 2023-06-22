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

    unsigned int turns = 0;
    std::vector<Shapes::DrawShape> circlePositions;
    std::vector<unsigned int> exesPositions;
    std::vector<unsigned int> coveredPositions;

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

        //Update the frame

        shape.drawCircle(mousePos(event) % 10 - 1, mousePos(event) / 10 - 1, gridSize, window, windowWidth, windowHeight);
        shape.drawCross(mousePos(event) % 10 - 1, mousePos(event) / 10 - 1, gridSize, window, windowWidth, windowHeight);
       
        //End update
        window.display();
    }

    return 0;
}
