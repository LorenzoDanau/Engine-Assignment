#include "Game.h"
#include <iostream>
#include <fstream>

Game::Game()
    : mode(WIDTH, HEIGHT), window(mode, "Game") {
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    window.setKeyRepeatEnabled(false);

    // Event handling
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorVisible(false);

    window.setMouseCursorVisible(false);

    window.setFramerateLimit(60);

    window.setFramerateLimit(60);


    // Initialize game
    Initialize();
}

void Game::CloseGame(const sf::Event& event) {
    if (event.key.code == sf::Keyboard::Escape) {
        window.close();
    }
}

void Game::Initialize() {
    InputManager::Instance().Init(window);
    DebugDraw::Instance().Initialize(&window);

    gameObjects.clear();

    player = std::make_shared<Player>();
    player->setPosition(WIDTH / 2, HEIGHT / 2);
    gameObjects.push_back(player);

    AssetManager::LoadSoundBuffer("CompleteSound", "../Assets/completeSound.wav");
    AssetManager::LoadMusic("MusicTrack", "../Assets/musicTrack.ogg");

    AssetManager::Musics["MusicTrack"]->play();

    for (const auto& gameObject : gameObjects) {
        gameObject->Initialize();
    }
}

void Game::Run() {
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        HandleEvents();
        Update(dt);
        Draw();
    }
}

void Game::HandleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            break;
        default:
            break;
        }
    }
}

void Game::Draw() {
    window.clear(BG_COLOR);

    DrawFloor(sf::Vector2f(0, 0), sf::Vector2i(10, 10), sf::Vector2i(64, 64));

    for (const auto& gameObject : gameObjects) {
        gameObject->Draw(window);
    }

    window.display();
}

void Game::DrawFloor(const sf::Vector2f& position, const sf::Vector2i& tiles, const sf::Vector2i& tileSize) {
    for (int x = 0; x < tiles.x; x++) {
        for (int y = 0; y < tiles.y; y++) {
            sf::Vector2f tilepos(position.x + x * tileSize.x, position.y + y * tileSize.y);
            DebugDraw::Instance().DrawRectangle(tilepos, tileSize.x, tileSize.y, (x + y) % 2 == 0 ? sf::Color::White : sf::Color::Black);
        }
    }
}

void Game::Update(float deltaTime) {
    for (const auto& gameObject : gameObjects) {
        gameObject->Update(deltaTime);
    }

    CheckAreaBorders();

    InputManager::Instance().Update();
}

void Game::CheckAreaBorders() {
    int left = 0;
    int top = 0;
    int right = WIDTH;
    int bottom = HEIGHT;

    if (player->getPosition().y > bottom - player->GetCollisionRect().height / 2) {
        player->setPosition(player->getPosition().x, bottom - player->GetCollisionRect().height / 2);
    }

    if (player->getPosition().y < top + player->GetCollisionRect().height / 2) {
        player->setPosition(player->getPosition().x, top + player->GetCollisionRect().height / 2);
    }

    if (player->getPosition().x > right - player->GetCollisionRect().width / 2) {
        player->setPosition(right - player->GetCollisionRect().width / 2, player->getPosition().y);
    }

    if (player->getPosition().x < left + player->GetCollisionRect().width / 2) {
        player->setPosition(left + player->GetCollisionRect().width / 2, player->getPosition().y);
    }
}

void Game::RespawnPlayer() {
    player->setPosition(WIDTH / 2, HEIGHT / 2);
}

bool HasReadAccess(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.is_open();
}

int main() {
    Game game;
    game.Run();
    return 0;
}