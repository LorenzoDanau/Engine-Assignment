#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Utils {
    // Returns the squared magnitude of a vector (length before square root)
    float SqrMagnitude(const sf::Vector2f& input);

    // Rotates a vector by a given angle counterclockwise
    sf::Vector2f RotateVector(const sf::Vector2f& v, float angle);

    // Returns the angle between two vectors.
    float AngleBetween(const sf::Vector2f& v1, const sf::Vector2f& v2);

    // Convert from radians to degrees
    float ToDegrees(float radians);

    // Convert from degrees to radians
    float ToRadians(float degrees);

    // Distance between two points
    float Distance(const sf::Vector2f& a, const sf::Vector2f& b);

    // Normalizes a vector to a length of 1
    sf::Vector2f Normalize(const sf::Vector2f& source);

    // Linear interpolation between two floats
    float Lerp(float firstFloat, float secondFloat, float t, bool clamped = true);

    // Linear interpolation between two vectors
    sf::Vector2f Lerp(const sf::Vector2f& firstVector, const sf::Vector2f& secondVector, float t);

    // Returns the Dot-Product of two vectors
    float Dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs);
}