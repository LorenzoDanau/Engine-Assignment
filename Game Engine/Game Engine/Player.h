#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "DebugDraw.h"
#include "InputManager.h"
#include "GameObject.h"

enum class AnimationType {
    IdleDown,
    IdleLeft,
    IdleUp,
    IdleRight,
    RunDown,
    RunLeft,
    RunUp,
    RunRight
};

class Player : public GameObject {
public:
    Player();

    sf::IntRect GetCollisionRect() const;
    sf::IntRect GetPlayerCollisionRect() const;

    void Draw(sf::RenderWindow& window) override;
    void Initialize() override;
    void Update(float deltaTime) override;

private:
    void UpdateTransform();
    void UpdateCollider();
    void HandleInput(float deltaTime);
    void HandleIdle();
    void DoAnimation();

private:
    static constexpr float ANIMATION_SPEED = 8.0f;
    static constexpr int TILING_X = 10;
    static constexpr int TILING_Y = 8;

    sf::Sprite animatedSprite;
    int animationTypeFramesCount[8] = { 3, 3, 1, 3, 10, 10, 10, 10 };
    float animationTimeIndex;
    sf::Vector2i colliderSize = { 50, 60 };
    AnimationType m_animationType = AnimationType::IdleDown;
    static constexpr float MoveSpeed = 150.0f;
    sf::IntRect CollisionRect;
    sf::IntRect PlayerCollisionRect;
};
