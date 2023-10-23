#include "Player.h"
#include "AssetManager.h"
#include "DebugDraw.h"
#include "InputManager.h"
#include <iostream>

Player::Player() {
    AssetManager::LoadTexture("Character", "../Assets/playerSpriteSheet.png");
    animatedSprite.setTexture(AssetManager::Textures["Character"]);
}

sf::IntRect Player::GetCollisionRect() const {
    return CollisionRect;
}

sf::IntRect Player::GetPlayerCollisionRect() const {
    return PlayerCollisionRect;
}

void Player::Draw(sf::RenderWindow& window) {
    DoAnimation();

    window.draw(animatedSprite);

    sf::Vector2f rectPosition(animatedSprite.getGlobalBounds().left, animatedSprite.getGlobalBounds().top);
    int rectWidth = static_cast<int>(std::round(animatedSprite.getGlobalBounds().width));
    int rectHeight = static_cast<int>(std::round(animatedSprite.getGlobalBounds().height));

    DebugDraw::Instance().DrawRectOutline(rectPosition, rectWidth, rectHeight, sf::Color::Red);

    DebugDraw::Instance().DrawRectOutline(sf::Vector2f(CollisionRect.left, CollisionRect.top), CollisionRect.width, CollisionRect.height, sf::Color::Green);
}

void Player::Initialize() {
    animatedSprite.setScale(1.0f, 1.0f);
    animatedSprite.setPosition(0, 0);

    animatedSprite.setTextureRect(
        sf::IntRect(0, 0, animatedSprite.getTextureRect().width / TILING_X, animatedSprite.getTextureRect().height / TILING_Y));

    setOrigin(sf::Vector2f(animatedSprite.getTextureRect().width / 2.f, animatedSprite.getTextureRect().height / 2.f));

    UpdateTransform();
    UpdateCollider();
}

void Player::Update(float deltaTime) {
    UpdateTransform();
    UpdateCollider();
    HandleIdle();

    HandleInput(deltaTime);

    animationTimeIndex += deltaTime * ANIMATION_SPEED;

    PlayerCollisionRect = sf::IntRect(
        static_cast<int>(getPosition().x),
        static_cast<int>(getPosition().y),
        static_cast<int>(animatedSprite.getGlobalBounds().width),
        static_cast<int>(animatedSprite.getGlobalBounds().height));
}

void Player::UpdateTransform() {
    animatedSprite.setPosition(getPosition());
    animatedSprite.setRotation(getRotation());
    animatedSprite.setScale(getScale());
    animatedSprite.setOrigin(getOrigin());
}

void Player::UpdateCollider() {
    CollisionRect = sf::IntRect(
        static_cast<int>(getPosition().x - colliderSize.x / 2),
        static_cast<int>(getPosition().y - colliderSize.y / 2),
        colliderSize.x,
        colliderSize.y);
}

void Player::HandleInput(float deltaTime) {
    // Get input
    if (InputManager::Instance().GetKeyPressed(sf::Keyboard::W)) {
        m_animationType = AnimationType::RunUp;
        move(sf::Vector2f(0, -1) * MoveSpeed * deltaTime);
    }

    if (InputManager::Instance().GetKeyPressed(sf::Keyboard::A)) {
        m_animationType = AnimationType::RunLeft;
        move(sf::Vector2f(-1, 0) * MoveSpeed * deltaTime);
    }

    if (InputManager::Instance().GetKeyPressed(sf::Keyboard::S)) {
        m_animationType = AnimationType::RunDown;
        move(sf::Vector2f(0, 1) * MoveSpeed * deltaTime);
    }

    if (InputManager::Instance().GetKeyPressed(sf::Keyboard::D)) {
        m_animationType = AnimationType::RunRight;
        move(sf::Vector2f(1, 0) * MoveSpeed * deltaTime);
    }
}

void Player::HandleIdle() {
    if (m_animationType == AnimationType::RunUp)
        m_animationType = AnimationType::IdleUp;
    if (m_animationType == AnimationType::RunDown)
        m_animationType = AnimationType::IdleDown;
    if (m_animationType == AnimationType::RunLeft)
        m_animationType = AnimationType::IdleLeft;
    if (m_animationType == AnimationType::RunRight)
        m_animationType = AnimationType::IdleRight;
}

void Player::DoAnimation() {
    int animationFrame = static_cast<int>(animationTimeIndex) % animationTypeFramesCount[static_cast<int>(m_animationType)];

    animatedSprite.setTextureRect(sf::IntRect(
        animationFrame * animatedSprite.getTextureRect().width,
        static_cast<int>(m_animationType) * animatedSprite.getTextureRect().height,
        animatedSprite.getTextureRect().width,
        animatedSprite.getTextureRect().height));
}