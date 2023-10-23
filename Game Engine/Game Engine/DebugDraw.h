#pragma once

#include <SFML/Graphics.hpp>

class DebugDraw {
private:
    sf::RenderWindow* window;
    DebugDraw() {} // Private constructor

public:
    static DebugDraw& Instance() {
        static DebugDraw instance; // Meyers Singleton
        return instance;
    }

    void Initialize(sf::RenderWindow* renderWindow);
    void DrawLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, sf::Color color);
    void DrawRectOutline(const sf::Vector2f& position, int width, int height, sf::Color color);
    void DrawRectangle(const sf::Vector2f& position, int width, int height, sf::Color color);
};