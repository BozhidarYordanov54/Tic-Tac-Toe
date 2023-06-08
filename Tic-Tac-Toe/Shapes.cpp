#include "Shapes.h"
#include <SFML/Graphics.hpp>

sf::CircleShape Shapes::DrawShape::drawCircle(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight)
{
    const float circleRadius = 60.0f;

    sf::CircleShape circle(circleRadius);
    circle.setOutlineThickness(2.5f);
    circle.setOutlineColor(sf::Color::Red);

    circle.setPosition(sf::Vector2f(((windowWidth / 2.0f) - circleRadius) + gridSize * column - 150, ((windowHeight / 2.0f) - circleRadius) + gridSize * row - 150));

    return circle;
}

sf::RectangleShape Shapes::DrawShape::drawCross(int row, int column, const unsigned int gridSize, const sf::Font& font)
{
    float size = 150;
    float thickness = 2.5f;

    sf::RectangleShape line1(sf::Vector2f(size, thickness));

    sf::RectangleShape line2(sf::Vector2f(size, thickness));

    return line1;
}