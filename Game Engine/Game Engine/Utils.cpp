// Utils.cpp
#include "Utils.h"
#include <algorithm>

float Utils::SqrMagnitude(const sf::Vector2f& input) {
    return input.x * input.x + input.y * input.y;
}

sf::Vector2f Utils::RotateVector(const sf::Vector2f& v, float angle) {
    float cosVal = std::cos(angle);
    float sinVal = std::sin(angle);

    return sf::Vector2f(
        v.x * cosVal - v.y * sinVal,
        v.x * sinVal + v.y * cosVal
    );
}

float Utils::AngleBetween(const sf::Vector2f& v1, const sf::Vector2f& v2) {
    return std::atan2(v2.y - v1.y, v2.x - v1.x);
}

float Utils::ToDegrees(float radians) {
    return 180.0f / 3.14159265f * radians;
}

float Utils::ToRadians(float degrees) {
    return 3.14159265f / 180.0f * degrees;
}

float Utils::Distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    float xDiff = a.x - b.x;
    float yDiff = a.y - b.y;
    return std::sqrt(xDiff * xDiff + yDiff * yDiff);
}

sf::Vector2f Utils::Normalize(const sf::Vector2f& source) {
    float length = std::sqrt(source.x * source.x + source.y * source.y);

    if (length != 0) {
        return sf::Vector2f(source.x / length, source.y / length);
    }

    return source;
}

float Utils::Lerp(float firstFloat, float secondFloat, float t, bool clamped) {
    if (clamped) {
        t = std::min(1.0f, t);
    }

    return firstFloat * (1 - t) + secondFloat * t;
}

sf::Vector2f Utils::Lerp(const sf::Vector2f& firstVector, const sf::Vector2f& secondVector, float t) {
    float x = Lerp(firstVector.x, secondVector.x, t);
    float y = Lerp(firstVector.y, secondVector.y, t);
    return sf::Vector2f(x, y);
}

float Utils::Dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}