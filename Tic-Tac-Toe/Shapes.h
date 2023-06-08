#include <SFML/Graphics.hpp>
#pragma once

namespace Shapes
{
    class DrawShape
    {
    public:
        sf::CircleShape drawCircle(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight);
        sf::RectangleShape drawCross(int row, int column, const unsigned int gridSize, const sf::Font& font);
        void drawGrid();
    };
}
