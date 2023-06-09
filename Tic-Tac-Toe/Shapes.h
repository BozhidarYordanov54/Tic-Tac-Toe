#include <SFML/Graphics.hpp>
#pragma once

namespace Shapes
{
    class DrawShape
    {
    public:
        void drawGrid(const unsigned int gridSize, sf::RenderWindow& window);
        void drawCircle(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight);
        void drawCross(int row, int column, const unsigned int gridSize, sf::RenderWindow& window, int windowWidth, int windowHeight);
    };
}
