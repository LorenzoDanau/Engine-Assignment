#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager& InputManager::Instance() {
    if (!instance)
        instance = new InputManager();
    return *instance;
}

void InputManager::Init(sf::Window& window) {
    window.setKeyRepeatEnabled(false);

    // Initialize your key states here
    isKeyDown[sf::Keyboard::W] = false;
    isKeyDown[sf::Keyboard::A] = false;
    isKeyDown[sf::Keyboard::S] = false;
    isKeyDown[sf::Keyboard::D] = false;
    isKeyDown[sf::Keyboard::Space] = false;
    isKeyDown[sf::Keyboard::Num1] = false;
    isKeyDown[sf::Keyboard::Num2] = false;

    isKeyUp[sf::Keyboard::W] = false;
    isKeyUp[sf::Keyboard::A] = false;
    isKeyUp[sf::Keyboard::S] = false;
    isKeyUp[sf::Keyboard::D] = false;
    isKeyUp[sf::Keyboard::Space] = false;
    isKeyUp[sf::Keyboard::Num1] = false;
    isKeyUp[sf::Keyboard::Num2] = false;

    isKeyPressed[sf::Keyboard::W] = false;
    isKeyPressed[sf::Keyboard::A] = false;
    isKeyPressed[sf::Keyboard::S] = false;
    isKeyPressed[sf::Keyboard::D] = false;
    isKeyPressed[sf::Keyboard::Space] = false;
    isKeyPressed[sf::Keyboard::Num1] = false;
    isKeyPressed[sf::Keyboard::Num2] = false;
}

void InputManager::Update() {
    for (auto& kvp : isKeyDown)
        kvp.second = false;

    for (auto& kvp : isKeyUp)
        kvp.second = false;
}

bool InputManager::GetKeyPressed(sf::Keyboard::Key key) {
    return isKeyPressed.find(key) != isKeyPressed.end() ? isKeyPressed[key] : false;
}

bool InputManager::GetKeyDown(sf::Keyboard::Key key) {
    return isKeyDown.find(key) != isKeyDown.end() ? isKeyDown[key] : false;
}

bool InputManager::GetKeyUp(sf::Keyboard::Key key) {
    return isKeyUp.find(key) != isKeyUp.end() ? isKeyUp[key] : false;
}

void InputManager::OnKeyPressed(sf::Keyboard::Key key) {
    if (isKeyPressed.find(key) != isKeyPressed.end()) {
        isKeyDown[key] = true;
        isKeyPressed[key] = true;
    }
}

void InputManager::OnKeyReleased(sf::Keyboard::Key key) {
    if (isKeyPressed.find(key) != isKeyPressed.end()) {
        isKeyUp[key] = true;
        isKeyPressed[key] = false;
    }
}