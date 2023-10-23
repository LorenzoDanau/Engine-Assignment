#include "DebugDraw.h"

DebugDraw* DebugDraw::instance = nullptr;

DebugDraw& DebugDraw::Instance() {
    if (!instance) {
        instance = new DebugDraw();
    }
    return *instance;
}

DebugDraw::DebugDraw() {

}


void DebugDraw::Initialize(sf::RenderWindow* renderWindow) {
    window = renderWindow;
}

void DebugDraw::DrawLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, sf::Color color) {
    sf::Vertex line[] = { sf::Vertex(startPoint, color), sf::Vertex(endPoint, color) };
    window->draw(line, 2, sf::Lines);
}

void DebugDraw::DrawRectOutline(const sf::Vector2f& position, int width, int height, sf::Color color) {
    sf::Vertex lines[5]; // Five vertices to outline a rectangle (four edges and one to close the loop)

    lines[0] = sf::Vertex(position, color); // Top-left corner
    lines[1] = sf::Vertex(sf::Vector2f(position.x + width, position.y), color); // Top-right corner
    lines[2] = sf::Vertex(sf::Vector2f(position.x + width, position.y + height), color); // Bottom-right corner
    lines[3] = sf::Vertex(sf::Vector2f(position.x, position.y + height), color); // Bottom-left corner
    lines[4] = lines[0]; // Close the loop

    window->draw(lines, 5, sf::LineStrip);
}

void DebugDraw::DrawRectangle(const sf::Vector2f& position, int width, int height, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window->draw(rectangle);
}