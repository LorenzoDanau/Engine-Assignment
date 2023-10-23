#pragma once

#include <SFML/Graphics.hpp>

class DebugDraw {
private:
    sf::RenderWindow* window;

    // Private constructor
    DebugDraw();

    // Static pointer to the instance
    static DebugDraw* instance;

public:
    // Static method to access the instance
    static DebugDraw& Instance();

    void Initialize(sf::RenderWindow* renderWindow);
    void DrawLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, sf::Color color);
    void DrawRectOutline(const sf::Vector2f& position, int width, int height, sf::Color color);
    void DrawRectangle(const sf::Vector2f& position, int width, int height, sf::Color color);
};