#include "Shapes.h"
#include <SFML/Graphics.hpp>

void Shapes::DrawShape::drawGrid(const unsigned int gridSize, sf::RenderWindow& window)
{
    sf::RectangleShape grid(sf::Vector2f(gridSize, gridSize));
    grid.setFillColor(sf::Color::Transparent);
    grid.setOutlineThickness(1.5f);
    grid.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid.setPosition(gridSize * i, gridSize * j);
            window.draw(grid);
        }
    }
}

void Shapes::DrawShape::drawCircle(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight)
{
    const float circleRadius = 60.0f;

    sf::CircleShape circle(circleRadius);
    circle.setOutlineThickness(3.0f);
    circle.setOutlineColor(sf::Color::Red);

    circle.setPosition(sf::Vector2f(((windowWidth / 2.0f) - circleRadius) + gridSize * row - 150, ((windowHeight / 2.0f) - circleRadius) + gridSize * column - 150));

    window.draw(circle);
}

void Shapes::DrawShape::drawCross(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight)
{
    float size = 150;
    float thickness = 3.0f;

    sf::RectangleShape line2(sf::Vector2f(size, thickness));
    sf::RectangleShape line1(sf::Vector2f(size, thickness));
    
    //TODO Implement color customization
    line1.setFillColor(sf::Color::Black);
    line2.setFillColor(sf::Color::Black);
    
    line1.setOrigin(size / 2.0f, thickness / 2.0f);
    line2.setOrigin(size / 2.0f, thickness / 2.0f);

    float posX = ((windowWidth / 2.0f) - size) + gridSize * row;
    float posY = ((windowWidth / 2.0f) - size) + gridSize * column;

    line1.setPosition(sf::Vector2f(posX, posY));
    line2.setPosition(sf::Vector2f(posX, posY));

    line1.rotate(-45);
    line2.rotate(45);

    window.draw(line1);
    window.draw(line2);
}