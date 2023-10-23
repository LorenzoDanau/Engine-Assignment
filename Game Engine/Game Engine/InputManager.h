#pragma once

#include <SFML/Window.hpp>
#include <map>

class InputManager {
private:
    static InputManager* instance;
    std::map<sf::Keyboard::Key, bool> isKeyDown;
    std::map<sf::Keyboard::Key, bool> isKeyPressed;
    std::map<sf::Keyboard::Key, bool> isKeyUp;

public:
    static InputManager& Instance();
    void Init(sf::Window& window);
    void Update();
    bool GetKeyPressed(sf::Keyboard::Key key);
    bool GetKeyDown(sf::Keyboard::Key key);
    bool GetKeyUp(sf::Keyboard::Key key);
    void OnKeyPressed(sf::Keyboard::Key key);
    void OnKeyReleased(sf::Keyboard::Key key);
};