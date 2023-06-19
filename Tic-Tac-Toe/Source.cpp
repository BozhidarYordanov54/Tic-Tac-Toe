#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <iostream>

const unsigned int gridSize = 150;
const unsigned int windowWidth = 450;
const unsigned int windowHeight = 450;

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tic-Tac-Toe");

    //Grid
    sf::RectangleShape grid(sf::Vector2f(gridSize, gridSize));
    grid.setFillColor(sf::Color::Transparent);
    grid.setOutlineThickness(1.5f);
    grid.setOutlineColor(sf::Color::Black);

    Shapes::DrawShape shape;

    sf::Font font;

    //TODO figure out why fonts aren't working

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

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid.setPosition(gridSize * i, gridSize * j);
                window.draw(grid);
            }
        }

        //Update the frame

        //shape.drawCircle(2, 2, gridSize, window, windowWidth, windowHeight);
        shape.drawCross(0, 1, gridSize, window, windowWidth, windowHeight);
       
        //End update


        window.display();
    }

    return 0;
}