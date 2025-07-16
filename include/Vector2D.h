#pragma once

class Vector2D {
public:
    Vector2D(float x_cord = 0.0f, float y_cord = 0.0f) {
        x = x_cord;
        y = y_cord;
    }

    float getX() const { return x; }
    float getY() const { return y; }

    Vector2D& operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D& setX(float x_cord) {
        x = x_cord;
        return *this;
    }

    Vector2D& setY(float y_cord) {
        y = y_cord;
        return *this;
    }

private:
    float x, y;
};
