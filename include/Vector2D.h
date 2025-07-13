#pragma once

class Vector2D
{
    public:
        Vector2D(int x_cord = 0, int y_cord = 0)
        {
            x = x_cord;
            y = y_cord;
        };

        int getX () const
        {
            return x;
        }
        int getY() const
        {
            return y;
        }

        Vector2D& operator+=(const Vector2D& other)
        {
            x += other.getX();
            y += other.getY();
            return *this;
        }

        Vector2D& operator-=(const Vector2D& other)
        {
            x -= other.getX();
            y -= other.getY();
            return *this;
        }

        Vector2D operator+(const Vector2D& other) const
        {
            return Vector2D(x + other.getX(), y + other.getY());
        }

        Vector2D operator-(const Vector2D& other) const
        {
            return Vector2D(x - other.getX(), y - other.getY());
        }

        Vector2D operator*(const Vector2D& other) const
        {
            return Vector2D(x * other.getX(), y * other.getY());
        }


        Vector2D& setX(int x_cord)
        {
            x = x_cord;

            return *this;
        }

        Vector2D& setY(int y_cord)
        {
            y = y_cord;

            return *this;
        }

    private:
        int x,y;
};