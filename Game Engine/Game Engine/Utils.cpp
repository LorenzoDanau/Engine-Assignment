#include <SFML/System.hpp>
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
// Returns the squared magnitude of a vector (length before square root)
float SqrMagnitude(const sf::Vector2f& input) {
    float sqrLength = input.x * input.x + input.y * input.y;
    return sqrLength;
}

// Rotates a vector by a given angle counterclockwise (angle in radians)
sf::Vector2f RotateVector(const sf::Vector2f& v, float angle) {
    return sf::Vector2f(
        v.x * cos(angle) - v.y * sin(angle),
        v.x * sin(angle) + v.y * cos(angle)
    );
}

// Returns the angle between two vectors (angle in radians)
float AngleBetween(const sf::Vector2f& v1, const sf::Vector2f& v2) {
    return atan2(v2.y - v1.y, v2.x - v1.x);
}

// Convert from radians to degrees
float ToDegrees(float val) {
    return 180.0f / M_PI * val;
}

// Convert from degrees to radians
float ToRadians(float val) {
    return M_PI / 180.0f * val;
}

// Distance between two points
float Distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Normalize a vector to a length of 1
sf::Vector2f Normalize(const sf::Vector2f& source) {
    float length = sqrt(source.x * source.x + source.y * source.y);

    if (length != 0) {
        return sf::Vector2f(source.x / length, source.y / length);
    }

    return source;
}

// Linear interpolation between two floats
float Lerp(float firstFloat, float secondFloat, float t, bool clamped = true) {
    if (clamped) {
        t = t > 1.0f ? 1.0f : t;
    }

    return firstFloat * (1 - t) + secondFloat * t;
}

// Linear interpolation between two vectors
sf::Vector2f Lerp(const sf::Vector2f& firstVector, const sf::Vector2f& secondVector, float t) {
    float x = Lerp(firstVector.x, secondVector.x, t);
    float y = Lerp(firstVector.y, secondVector.y, t);
    return sf::Vector2f(x, y);
}

// Returns the Dot-Product of two vectors
float Dot(const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
    float dotProduct = lhs.x * rhs.x + lhs.y * rhs.y;
    return dotProduct;
}