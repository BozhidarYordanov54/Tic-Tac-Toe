#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <iostream>

const unsigned int gridSize = 150;
const unsigned int windowWidth = 450;
const unsigned int windowHeight = 450;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic-Tac-Toe");

    Shapes::DrawShape shape;

    sf::Event event;
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

        shape.drawCircle(0, 0, gridSize, window, windowWidth, windowHeight);
        shape.drawCross(1, 1, gridSize, window, windowWidth, windowHeight);
       
        //End update
        window.display();
    }

    return 0;
}