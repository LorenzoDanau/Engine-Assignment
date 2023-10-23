#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.h"
#include "InputManager.h"
#include "DebugDraw.h"
#include "AssetManager.h"

class Game {
public:
    static const int WIDTH = 640;
    static const int HEIGHT = 480;

    Game();

    void Run();

private:
    const sf::Color BG_COLOR = sf::Color(50, 50, 50);
    const sf::VideoMode mode;
    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    std::shared_ptr<Player> player;

    void CloseGame(const sf::Event& event);
    void Initialize();
    void HandleEvents();
    void Draw();
    void DrawFloor(const sf::Vector2f& position, const sf::Vector2i& tiles, const sf::Vector2i& tileSize);
    void Update(float deltaTime);
    void CheckAreaBorders();
    void RespawnPlayer();
};