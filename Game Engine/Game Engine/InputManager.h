#pragma once

#include <SFML/Window.hpp>
#include <map>

class InputManager {
private:
    std::map<sf::Keyboard::Key, bool> isKeyDown;
    std::map<sf::Keyboard::Key, bool> isKeyPressed;
    std::map<sf::Keyboard::Key, bool> isKeyUp;

    InputManager(); // Private constructor

    // Static pointer to the instance
    static InputManager* instance;

public:
    // Static method to access the instance
    static InputManager& Instance();

    // Delete copy constructor and assignment operator
    InputManager(const InputManager&) = delete;
    void operator=(const InputManager&) = delete;

    void Init(sf::Window& window);
    void Update();
    bool GetKeyPressed(sf::Keyboard::Key key);
    bool GetKeyDown(sf::Keyboard::Key key);
    bool GetKeyUp(sf::Keyboard::Key key);
    void OnKeyPressed(sf::Keyboard::Key key);
    void OnKeyReleased(sf::Keyboard::Key key);
};